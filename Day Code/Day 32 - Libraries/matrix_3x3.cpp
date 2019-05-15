// For reference: http://mathworld.wolfram.com/RotationMatrix.html


#include "matrix_3x3.h"
#include <cstdlib>


matrix_3x3::matrix_3x3(const float a_m00 /*= 1.0f*/, const float a_m01 /*= 0.0f*/, const float a_m02 /*= 0.0f*/,
	const float a_m10 /*= 0.0f*/, const float a_m11 /*= 1.0f*/, const float a_m12 /*= 0.0f*/,
	const float a_m20 /*= 0.0f*/, const float a_m21 /*= 0.0f*/, const float a_m22 /*= 1.0f*/) :
	_2D{ a_m00, a_m01, a_m02, a_m10, a_m11, a_m12, a_m20, a_m21, a_m22 }
{}

matrix_3x3::matrix_3x3(const vector_3& a_right, const vector_3& a_up, const vector_3& a_forward) :
	axes{ a_right, a_up, a_forward }
{

}

vector_3& matrix_3x3::operator[](const int a_index)
{
	return axes[a_index];
}

const vector_3& matrix_3x3::operator[](const int a_index) const
{
	return axes[a_index];
}

matrix_3x3 matrix_3x3::operator*(const matrix_3x3& a_rhs) const
{
	return 
	{
		_2D[0][0] * a_rhs._2D[0][0] + _2D[1][0] * a_rhs._2D[0][1] + _2D[2][0] * a_rhs._2D[0][2], // First line
		_2D[0][1] * a_rhs._2D[0][0] + _2D[1][1] * a_rhs._2D[0][1] + _2D[2][1] * a_rhs._2D[0][2], // Expand to 1 column
		_2D[0][2] * a_rhs._2D[0][0] + _2D[1][2] * a_rhs._2D[0][1] + _2D[2][2] * a_rhs._2D[0][2],

		_2D[0][0] * a_rhs._2D[1][0] + _2D[1][0] * a_rhs._2D[1][1] + _2D[2][0] * a_rhs._2D[1][2], // Moving across RHS columns
		_2D[0][1] * a_rhs._2D[1][0] + _2D[1][1] * a_rhs._2D[1][1] + _2D[2][1] * a_rhs._2D[1][2],
		_2D[0][2] * a_rhs._2D[1][0] + _2D[1][2] * a_rhs._2D[1][1] + _2D[2][2] * a_rhs._2D[1][2],

		_2D[0][0] * a_rhs._2D[2][0] + _2D[1][0] * a_rhs._2D[2][1] + _2D[2][0] * a_rhs._2D[2][2], // Moving accross RHS columns
		_2D[0][1] * a_rhs._2D[2][0] + _2D[1][1] * a_rhs._2D[2][1] + _2D[2][1] * a_rhs._2D[2][2],
		_2D[0][2] * a_rhs._2D[2][0] + _2D[1][2] * a_rhs._2D[2][1] + _2D[2][2] * a_rhs._2D[2][2]
	};
}

vector_3 matrix_3x3::operator*(const vector_3& a_rhs) const
{
	return
	{
		_2D[0][0] * a_rhs[0] + _2D[1][0] * a_rhs[1] + _2D[2][0] * a_rhs[2], // First line
		_2D[0][1] * a_rhs[0] + _2D[1][1] * a_rhs[1] + _2D[2][1] * a_rhs[2], // Expand to 1 column
		_2D[0][2] * a_rhs[0] + _2D[1][2] * a_rhs[1] + _2D[2][2] * a_rhs[2]
	};
}

matrix_3x3::operator float*()
{
	return _1D;
}

matrix_3x3::operator const float*() const
{
	return _1D;
}

void matrix_3x3::setRotateX(float x_rotation)
{
	_1D[4] = cos(x_rotation);
	_1D[5] = sin(x_rotation);
	_1D[7] = -sin(x_rotation);
	_1D[8] = cos(x_rotation);
}

void matrix_3x3::setRotateY(float y_rotation)
{
	_1D[0] = cos(y_rotation);
	_1D[2] = -sin(y_rotation);
	_1D[6] = sin(y_rotation);
	_1D[8] = cos(y_rotation);
}

void matrix_3x3::setRotateZ(float z_rotation)
{
	_1D[0] = cos(z_rotation);
	_1D[1] = sin(z_rotation);
	_1D[3] = -sin(z_rotation);
	_1D[4] = cos(z_rotation);
}