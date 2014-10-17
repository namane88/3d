#include "mat4.h"


namespace math
{

Mat4::Mat4() {
	clear();
}

Mat4::Mat4(float value)
{
	setIdentity(value);
}


void Mat4::setIdentity(float value)
{
	clear();

	for(short i=0; i <= 15; i += 5)
		values[i] = value;
}

void Mat4::clear()
{
	memset(values, 0, sizeof(values));
}

Mat4 operator*(Mat4 &lhs, Mat4 &rhs)
{
	Mat4 result;
				
	for(int row = 0; row < 4; row++)
	{
		for(int col = 0; col < 4; col++)
		{
			result[ row * 4 + col ] = 0;

			for(int i =0; i < 4; i++)
			{
				result[row * 4 + col] +=  lhs[row * 4 + i] * rhs[col + i * 4];
			}
		}
	}

	return result;
}

float* Mat4::ref() {
	return &values[0];
}

void removeMinor(float *mat, int col, int s, float *minor)
{
	int ci = 0;

	for(int r=1; r < s; r++)
	{
		for(int c=0; c < s; c++)
		{
			if (c == col) continue;

			minor[ ci++ ] = mat[ c+r*s ];
		}
	}
}

float det(float *mat, int s)
{
	if ( s == 2 ) {
		return mat[0] * mat[3] - mat[1] * mat[2];
	}else {
		float v = 0.0;

		for(int col = 0; col < s; col++) 
		{
			int ms = s-1;
			float minor[ ms*ms ];

			removeMinor(mat, col, s, minor);

			v += pow(-1, col+1+1) * mat[col] * det(minor, ms);
		}

		return v;
	}
}

float Mat4::determinant() {
	return det(ref(), 4);	
}

}
