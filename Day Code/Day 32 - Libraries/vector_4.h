#pragma once

#ifndef _vector_4_
#define _vector_4_

class vector_4
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
	vector_4(const float a_x = 0.0f, const float a_y = 0.0f, const float a_z = 0.0f, const float a_w = 1.0f);

	vector_4 operator+(const vector_4& a_rhs) const;
	vector_4 operator-(const vector_4& a_rhs) const;
	vector_4 operator*(const float a_rhs) const;
	vector_4 operator/(const float a_rhs) const;
	
	vector_4& operator+=(const vector_4& a_rhs);
	vector_4& operator-=(const vector_4& a_rhs);
	vector_4& operator*=(const float a_rhs);
	vector_4& operator/=(const float a_rhs);
	
	float square_magnitude() const;
	float magnitude() const;

	void normalise();
	vector_4 normalise() const;

	bool operator==(const vector_4& a_rhs) const;

	float dot(const vector_4& a_vector_4) const;
	static float dot(const vector_4& a_vector_4_A, const vector_4& a_vector_4_B);

	vector_4 cross(const vector_4& a_vector_4) const;
	static vector_4 cross(const vector_4& a_vector_4_A, const vector_4& a_vector_4_B);

	float& operator[](const int a_index);
	operator float*();
	operator const float*() const;
};

vector_4 operator*(const float a_lhs, const vector_4& a_rhs);

#endif // !_vector_4_
