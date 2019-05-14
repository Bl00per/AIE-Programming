#include "matrix_3x3.h"



matrix_3x3::matrix_3x3(const float a_m00 /*= 1.0f*/, const float a_m01 /*= 0.0f*/, const float a_m02 /*= 0.0f*/,
	const float a_m10 /*= 0.0f*/, const float a_m11 /*= 1.0f*/, const float a_m12 /*= 0.0f*/,
	const float a_m20 /*= 0.0f*/, const float a_m21 /*= 0.0f*/, const float a_m22 /*= 1.0f*/) :
	_2D{ a_m00, a_m01, a_m02, a_m10, a_m11, a_m12, a_m20, a_m21, a_m22 }
{}

matrix_3x3::matrix_3x3(const vector_3& a_right, const vector_3& a_up, const vector_3& a_forward) :
	axes{ a_right, a_up, a_forward }
{

}
