#pragma once
#include <cmath>
#include "collider.h"
#include "Vector2.h"

class aligned_bounding_box : public collider
{
public:

	static const Vector2 DEFAULT_EXTENTS;

	aligned_bounding_box(const Vector2& a_position = Vector2(),
						 const Vector2& a_extents = DEFAULT_EXTENTS);

	const Vector2 get_position() const;
	void set_position(const Vector2& a_position);

	const Vector2 get_extents() const;
	void set_extents(const Vector2& a_extents);

	const float get_width();
	const float get_height();

	const Vector2 get_min() const;
	const Vector2 get_max() const;

private:
	Vector2 m_position{ 0.0f, 0.0f };

	union
	{
		Vector2 m_extents;
		struct
		{
			float width;
			float height;
		};
	};

};

