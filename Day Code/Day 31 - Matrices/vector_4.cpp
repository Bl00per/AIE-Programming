#include "vector_4.h"
#include <cassert>
#include <math.h>

vector_4::vector_4(const float a_x, const float a_y, const float a_z, const float a_w)
	: data{ a_x, a_y, a_z, a_w }
{
}


// Default operators ( + - * / )
vector_4 vector_4::operator+(const vector_4& a_rhs) const
{
	return vector_4(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z, w + a_rhs.w);
}

vector_4 vector_4::operator-(const vector_4& a_rhs) const
{
	return vector_4(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z, w - a_rhs.w);
}

vector_4 vector_4::operator*(const float a_rhs) const
{
	return vector_4(x * a_rhs, y * a_rhs, z * a_rhs, w * a_rhs);
}

vector_4 vector_4::operator/(const float a_rhs) const
{
	return vector_4(x / a_rhs, y / a_rhs, z / a_rhs, w / a_rhs);
}


// Equals operators ( += -= *= /= )
vector_4& vector_4::operator+=(const vector_4& a_rhs)
{
	*this = *this + a_rhs;
	return *this;
}

vector_4& vector_4::operator-=(const vector_4& a_rhs)
{
	*this = *this - a_rhs;
	return *this;
}

vector_4& vector_4::operator*=(const float a_rhs)
{
	*this = *this * a_rhs;
	return *this;
}

vector_4& vector_4::operator/=(const float a_rhs)
{
	*this = *this / a_rhs;
	return *this;
}



float vector_4::square_magnitude() const
{
	return (x * x) + (y * y) + (z * z);
}

float vector_4::magnitude() const
{
	return (float)sqrt(square_magnitude());
}

void vector_4::normalize()
{
	*this /= magnitude();
}

vector_4 vector_4::normalized() const
{
	return *this / magnitude();
}

bool vector_4::operator==(const vector_4& a_rhs) const
{
	return ((x == a_rhs.x) && (y == a_rhs.y) && (z == a_rhs.z));
}

float vector_4::dot(const vector_4& a_vector_4) const
{
	return	(x * a_vector_4.x) +
			(y * a_vector_4.y) +
			(z * a_vector_4.z);
}

float vector_4::dot(const vector_4& a_vector_4_A, const vector_4& a_vector_4_B)
{
	return a_vector_4_A.dot(a_vector_4_B);
}

vector_4 vector_4::cross(const vector_4& a_vector_4) const
{
	return	{ y * a_vector_4.z - z * a_vector_4.y,
			z * a_vector_4.x - x * a_vector_4.z,
			x * a_vector_4.y - y * a_vector_4.x };
}

vector_4 vector_4::cross(const vector_4& a_vector_4_A, const vector_4& a_vector_4_B)
{
	return a_vector_4_A.cross(a_vector_4_B);
}

float& vector_4::operator[](const int a_index)
{
	_STL_ASSERT(a_index >= 0 && a_index < 2, "Vector 3 out of range");
	return data[a_index];
}

vector_4::operator float*()
{
	return data;
}

vector_4::operator const float*() const
{
	return data;
}

vector_4 operator*(const float a_lhs, const vector_4& a_rhs)
{
	return a_rhs * a_lhs;
}
