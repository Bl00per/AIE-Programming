#pragma once

#include "vector_2.h"
#include <cmath>

#define BOID_SPEED 5.0f

namespace aie
{
	class Renderer2D;
}

class Flock;

class Boid
{

public:
	Boid();

	vector_2 position;
	vector_2 velocity;

	void update(float deltaTime);
	void draw(aie::Renderer2D* renderer);

};