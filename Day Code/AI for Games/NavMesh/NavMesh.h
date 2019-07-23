#pragma once

#include <vector>
#include <list>

///////////////////////////////////////////////////////////
// NOTE: This is included just for reference
// TODO: Replace with your own implementations!!
namespace Pathfinding {

	class Node;

	// a one-way link to a node with a cost
	class Edge {
	public:

		Edge() {}
		Edge(Node* t, float c) : target(t), cost(c) {}
		virtual ~Edge() {}

		Node* target = nullptr;
		float cost = 0;
	};

	// a node for any type of graph search
	// specific implementation details (such as position etc)
	// is implemented in derived classes
	class Node {
	public:

		Node() {}
		virtual ~Node() { for (auto e : edges) delete e; }

		std::vector<Edge*> edges;
	};
}

struct Vector2 {
	float x, y;
};

struct GameObject {
	Vector2 position = {};
	float speed = 50;

	// these are used by the NavMesh behaviours
	std::list<Vector2> smoothPath;
	std::list<Pathfinding::Node*> path;
};

class Behaviour {
public:

	// empty constructors and destructors for base class
	Behaviour() {}
	virtual ~Behaviour() {}

	// pure virtual function for executing the behaviour
	virtual bool execute(GameObject* gameObject, float deltaTime) = 0;
};
///////////////////////////////////////////////////////////

// forward declaring some Poly2Tri objects
namespace p2t {
	class CDT;
	struct Point;
}

class NavMesh {
public:

	// creates the base walkable area
	NavMesh(float width, float height);
	~NavMesh();

	struct Obstacle {
		float x, y, w, h, padding;
	};

	// returns true if the obstacle was added safely (does not overlap)
	bool addObstacle(float x, float y, float width, float height, float padding);

	// triangulates the walkable area and builds the nav mesh nodes
	void build();

	// given a list of pathfinding nodes from a pathfinding search,
	// treat them as NavMesh::Node's and smooth the path using a
	// funneling algorithm from (http://digestingduck.blogspot.com.au/2010/03/simple-stupid-funnel-algorithm.html)
	// we must build a list of portals first
	static int smoothPath(const std::list<Pathfinding::Node*>& path, std::list<Vector2>& smoothPath);

	// access nodes
	class Node;
	unsigned int getNodeCount() const { return m_nodes.size(); }
	const std::vector<NavMesh::Node*>& getNodes() const { return m_nodes; }

	// access random node or closest node to a coordinate
	NavMesh::Node* getRandomNode() const;
	NavMesh::Node* findClosest(float x, float y) const;

	// access osbatcles
	unsigned int getObstacleCount() const { return m_obstacles.size(); }
	const std::vector<Obstacle>& getObstacles() const { return m_obstacles; }

public:

	// the nav mesh node
	class Node : public Pathfinding::Node {
	public:

		Node() {}
		virtual ~Node() {}

		Vector2 position;

		// edges
		std::vector<Vector2> vertices;

		// finds any vertices that are shared with the other node
		int getAdjacentVertices(NavMesh::Node* other, Vector2* adjacent) {
			int count = 0;
			for (auto v : vertices) {
				for (auto v2 : other->vertices) {
					if (v.x == v2.x &&
						v.y == v2.y) {
						adjacent[count++] = v;
						break;
					}
				}
			}
			return count;
		}

		// simple distance squared
		static float heuristic(Pathfinding::Node* a, Pathfinding::Node* b) {
			NavMesh::Node* s = (NavMesh::Node*)a;
			NavMesh::Node* e = (NavMesh::Node*)b;
			float x = e->position.x - s->position.x;
			float y = e->position.y - s->position.y;
			return x * x + y * y;
		}
	};

	// a behaviour that follows a path
	class FollowPathBehaviour : public Behaviour {
	public:

		FollowPathBehaviour() {}
		virtual ~FollowPathBehaviour() {}

		virtual bool execute(GameObject* gameObject, float deltaTime);
	};

	// a behaviour that finds a new path and smooths it
	class NewPathBehaviour : public Behaviour {
	public:

		NewPathBehaviour(NavMesh* navMesh, std::list<Vector2>& smoothPath) : m_navMesh(navMesh), m_smoothPath(smoothPath) {}
		virtual ~NewPathBehaviour() {}

		virtual bool execute(GameObject* gameObject, float deltaTime);

	protected:

		NavMesh* m_navMesh;
		std::list<Vector2>& m_smoothPath;
	};

protected:

	// funneling algorithm from (http://digestingduck.blogspot.com.au/2010/03/simple-stupid-funnel-algorithm.html)
	inline static float triarea2(const Vector2& a, const Vector2& b, const Vector2& c) {
		const float ax = b.x - a.x;
		const float ay = b.y - a.y;
		const float bx = c.x - a.x;
		const float by = c.y - a.y;
		return bx*ay - ax*by;
	}
	inline static float vdistsqr(const Vector2& a, const Vector2& b) {
		float dx = a.x - b.x;
		float dy = a.y - b.y;
		return (dx*dx) + (dy*dy);
	}
	inline static bool vequal(const Vector2& a, const Vector2& b) {
		static const float eq = 0.001f*0.001f;
		return vdistsqr(a, b) < eq;
	}
	static int stringPull(const Vector2* portals, int portalCount, Vector2* points, const int maxPoints);

	// store obstacles and nav nodes
	std::vector<Obstacle> m_obstacles;
	std::vector<NavMesh::Node*> m_nodes;

	// this is used for building the mesh
	// uses Poly2Tri (https://github.com/greenm01/poly2tri)
	p2t::CDT* m_cdt;
	std::vector<std::vector<p2t::Point*>> m_polygons;
};