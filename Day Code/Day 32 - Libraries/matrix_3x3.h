#pragma once
#include "vector_3.h"

class matrix_3x3
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
			vector_3 right;
			vector_3 up;
			vector_3 forward;
		};

		vector_3 axes[3];
	};



	matrix_3x3(	const float a_m00 = 1.0f, const float a_m01 = 0.0f, const float a_m02 = 0.0f,	// Column 1
				const float a_m10 = 0.0f, const float a_m11 = 1.0f, const float a_m12 = 0.0f,	// Column 2
				const float a_m20 = 0.0f, const float a_m21 = 0.0f, const float a_m22 = 1.0f);	// Column 3

	matrix_3x3(const vector_3& a_right, const vector_3& a_up, const vector_3& a_forward);

	vector_3& operator[](const int a_index);
	const vector_3& operator[](const int a_index) const;

	matrix_3x3 operator*(const matrix_3x3& a_rhs) const;
	vector_3 operator*(const vector_3& a_rhs) const;

	operator float*();
	operator const float*() const;

	void setRotateX(float x_rotation){};
	void setRotateY(float y_rotation){};
	void setRotateZ(float z_rotation){};
};

