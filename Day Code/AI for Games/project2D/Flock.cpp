#include "Flock.h"
#include "Renderer2D.h"

Flock::Flock()
{
}

void Flock::CreateBoids(int count)
{
	for (int i = 0; i < count; i++)
	{
		boids.push_back(Boid());
	}
}


void Flock::draw(aie::Renderer2D* renderer)
{
	for (Boid& thisBoid : boids)
	{
		thisBoid.draw(renderer);
	}
}
