#pragma once
#include <cmath>
#include "collider.h"
#include "vector_2.h"

class circle : public collider
{
public:
	const static float DEFAULT_RADIUS;

	circle(const vector_2& a_position = vector_2(), 
		   const float a_radius = DEFAULT_RADIUS);

	float get_radius() const;
	/*	@brief Sets the radius to the absolute value of the argument
		@param The new radius as float
	*/
	void set_radius(const float a_radius);

	const vector_2 get_position() const;
	void set_position(const vector_2& a_position);


private:
	float m_radius = 0.0f;
	vector_2 m_position{ 0.0f, 0.0f };
};
