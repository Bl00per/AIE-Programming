#pragma once
#include <vector>

class Flock
{
public:
	std::vector<Boid> boids;

	void CreateBoids(int count);

	void draw(aie::Renderer2D* renderer);
};

