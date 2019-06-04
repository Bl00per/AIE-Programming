#include "Vector2.h"
#include <cassert>
#include <math.h>

Vector2::Vector2(const float a_x /*= 0.0f*/, const float a_y /*= 0.0f*/)
	: data{ a_x, a_y }
{
}

float& Vector2::operator[](const int a_index)
{
	// _STL_ASSERT(condition, "Message");
	_STL_ASSERT(a_index >= 0 && a_index < 2, "Vector 2 index out of range");
	return data[a_index];
}

Vector2 Vector2::operator+(const Vector2& a_rhs) const
{
	// User defined construction
	return Vector2(x + a_rhs.x, y + a_rhs.y);

	// Initializer list construction
	//return { x + a_rhs.x, y + a_rhs.y };
}

Vector2 Vector2::operator-(const Vector2& a_rhs) const
{
	return Vector2(x - a_rhs.x, y - a_rhs.y);
}

Vector2 Vector2::operator*(const float a_rhs) const
{
	return Vector2(x * a_rhs, y * a_rhs);
}

Vector2 Vector2::operator/(const float a_rhs) const
{
	return Vector2(x / a_rhs, y / a_rhs);
}

Vector2 operator*(const float a_lhs, const Vector2& a_rhs)
{
	return a_rhs * a_lhs;
}

Vector2& Vector2::operator+=(const Vector2& a_rhs)
{
	*this = *this + a_rhs;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& a_rhs)
{
	*this = *this - a_rhs;
	return *this;
}

Vector2& Vector2::operator*=(const float a_rhs)
{
	*this = *this * a_rhs;
	return *this;
}

Vector2& Vector2::operator/=(const float a_rhs)
{
	*this = *this / a_rhs;
	return *this;
}

Vector2::operator float*()
{
	return data;
}

Vector2::operator const float*() const
{
	return data;
}

float Vector2::square_magnitude() const
{
	return (x * x) + (y * y);
}

float Vector2::magnitude() const
{
	return (float)sqrt(square_magnitude());
}

void Vector2::normalise()
{
	*this /= magnitude();
}

Vector2 Vector2::normalised() const
{
	return *this / magnitude();
}

bool Vector2::operator==(const Vector2& a_rhs) const
{
	return ((x == a_rhs.x) && (y == a_rhs.y));
}

float Vector2::dot(const Vector2& a_Vector2) const
{
	return (x * a_Vector2.x) + (y * a_Vector2.y);
}

Vector2 Vector2::right() const
{
	return { y, -x };
}

float Vector2::dot(const Vector2& a_Vector2_A, const Vector2& a_Vector2_B)
{
	return a_Vector2_A.dot(a_Vector2_B);
}
