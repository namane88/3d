#ifndef MAT4_H
#define MAT4_H

#include <iostream>
#include <assert.h>
#include <cstring>
#include <math.h>

namespace math 
{

	class Mat4
	{
		private:
			float values[16];

		public:
			Mat4();
			Mat4(float value);

			float *ref();

			float& operator[](const int index) {
				assert( index >= 0 && index <= 16);
				
				return values[index];
			}

			friend Mat4 operator*(Mat4 &lhs, Mat4 &rhs);

			void setIdentity(float value);

			void clear();

			void print() {	
				for(int i = 1; i <= 16; i++) {
					std::cout << values[i-1] << "\t";

					if ( 0 == (i % 4) ) std::cout << std::endl;
				}

				std::cout << std::endl;
			}

			float determinant();
	};

}
#endif
