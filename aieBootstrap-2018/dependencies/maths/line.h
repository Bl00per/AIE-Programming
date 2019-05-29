#pragma once
#include <cmath>
#include <limits>
#include "collider.h"
#include "vector_2.h"

class line : public collider
{
public:
	static const vector_2 DEFAULT_NORMAL;

	line(const vector_2& a_normal = DEFAULT_NORMAL,
		const float a_distance = 0.0f);

	const vector_2 get_normal() const;
	void set_normal(const vector_2& a_normal);

	const float get_distance() const;
	void set_distance(const float a_distance);

private:
	vector_2 m_normal = DEFAULT_NORMAL;
	float m_distance = 0.0f;

};

