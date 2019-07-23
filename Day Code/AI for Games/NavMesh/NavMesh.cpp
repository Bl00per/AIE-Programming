#include "NavMesh.h"

#include "poly2tri/poly2tri.h"

NavMesh::NavMesh(float width, float height) {

	m_polygons.push_back({});
	m_polygons[0].push_back(new p2t::Point(0, 0));
	m_polygons[0].push_back(new p2t::Point(0, height));
	m_polygons[0].push_back(new p2t::Point(width, height));
	m_polygons[0].push_back(new p2t::Point(width, 0));

	m_cdt = new p2t::CDT(m_polygons[0]);
}

NavMesh::~NavMesh() {
	for (auto node : m_nodes)
		delete node;
}

NavMesh::Node* NavMesh::getRandomNode() const {
	if (m_nodes.empty())
		return nullptr;

	return m_nodes[rand() % m_nodes.size()];
}

NavMesh::Node* NavMesh::findClosest(float x, float y) const {

	NavMesh::Node* closest = nullptr;
	float closestDist = 2000 * 2000;

	for (auto node : m_nodes) {

		float dist = (node->position.x - x) * (node->position.x - x) + (node->position.y - y) * (node->position.y - y);

		if (dist < closestDist) {
			closest = node;
			closestDist = dist;
		}
	}

	return closest;
}

bool NavMesh::addObstacle(float x, float y, float width, float height, float padding) {

	for (auto& ob : m_obstacles) {
		if (((ob.x + ob.w + ob.padding) < x - padding ||
			 (ob.y + ob.h + ob.padding) < y - padding ||
			 (x + width + padding) < ob.x - ob.padding ||
			 (y + height + padding) < ob.y - ob.padding) == false)
			return false;
	}

	Obstacle o = { x, y, width, height, padding };
	m_obstacles.push_back(o);

	m_polygons.push_back({});
	m_polygons.back().push_back(new p2t::Point(o.x - padding, o.y - padding));
	m_polygons.back().push_back(new p2t::Point(o.x - padding, o.y + o.h + padding));
	m_polygons.back().push_back(new p2t::Point(o.x + o.w + padding, o.y + o.h + padding));
	m_polygons.back().push_back(new p2t::Point(o.x + o.w + padding, o.y - padding));
	m_cdt->AddHole(m_polygons.back());

	return true;
}

void NavMesh::build() {

	m_cdt->Triangulate();

	// first convert triangles to NavMesh::Node's
	std::vector<p2t::Triangle*> triangles = m_cdt->GetTriangles();
	for (auto tri : triangles)
	{
		NavMesh::Node* n = new NavMesh::Node();

		// Get the points of the triangle (3 total)
		n->vertices.push_back({ (float)tri->GetPoint(0)->x,
								(float)tri->GetPoint(0)->y });
		n->vertices.push_back({ (float)tri->GetPoint(1)->x,
								(float)tri->GetPoint(1)->y });
		n->vertices.push_back({ (float)tri->GetPoint(2)->x,
								(float)tri->GetPoint(2)->y });

		// Get the average position by adding up and dividing by the amount of points (3)
		n->position.x = (n->vertices[0].x + n->vertices[1].x + n->vertices[2].x) / 3;
		n->position.y = (n->vertices[0].y + n->vertices[1].y + n->vertices[2].y) / 3;

		m_nodes.push_back(n);
	}

	// then link nodes that share triangle edges
	for (auto node : m_nodes)
	{
		for (auto node2 : m_nodes)
		{
			// Ignore same node
			if (node == node2)
				continue;

			// Share verts
			int sharedVerts = 0;
			for (auto& v : node->vertices)
			{
				for (auto& v2 : node2->vertices)
				{
					if (v.x == v2.x && v.y == v2.y)
						sharedVerts++;
				}
			}

			// Link if two verts shared (should only ever be 0, 1 or 2)
			if (sharedVerts == 2)
			{
				float mag = (node2->position.x - node->position.x) *
							(node2->position.x - node->position.x) +
							(node2->position.y - node->position.y) *
							(node2->position.y - node->position.y);

				// add links to both nodes 
				node->edges.push_back(Pathfinding::Edge(node2, mag)); 
				node2->edges.push_back(Pathfinding::Edge(node, mag));
			}
		}
	}

	// cleanup polygons
	for (auto& p : m_polygons)
		for (auto ptr : p)
			delete ptr;
	m_polygons.clear();

	// close up Poly2Tri
	delete m_cdt;
	m_cdt = nullptr;
}

bool NavMesh::FollowPathBehaviour::execute(GameObject* gameObject, float deltaTime) {

	if (gameObject->smoothPath.empty())
		return false;
		
	// access first node we're heading towards
	Vector2 first = gameObject->smoothPath.front();

	// distance to first
	float xDiff = first.x - gameObject->position.x;
	float yDiff = first.y - gameObject->position.y;

	float distance = xDiff * xDiff + yDiff * yDiff;

	// if not at the target then move towards it
	if (distance > 25) {

		distance = sqrt(distance);
		xDiff /= distance;
		yDiff /= distance;

		// move to target (can overshoot!)
		gameObject->position.x += xDiff * gameObject->speed * deltaTime;
		gameObject->position.y += yDiff * gameObject->speed * deltaTime;
	}
	else {
		// at the node, remove it and move to the next
		gameObject->smoothPath.pop_front();
	}
	return true;
}

bool NavMesh::NewPathBehaviour::execute(GameObject* gameObject, float deltaTime) {

	// random end node
	bool found = false;
	do {

		auto first = m_navMesh->findClosest(gameObject->position.x, gameObject->position.y);
		auto end = m_navMesh->getRandomNode();

#pragma message("TODO: USe your own A* method here!")
//		found = aStar(first, end, gameObject->path, NavMesh::Node::heuristic);

	} while (found == false);

	NavMesh::smoothPath(gameObject->path, m_smoothPath);

	return true;
}

// funneling algorithm taken from
// http://digestingduck.blogspot.com.au/2010/03/simple-stupid-funnel-algorithm.html
int NavMesh::stringPull(const Vector2* portals, int portalCount,
						Vector2* points, const int maxPoints) {

	// Find straight path
	int npts = 0;

	// Init scan state
	Vector2 portalApex, portalLeft, portalRight;
	int apexIndex = 0, leftIndex = 0, rightIndex = 0;
	portalApex = portals[0];
	portalLeft = portals[0];
	portalRight = portals[1];

	// Add start point
	points[npts] = portalApex;
	npts++;

	for (int i = 1; i < portalCount && npts < maxPoints; ++i) {
		Vector2 left = portals[i * 2 + 0];
		Vector2 right = portals[i * 2 + 1];

		// Update right vertex
		if (triarea2(portalApex, portalRight, right) <= 0.0f) {
			if (vequal(portalApex, portalRight) || triarea2(portalApex, portalLeft, right) > 0.0f) {

				// Tighten the funnel
				portalRight = right;
				rightIndex = i;
			}
			else {
				// Right over left, insert left to path and restart scan from portal left point
				points[npts] = portalLeft;
				npts++;

				// Make current left the new apex
				portalApex = portalLeft;
				apexIndex = leftIndex;

				// Reset portal
				portalLeft = portalApex;
				portalRight = portalApex;
				leftIndex = apexIndex;
				rightIndex = apexIndex;

				// Restart scan
				i = apexIndex;
				continue;
			}
		}

		// Update left vertex
		if (triarea2(portalApex, portalLeft, left) >= 0.0f) {
			if (vequal(portalApex, portalLeft) || triarea2(portalApex, portalRight, left) < 0.0f) {

				// Tighten the funnel
				portalLeft = left;
				leftIndex = i;
			}
			else {
				// Left over right, insert right to path and restart scan from portal right point
				points[npts] = portalRight;
				npts++;

				// Make current right the new apex
				portalApex = portalRight;
				apexIndex = rightIndex;

				// Reset portal
				portalLeft = portalApex;
				portalRight = portalApex;
				leftIndex = apexIndex;
				rightIndex = apexIndex;

				// Restart scan
				i = apexIndex;
				continue;
			}
		}
	}

	// Append last point to path
	if (npts < maxPoints) {
		points[npts] = portals[(portalCount - 1) * 2 + 0];
		npts++;
	}

	return npts;
}

int NavMesh::smoothPath(const std::list<Pathfinding::Node*>& path, std::list<Vector2>& smoothPath) {

	if (path.size() == 0)
		return 0;

	smoothPath.clear();

	// Build portal list
	int index = 0;
	Vector2* portals = new Vector2[(path.size() + 1) * 2];

	// Add start node as first portal
	portals[index++] = ((NavMesh::Node*)path.front())->position;
	portals[index++] = ((NavMesh::Node*)path.front())->position;

	NavMesh::Node* prev = nullptr;

	for (auto it = path.begin(); it != path.end(); it++)
	{
		if (it != path.begin())
		{
			NavMesh::Node* node = (NavMesh::Node*)*it;

			// Find vertices they share to make a portal from
			Vector2 adjacent[2];
			prev->getAdjacentVertices(node, adjacent);

			// Get a vector going from previous node to this one
			float mag = (node->position.x - prev->position.x) *
						(node->position.x - prev->position.x) +
						(node->position.y - prev->position.y) *
						(node->position.y - prev->position.y);

			Vector2 fromPrev = {};
			if (mag > 0)
			{
				mag = sqrt(mag);
				fromPrev.x = (node->position.x - prev->position.x) / mag;
				fromPrev.y = (node->position.y - prev->position.y) / mag;
			}

			// Now get a vector going to the first adjacent vertex on the edge
			mag = (adjacent[0].x - prev->position.x) *
					(adjacent[0].x - prev->position.x) +
					(adjacent[0].y - prev->position.y) *
					(adjacent[0].y - prev->position.y);

			Vector2 toAdj0 = {};
			if (mag > 0)
			{
				mag = sqrt(mag);
				toAdj0.x = (adjacent[0].x - prev->position.x) / mag;
				toAdj0.y = (adjacent[0].y - prev->position.y) / mag;
			}

			if ((fromPrev.x * toAdj0.y - toAdj0.x * fromPrev.y) > 0)
			{
				portals[index++] = adjacent[0];
				portals[index++] = adjacent[1];
			}
			else
			{
				portals[index++] = adjacent[1];
				portals[index++] = adjacent[0];
			}

			prev = (NavMesh::Node*)*it;
		}
	}

	// Add last node as end portal
	portals[index++] = ((NavMesh::Node*)path.back())->position;
	portals[index++] = ((NavMesh::Node*)path.back())->position;

	// Run funnelling algorithm
	Vector2 out[100];
	int count = stringPull(portals, index / 2, out, 100);

	// Gather up shortest path
	for (int i = 0; i < count; i++)
	{
		smoothPath.push_back(out[i]);
	}

	// Cleanup and return length of path
	delete[] portals;
	return smoothPath.size();
}