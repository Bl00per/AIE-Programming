// For reference: http://mathworld.wolfram.com/RotationMatrix.html

#include "Matrix4.h"
#include <cstdlib>



Matrix4::Matrix4(const float a_m00 /*= 1.0f*/, const float a_m01 /*= 0.0f*/, const float a_m02 /*= 0.0f*/, const float a_m03 /*= 0.0f*/,
	const float a_m10 /*= 0.0f*/, const float a_m11 /*= 1.0f*/, const float a_m12 /*= 0.0f*/, const float a_m13 /*= 0.0f*/,
	const float a_m20 /*= 0.0f*/, const float a_m21 /*= 0.0f*/, const float a_m22 /*= 1.0f*/, const float a_m23 /*= 0.0f*/,
	const float a_30 /*= 0.0f*/, const float a_31 /*= 0.0f*/, const float a_32 /*= 0.0f*/, const float a_33 /*= 1.0f*/) :
	_2D{ a_m00, a_m01, a_m02, a_m03, a_m10, a_m11, a_m12, a_m13, a_m20, a_m21, a_m22, a_m23, a_30, a_31, a_32, a_33 }
{}

Matrix4::Matrix4(const Vector4& a_right, const Vector4& a_up, const Vector4& a_forward, Vector4& a_position) :
	axes{ a_right, a_up, a_forward, a_position }
{

}

Vector4& Matrix4::operator[](const int a_index)
{
	return axes[a_index];
}

const Vector4& Matrix4::operator[](const int a_index) const
{
	return axes[a_index];
}

Matrix4 Matrix4::operator*(const Matrix4& a_rhs) const
{
	return 
	{
		_2D[0][0] * a_rhs._2D[0][0] + _2D[1][0] * a_rhs._2D[0][1] + _2D[2][0] * a_rhs._2D[0][2] + _2D[3][0] * a_rhs._2D[0][3], // First line
		_2D[0][1] * a_rhs._2D[0][0] + _2D[1][1] * a_rhs._2D[0][1] + _2D[2][1] * a_rhs._2D[0][2] + _2D[3][1] * a_rhs._2D[0][3], // Expand to 1 column
		_2D[0][2] * a_rhs._2D[0][0] + _2D[1][2] * a_rhs._2D[0][1] + _2D[2][2] * a_rhs._2D[0][2] + _2D[3][2] * a_rhs._2D[0][3],
		_2D[0][3] * a_rhs._2D[0][0] + _2D[1][3] * a_rhs._2D[0][1] + _2D[2][3] * a_rhs._2D[0][2] + _2D[3][3] * a_rhs._2D[0][3],

		_2D[0][0] * a_rhs._2D[1][0] + _2D[1][0] * a_rhs._2D[1][1] + _2D[2][0] * a_rhs._2D[1][2] + _2D[3][0] * a_rhs._2D[1][3], // NEW LINE
		_2D[0][1] * a_rhs._2D[1][0] + _2D[1][1] * a_rhs._2D[1][1] + _2D[2][1] * a_rhs._2D[1][2] + _2D[3][1] * a_rhs._2D[1][3],
		_2D[0][2] * a_rhs._2D[1][0] + _2D[1][2] * a_rhs._2D[1][1] + _2D[2][2] * a_rhs._2D[1][2] + _2D[3][2] * a_rhs._2D[1][3],
		_2D[0][3] * a_rhs._2D[1][0] + _2D[1][3] * a_rhs._2D[1][1] + _2D[2][3] * a_rhs._2D[1][2] + _2D[3][3] * a_rhs._2D[1][3],

		_2D[0][0] * a_rhs._2D[2][0] + _2D[1][0] * a_rhs._2D[2][1] + _2D[2][0] * a_rhs._2D[2][2] + _2D[3][0] * a_rhs._2D[2][3], // NEW LINE
		_2D[0][1] * a_rhs._2D[2][0] + _2D[1][1] * a_rhs._2D[2][1] + _2D[2][1] * a_rhs._2D[2][2] + _2D[3][1] * a_rhs._2D[2][3],
		_2D[0][2] * a_rhs._2D[2][0] + _2D[1][2] * a_rhs._2D[2][1] + _2D[2][2] * a_rhs._2D[2][2] + _2D[3][2] * a_rhs._2D[2][3],
		_2D[0][3] * a_rhs._2D[2][0] + _2D[1][3] * a_rhs._2D[2][1] + _2D[2][3] * a_rhs._2D[2][2] + _2D[3][3] * a_rhs._2D[2][3],

		_2D[0][0] * a_rhs._2D[3][0] + _2D[1][0] * a_rhs._2D[3][1] + _2D[2][0] * a_rhs._2D[3][2] + _2D[3][0] * a_rhs._2D[3][3], // NEW SECTION
		_2D[0][1] * a_rhs._2D[3][0] + _2D[1][1] * a_rhs._2D[3][1] + _2D[2][1] * a_rhs._2D[3][2] + _2D[3][1] * a_rhs._2D[3][3],
		_2D[0][2] * a_rhs._2D[3][0] + _2D[1][2] * a_rhs._2D[3][1] + _2D[2][2] * a_rhs._2D[3][2] + _2D[3][2] * a_rhs._2D[3][3],
		_2D[0][3] * a_rhs._2D[3][0] + _2D[1][3] * a_rhs._2D[3][1] + _2D[2][3] * a_rhs._2D[3][2] + _2D[3][3] * a_rhs._2D[3][3]
	};
}

Vector4 Matrix4::operator*(const Vector4& a_rhs) const
{
	return
	{
		_2D[0][0] * a_rhs[0] + _2D[1][0] * a_rhs[1] + _2D[2][0] * a_rhs[2] + _2D[3][0] * a_rhs[3], // Moving accross RHS columns
		_2D[0][1] * a_rhs[0] + _2D[1][1] * a_rhs[1] + _2D[2][1] * a_rhs[2] + _2D[3][1] * a_rhs[3],
		_2D[0][2] * a_rhs[0] + _2D[1][2] * a_rhs[1] + _2D[2][2] * a_rhs[2] + _2D[3][2] * a_rhs[3],
		_2D[0][3] * a_rhs[0] + _2D[1][3] * a_rhs[1] + _2D[2][3] * a_rhs[2] + _2D[3][3] * a_rhs[3]
	};
}

Matrix4::operator float*()
{
	return _1D;
}

Matrix4::operator const float*() const
{
	return _1D;
}

void Matrix4::setRotateX(float x_rotation)
{
	_1D[5] = cos(x_rotation);
	_1D[6] = sin(x_rotation);
	_1D[9] = -sin(x_rotation);
	_1D[10] = cos(x_rotation);
}

void Matrix4::setRotateY(float y_rotation)
{
	_1D[0] = cos(y_rotation);
	_1D[2] = -sin(y_rotation);
	_1D[8] = sin(y_rotation);
	_1D[10] = cos(y_rotation);
}

void Matrix4::setRotateZ(float z_rotation)
{
	_1D[0] = cos(z_rotation);
	_1D[1] = sin(z_rotation);
	_1D[4] = -sin(z_rotation);
	_1D[5] = cos(z_rotation);
}