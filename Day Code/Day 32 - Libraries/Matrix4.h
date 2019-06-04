#pragma once
#include "Vector4.h"

class Matrix4
{
public:
	union
	{
		struct 
		{
			float x_axis[4];
			float y_axis[4];
			float z_axis[4];
			float w_axis[4];
		};

		float _1D[16];
		float _2D[4][4];

		struct 
		{
			Vector4 right;
			Vector4 up;
			Vector4 forward;
			Vector4 position;
		};

		Vector4 axes[4];
	};



	Matrix4(	const float a_m00 = 1.0f, const float a_m01 = 0.0f, const float a_m02 = 0.0f, const float a_m03 = 0.0f,	// Column 1
				const float a_m10 = 0.0f, const float a_m11 = 1.0f, const float a_m12 = 0.0f, const float a_m13 = 0.0f,	// Column 2
				const float a_m20 = 0.0f, const float a_m21 = 0.0f, const float a_m22 = 1.0f, const float a_m23 = 0.0f,	// Column 3
				const float a_m30 = 0.0f, const float a_m31 = 0.0f, const float a_m32 = 0.0f, const float a_m33 = 1.0f);// Column 4

	Matrix4(const Vector4& a_right, const Vector4& a_up, const Vector4& a_forward, Vector4& a_position);

	Vector4& operator[](const int a_index);
	const Vector4& operator[](const int a_index) const;

	Matrix4 operator*(const Matrix4& a_rhs) const;
	Vector4 operator*(const Vector4& a_rhs) const;

	operator float*();
	operator const float*() const;

	void setRotateX(float x_rotation);
	void setRotateY(float y_rotation);
	void setRotateZ(float z_rotation);
};

