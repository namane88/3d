#ifndef VEC3_H
#define VEC3_H

#include <string>
#include <math.h>

namespace math
{
	class Vec3
	{
		public:
			
			float x, y, z;

			Vec3();
			Vec3(float, float, float);

			Vec3 &operator+=(const Vec3& vo); 
			Vec3 &operator-=(const Vec3& vo);
			Vec3 &operator*=(const Vec3& vo);

			Vec3 &operator/=(float);

			bool operator==(const Vec3& vo);

			friend Vec3 operator+(const Vec3&, const Vec3&);
			friend Vec3 operator-(const Vec3&, const Vec3&);
			friend Vec3 operator*(const Vec3&, const Vec3&);
			
			friend Vec3 operator+(const Vec3&, double);
			friend Vec3 operator-(const Vec3&, double);
			friend Vec3 operator*(const Vec3&, double);

			Vec3 cross(const Vec3&);

			float dot(const Vec3& rhs);

			float length();

			Vec3& normalize();

			std::string str(const std::string &sep = ";");
	};
}

#endif
