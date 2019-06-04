#pragma once
#include "Vector3.h"

class Matrix3
{
public:
	union
	{
		struct 
		{
			float x_axis[3];
			float y_axis[3];
			float z_axis[3];
		};

		float _1D[9];
		float _2D[3][3];

		struct 
		{
			Vector3 right;
			Vector3 up;
			Vector3 forward;
		};

		Vector3 axes[3];
	};



	Matrix3(	const float a_m00 = 1.0f, const float a_m01 = 0.0f, const float a_m02 = 0.0f,	// Column 1
				const float a_m10 = 0.0f, const float a_m11 = 1.0f, const float a_m12 = 0.0f,	// Column 2
				const float a_m20 = 0.0f, const float a_m21 = 0.0f, const float a_m22 = 1.0f);	// Column 3

	Matrix3(const Vector3& a_right, const Vector3& a_up, const Vector3& a_forward);

	Vector3& operator[](const int a_index);
	const Vector3& operator[](const int a_index) const;

	Matrix3 operator*(const Matrix3& a_rhs) const;
	Vector3 operator*(const Vector3& a_rhs) const;

	operator float*();
	operator const float*() const;

	void setRotateX(float x_rotation);
	void setRotateY(float y_rotation);
	void setRotateZ(float z_rotation);
};

