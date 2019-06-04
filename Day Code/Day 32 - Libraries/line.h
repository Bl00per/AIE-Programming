#pragma once
#include <cmath>
#include <limits>
#include "collider.h"
#include "Vector2.h"

class line : public collider
{
public:
	static const Vector2 DEFAULT_NORMAL;

	line(const Vector2& a_normal = DEFAULT_NORMAL,
		const float a_distance = 0.0f);

	const Vector2 get_normal() const;
	void set_normal(const Vector2& a_normal);

	const float get_distance() const;
	void set_distance(const float a_distance);

private:
	Vector2 m_normal = DEFAULT_NORMAL;
	float m_distance = 0.0f;

};

