#include "line.h"


const Vector2 line::DEFAULT_NORMAL = { 1.0f, 0.0f };

line::line(const Vector2& a_normal /*= { 1.0f, 0.0f }*/,
	const float a_distance /*= 0.0f*/) :
	m_normal(a_normal),
	m_distance(a_distance),
	collider(shape::line)
{
	set_normal(m_normal);
}

const Vector2 line::get_normal() const
{
	return m_normal;
}

void line::set_normal(const Vector2& a_normal)
{
	if (m_normal.square_magnitude() < std::numeric_limits<float>::min())
	{
		m_normal = DEFAULT_NORMAL;
	}
	else
	{
		m_normal.normalise();
	}
}

const float line::get_distance() const
{
	return m_distance;
}

void line::set_distance(const float a_distance)
{

}
