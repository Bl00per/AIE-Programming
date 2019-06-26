#include "Boid.h"
#include "Renderer2D.h"

Boid::Boid()
{
	position = vec2(rand() % 1280, rand() % 720);

	velocity = vec2(rand() % 10 - 5, rand() % 10 - 5);

	if (velocity.length() <= 0.00001f)
	{
		velocity = vec2(BOID_SPEED, 0.0f);
	}
	else
	{
		velocity /= velocity.length();
		velocity *= BOID_SPEED;
	}
}

void Boid::update(float deltaTime)
{
	// Create a list of other boids in the neighbourhood
	if (velocity.right <= 0.00001f)
	{
		velocity = vector_2(BOID_SPEED, 0.0f);
	}
	else
	{
		velocity /= velocity.right;
		velocity *= BOID_SPEED;
	}

	position += velocity * deltaTime;
}

void Boid::draw(aie::Renderer2D* renderer)
{
	renderer->drawCircle(position.x, position.y, 5.0f);
}