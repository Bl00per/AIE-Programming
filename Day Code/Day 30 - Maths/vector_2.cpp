#include "vector_2.h"
#include <cassert>
#include <math.h>


//Vector_2::Vector_2() : x (0.0f), y(0.0f)
//{
//}

vector_2::vector_2(const float a_x /*= 0.0f*/, const float a_y /*= 0.0f*/) : x(a_x), y(a_y)
{
}


float& vector_2::operator[](const int a_index)
{
	// _STL_ASSERT(condition, "Message");
	_STL_ASSERT(a_index >= 0 && a_index < 2, "Vector 2 index out of range");
	return data[a_index];
}

vector_2 vector_2::operator+(const vector_2& a_rhs) const
{
	// User defined construction
	return vector_2(x + a_rhs.x, y + a_rhs.y);

	// Initializer list construction
	//return { x + a_rhs.x, y + a_rhs.y };
}

vector_2 vector_2::operator-(const vector_2& a_rhs) const
{
	return vector_2(x - a_rhs.x, y - a_rhs.y);
}

vector_2 vector_2::operator*(const float a_rhs) const
{
	return vector_2(x * a_rhs, y * a_rhs);
}

vector_2 vector_2::operator/(const float a_rhs) const
{
	return vector_2(x / a_rhs, y / a_rhs);
}

vector_2 operator*(const float a_lhs, const vector_2& a_rhs)
{
	return a_rhs * a_lhs;
}

vector_2& vector_2::operator+=(const vector_2& a_rhs)
{
	*this = *this + a_rhs;
	return *this;
}

vector_2& vector_2::operator-=(const vector_2& a_rhs)
{
	*this = *this - a_rhs;
	return *this;
}

vector_2& vector_2::operator*=(const float a_rhs)
{
	*this = *this * a_rhs;
	return *this;
}

vector_2& vector_2::operator/=(const float a_rhs)
{
	*this = *this / a_rhs;
	return *this;
}

vector_2::operator float*()
{
	return data;
}

vector_2::operator const float*() const
{
	return data;
}

float vector_2::square_magnitude() const
{
	return (x * x) + (y * y);
}

float vector_2::magnitude() const
{
	return sqrt(square_magnitude());
}

void vector_2::normalize()
{
	*this /= magnitude();
}

vector_2 vector_2::normalized() const
{
	return *this / magnitude();
}

bool vector_2::operator==(const vector_2& a_rhs) const
{
	return ((x == a_rhs.x) && (y == a_rhs.y));
}