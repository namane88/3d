#include "vec3.h"

namespace math
{
	Vec3::Vec3() : x(0.0), y(0.0), z(0.0) {}
	
	Vec3::Vec3(float _x, float _y, float _z): x(_x), y(_y), z(_z) {}

	Vec3 &Vec3::operator+=(const Vec3& vo) {
		x += vo.x;
		y += vo.y;
		z += vo.z;

		return *this;
	}

	Vec3 &Vec3::operator-=(const Vec3& vo) {
		x -= vo.x;
		y -= vo.y;
		z -= vo.z;

		return *this;
	}

	Vec3 &Vec3::operator*=(const Vec3& vo) {
		x *= vo.x;
		y *= vo.y;
		z *= vo.z;

		return *this;
	}

	Vec3 &Vec3::operator/=(float d) {
		
		if ( d != 0.0 ) {
			x /= d;
			y /= d;
			z /= d;
		}

		return *this;
	}

	bool Vec3::operator==(const Vec3& vo) {
		return x == vo.x && y == vo.y && z == vo.z;
	}

	float Vec3::length() {
		return sqrt(x*x + y*y + z*z);
	}

	Vec3& Vec3::normalize() {
		return *this /= length();
	}

	std::string Vec3::str(const std::string &sep)
	{
		std::string s;

		return s.append( std::to_string(x) ).append(sep)
		.append( std::to_string(y) ).append(sep)
		.append( std::to_string(z) );
	}

	Vec3 Vec3::cross(const Vec3& rhs)
	{
		return Vec3(
			y * rhs.z - z * rhs.y,
			z * rhs.x - x * rhs.z,
			x * rhs.y - y * rhs.x
		);
	}

	float Vec3::dot(const Vec3& rhs)
	{
		return x * rhs.x + y * rhs.y + z * rhs.z;
	}


	Vec3 operator+(const Vec3& lhs, const Vec3& rhs)
	{
		return Vec3(lhs.x+rhs.x, lhs.y+rhs.y, lhs.z+rhs.z);
	}

	Vec3 operator-(const Vec3& lhs, const Vec3& rhs)
	{
		return Vec3(lhs.x-rhs.x, lhs.y-rhs.y, lhs.z-rhs.z);
	}

	Vec3 operator*(const Vec3& lhs, const Vec3& rhs)
	{
		return Vec3(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
	}


	Vec3 operator+(const Vec3& lhs, double v)
	{
		return Vec3(lhs.x + v, lhs.y + v, lhs.z + v);
	}

	Vec3 operator-(const Vec3& lhs, double v)
	{
		return Vec3(lhs.x - v, lhs.y - v, lhs.z - v);
	}
	
	Vec3 operator*(const Vec3& lhs, double v)
	{
		return Vec3(lhs.x * v, lhs.y * v, lhs.z * v);
	}
}
