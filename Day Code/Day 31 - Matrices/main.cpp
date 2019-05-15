#include <iostream>
#include "matrix_3x3.h"

int main(void)
{
	matrix_3x3 matrix
	{
		10.0f, 2.0f, 8.0f,
		5.0f, 6.0f, 4.0f,
		1.0f, 2.0f, 3.0f
	};

	vector_3 matrix2x2
	{
		2.0f, 4.0f, 6.0f
	};

	matrix_3x3 matrix_result = matrix * matrix;

	vector_3 v3{ 1,1,1 };
	





	system("Pause");
	return 0;
}