#include "Vector3.h"
#include <cassert>
#include <math.h>

Vector3::Vector3(const float a_x, const float a_y, const float a_z)
	: data{ a_x, a_y, a_z }
{
}


// Default operators ( + - * / )
Vector3 Vector3::operator+(const Vector3& a_rhs) const
{
	return Vector3(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z);
}

Vector3 Vector3::operator-(const Vector3& a_rhs) const
{
	return Vector3(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z);
}

Vector3 Vector3::operator*(const float a_rhs) const
{
	return Vector3(x * a_rhs, y * a_rhs, z * a_rhs);
}

Vector3 Vector3::operator/(const float a_rhs) const
{
	return Vector3(x / a_rhs, y / a_rhs, z / a_rhs);
}


// Equals operators ( += -= *= /= )
Vector3& Vector3::operator+=(const Vector3& a_rhs)
{
	*this = *this + a_rhs;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& a_rhs)
{
	*this = *this - a_rhs;
	return *this;
}

Vector3& Vector3::operator*=(const float a_rhs)
{
	*this = *this * a_rhs;
	return *this;
}

Vector3& Vector3::operator/=(const float a_rhs)
{
	*this = *this / a_rhs;
	return *this;
}



float Vector3::square_magnitude() const
{
	return (x * x) + (y * y) + (z * z);
}

float Vector3::magnitude() const
{
	return (float)sqrt(square_magnitude());
}

void Vector3::normalise()
{
	*this /= magnitude();
}

Vector3 Vector3::normalise() const
{
	return *this / magnitude();
}

bool Vector3::operator==(const Vector3& a_rhs) const
{
	return ((x == a_rhs.x) && (y == a_rhs.y) && (z == a_rhs.z));
}

float Vector3::dot(const Vector3& a_Vector3) const
{
	return	(x * a_Vector3.x) +
			(y * a_Vector3.y) +
			(z * a_Vector3.z);
}

float Vector3::dot(const Vector3& a_Vector3_A, const Vector3& a_Vector3_B)
{
	return a_Vector3_A.dot(a_Vector3_B);
}

Vector3 Vector3::cross(const Vector3& a_Vector3) const
{
	return	{ y * a_Vector3.z - z * a_Vector3.y,
			z * a_Vector3.x - x * a_Vector3.z,
			x * a_Vector3.y - y * a_Vector3.x };
}

Vector3 Vector3::cross(const Vector3& a_Vector3_A, const Vector3& a_Vector3_B)
{
	return a_Vector3_A.cross(a_Vector3_B);
}

float& Vector3::operator[](const int a_index)
{
	_STL_ASSERT(a_index >= 0 && a_index < 2, "Vector 3 out of range");
	return data[a_index];
}

Vector3::operator float*()
{
	return data;
}

Vector3::operator const float*() const
{
	return data;
}

Vector3 operator*(const float a_lhs, const Vector3& a_rhs)
{
	return a_rhs * a_lhs;
}
