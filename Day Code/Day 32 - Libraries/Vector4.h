#pragma once

#ifndef _Vector4_
#define _Vector4_

class Vector4
{
public:
	union
	{
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
		float data[4];
	};
	// Set default values for x, y & z
	Vector4(const float a_x = 0.0f, const float a_y = 0.0f, const float a_z = 0.0f, const float a_w = 1.0f);

	Vector4 operator+(const Vector4& a_rhs) const;
	Vector4 operator-(const Vector4& a_rhs) const;
	Vector4 operator*(const float a_rhs) const;
	Vector4 operator/(const float a_rhs) const;
	
	Vector4& operator+=(const Vector4& a_rhs);
	Vector4& operator-=(const Vector4& a_rhs);
	Vector4& operator*=(const float a_rhs);
	Vector4& operator/=(const float a_rhs);
	
	float square_magnitude() const;
	float magnitude() const;

	void normalise();
	Vector4 normalise() const;

	bool operator==(const Vector4& a_rhs) const;

	float dot(const Vector4& a_Vector4) const;
	static float dot(const Vector4& a_Vector4_A, const Vector4& a_Vector4_B);

	Vector4 cross(const Vector4& a_Vector4) const;
	static Vector4 cross(const Vector4& a_Vector4_A, const Vector4& a_Vector4_B);

	float& operator[](const int a_index);
	operator float*();
	operator const float*() const;
};

Vector4 operator*(const float a_lhs, const Vector4& a_rhs);

#endif // !_Vector4_
