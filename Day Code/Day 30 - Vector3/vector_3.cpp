#include "vector_3.h"
#include <cassert>
#include <math.h>

vector_3::vector_3(const float a_x, const float a_y, const float a_z)
	: data{ a_x, a_y, a_z }
{
}


// Default operators ( + - * / )
vector_3 vector_3::operator+(const vector_3& a_rhs) const
{
	return vector_3(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z);
}

vector_3 vector_3::operator-(const vector_3& a_rhs) const
{
	return vector_3(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z);
}

vector_3 vector_3::operator*(const float a_rhs) const
{
	return vector_3(x * a_rhs, y * a_rhs, z * a_rhs);
}

vector_3 vector_3::operator/(const float a_rhs) const
{
	return vector_3(x / a_rhs, y / a_rhs, z / a_rhs);
}


// Equals operators ( += -= *= /= )
vector_3& vector_3::operator+=(const vector_3& a_rhs)
{
	*this = *this + a_rhs;
	return *this;
}

vector_3& vector_3::operator-=(const vector_3& a_rhs)
{
	*this = *this - a_rhs;
	return *this;
}

vector_3& vector_3::operator*=(const float a_rhs)
{
	*this = *this * a_rhs;
	return *this;
}

vector_3& vector_3::operator/=(const float a_rhs)
{
	*this = *this / a_rhs;
	return *this;
}



float vector_3::square_magnitude() const
{
	return (x * x) + (y * y) + (z * z);
}

float vector_3::magnitude() const
{
	return (float)sqrt(square_magnitude());
}

void vector_3::normalise()
{
	*this /= magnitude();
}

vector_3 vector_3::normalise() const
{
	return *this / magnitude();
}

bool vector_3::operator==(const vector_3& a_rhs) const
{
	return ((x == a_rhs.x) && (y == a_rhs.y) && (z == a_rhs.z));
}

float vector_3::dot(const vector_3& a_vector_3) const
{
	return	(x * a_vector_3.x) +
			(y * a_vector_3.y) +
			(z * a_vector_3.z);
}

float vector_3::dot(const vector_3& a_vector_3_A, const vector_3& a_vector_3_B)
{
	return a_vector_3_A.dot(a_vector_3_B);
}

vector_3 vector_3::cross(const vector_3& a_vector_3) const
{
	return	{ y * a_vector_3.z - z * a_vector_3.y,
			z * a_vector_3.x - x * a_vector_3.z,
			x * a_vector_3.y - y * a_vector_3.x };
}

vector_3 vector_3::cross(const vector_3& a_vector_3_A, const vector_3& a_vector_3_B)
{
	return a_vector_3_A.cross(a_vector_3_B);
}

float& vector_3::operator[](const int a_index)
{
	_STL_ASSERT(a_index >= 0 && a_index < 2, "Vector 3 out of range");
	return data[a_index];
}

vector_3::operator float*()
{
	return data;
}

vector_3::operator const float*() const
{
	return data;
}

vector_3 operator*(const float a_lhs, const vector_3& a_rhs)
{
	return a_rhs * a_lhs;
}
