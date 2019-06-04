#include "Vector4.h"
#include <cassert>
#include <math.h>

Vector4::Vector4(const float a_x, const float a_y, const float a_z, const float a_w)
	: data{ a_x, a_y, a_z, a_w }
{
}


// Default operators ( + - * / )
Vector4 Vector4::operator+(const Vector4& a_rhs) const
{
	return Vector4(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z, w + a_rhs.w);
}

Vector4 Vector4::operator-(const Vector4& a_rhs) const
{
	return Vector4(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z, w - a_rhs.w);
}

Vector4 Vector4::operator*(const float a_rhs) const
{
	return Vector4(x * a_rhs, y * a_rhs, z * a_rhs, w * a_rhs);
}

Vector4 Vector4::operator/(const float a_rhs) const
{
	return Vector4(x / a_rhs, y / a_rhs, z / a_rhs, w / a_rhs);
}


// Equals operators ( += -= *= /= )
Vector4& Vector4::operator+=(const Vector4& a_rhs)
{
	*this = *this + a_rhs;
	return *this;
}

Vector4& Vector4::operator-=(const Vector4& a_rhs)
{
	*this = *this - a_rhs;
	return *this;
}

Vector4& Vector4::operator*=(const float a_rhs)
{
	*this = *this * a_rhs;
	return *this;
}

Vector4& Vector4::operator/=(const float a_rhs)
{
	*this = *this / a_rhs;
	return *this;
}



float Vector4::square_magnitude() const
{
	return (x * x) + (y * y) + (z * z);
}

float Vector4::magnitude() const
{
	return (float)sqrt(square_magnitude());
}

void Vector4::normalise()
{
	*this /= magnitude();
}

Vector4 Vector4::normalise() const
{
	return *this / magnitude();
}

bool Vector4::operator==(const Vector4& a_rhs) const
{
	return ((x == a_rhs.x) && (y == a_rhs.y) && (z == a_rhs.z));
}

float Vector4::dot(const Vector4& a_Vector4) const
{
	return	(x * a_Vector4.x) +
			(y * a_Vector4.y) +
			(z * a_Vector4.z);
}

float Vector4::dot(const Vector4& a_Vector4_A, const Vector4& a_Vector4_B)
{
	return a_Vector4_A.dot(a_Vector4_B);
}

Vector4 Vector4::cross(const Vector4& a_Vector4) const
{
	return	{ y * a_Vector4.z - z * a_Vector4.y,
			z * a_Vector4.x - x * a_Vector4.z,
			x * a_Vector4.y - y * a_Vector4.x, w };
}

Vector4 Vector4::cross(const Vector4& a_Vector4_A, const Vector4& a_Vector4_B)
{
	return a_Vector4_A.cross(a_Vector4_B);
}

float& Vector4::operator[](const int a_index)
{
	_STL_ASSERT(a_index >= 0 && a_index < 2, "Vector 3 out of range");
	return data[a_index];
}

Vector4::operator float*()
{
	return data;
}

Vector4::operator const float*() const
{
	return data;
}

Vector4 operator*(const float a_lhs, const Vector4& a_rhs)
{
	return a_rhs * a_lhs;
}
