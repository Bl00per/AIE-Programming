#pragma once

#ifndef _Vector3_
#define _Vector3_

class Vector3
{
public:
	union
	{
		struct
		{
			float x;
			float y;
			float z;
		};
		float data[3];
	};
	// Set default values for x, y & z
	Vector3(const float a_x = 0.0f, const float a_y = 0.0f, const float a_z = 0.0f);

	Vector3 operator+(const Vector3& a_rhs) const;
	Vector3 operator-(const Vector3& a_rhs) const;
	Vector3 operator*(const float a_rhs) const;
	Vector3 operator/(const float a_rhs) const;
	
	Vector3& operator+=(const Vector3& a_rhs);
	Vector3& operator-=(const Vector3& a_rhs);
	Vector3& operator*=(const float a_rhs);
	Vector3& operator/=(const float a_rhs);
	
	float square_magnitude() const;
	float magnitude() const;

	void normalise();
	Vector3 normalise() const;

	bool operator==(const Vector3& a_rhs) const;

	float dot(const Vector3& a_Vector3) const;
	static float dot(const Vector3& a_Vector3_A, const Vector3& a_Vector3_B);

	Vector3 cross(const Vector3& a_Vector3) const;
	static Vector3 cross(const Vector3& a_Vector3_A, const Vector3& a_Vector3_B);

	float& operator[](const int a_index);
	operator float*();
	operator const float*() const;
};

Vector3 operator*(const float a_lhs, const Vector3& a_rhs);

#endif // !_Vector3_
