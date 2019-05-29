#pragma once
#include <cmath>
#include "collider.h"
#include "vector_2.h"

class aligned_bounding_box : public collider
{
public:

	static const vector_2 DEFAULT_EXTENTS;

	aligned_bounding_box(const vector_2& a_position = vector_2(),
						 const vector_2& a_extents = DEFAULT_EXTENTS);

	const vector_2 get_position() const;
	void set_position(const vector_2& a_position);

	const vector_2 get_extents() const;
	void set_extents(const vector_2& a_extents);

	const float get_width();
	const float get_height();

	const vector_2 get_min() const;
	const vector_2 get_max() const;

private:
	vector_2 m_position{ 0.0f, 0.0f };

	union
	{
		vector_2 m_extents;
		struct
		{
			float width;
			float height;
		};
	};

};

