// @brief Vector2.h
// Class represents a pair f cartesian coordinates
// for use in two dimentional game systems

#pragma once

#ifndef _Vector2_
#define _Vector2_

class Vector2
{
public:
	/*	@brief Critical math data for Vector2
	*/
	union
	{
		struct
		{
			float x;
			float y;
		};
		float data[2];
	};

	Vector2(const float a_x = 0.0f, const float a_y = 0.0f);

	/*	@brief Subscript operator overloading to allow direct data access
		@param Index of the data member
		@return Reference to indexed data member
	*/
	float& operator[](const int a_index);

	/*	@brief Casting operator oveloading 
	*/
	operator float*();

	/*	@brief Casting read only float* operator oveloading
	*/
	operator const float*() const;

	Vector2 operator+(const Vector2& a_rhs) const;
	Vector2 operator-(const Vector2& a_rhs) const;
	Vector2 operator*(const float a_rhs) const;
	Vector2 operator/(const float a_rhs) const;

	Vector2& operator+=(const Vector2& a_rhs);
	Vector2& operator-=(const Vector2& a_rhs);
	Vector2& operator*=(const float a_rhs);
	Vector2& operator/=(const float a_rhs);

	float square_magnitude() const;
	float magnitude() const;

	void normalise();
	Vector2 normalised() const;

	float dot(const Vector2& a_Vector2) const;

	Vector2 right() const;

	float dot(const Vector2& a_Vector2_A, const Vector2& a_Vector2_B);

	bool operator==(const Vector2& a_rhs) const;
};

Vector2 operator*(const float a_lhs, const Vector2& a_rhs);

#endif // !_Vector2_
