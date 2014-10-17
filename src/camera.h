#ifndef CAMERA_H
#define CAMERA_H

#include "math/vec3.h"
#include "math/mat4.h"

class Camera
{
	private:
		math::Vec3 location;
		math::Vec3 direction;
		math::Vec3 up;

		math::Mat4 perspective, modelview;

		float fov;
		float aspect;
		float zNear, zFar;
		float pitch, yaw;

	public:
		Camera(float, float, float, float);
		~Camera();


		math::Mat4 getViewMatrix();
		math::Mat4 &getModelview();
		
		void resetPerspectiveMatrix();

		void setLocation(float, float, float);
		void setLocation(const math::Vec3&);
		void setDirection(float, float, float);

		const math::Vec3& getLocation();

		void forward();
		void back();
		void left();
		void right();

		void setDirectionFromScreen(int, int);
};

#endif
