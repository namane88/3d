#include "camera.h"

Camera::Camera(float _fov, float _aspect, float _zNear, float _zFar)
	: fov(_fov), aspect(_aspect), zNear(_zNear), zFar(_zFar), pitch(0.0), yaw(0.0), up(0, 1, 0), modelview(1) 
{
	movementSpeed = 0.5;

	resetPerspectiveMatrix();
}

Camera::~Camera() {}

math::Mat4 &Camera::getModelview()
{
	return modelview;
}

math::Mat4 Camera::getViewMatrix()
{
	math::Vec3 f = direction;
	f.normalize();

	math::Vec3 s = f.cross(up).normalize();
	math::Vec3 u = s.cross(f);

	modelview[0 * 4 + 0] = s.x;
	modelview[1 * 4 + 0] = s.y;
	modelview[2 * 4 + 0] = s.z;

	modelview[0 * 4 + 1] = u.x;
	modelview[1 * 4 + 1] = u.y;
	modelview[2 * 4 + 1] = u.z;

	modelview[0 * 4 + 2]  = -f.x;
	modelview[1 * 4 + 2]  = -f.y;
	modelview[2 * 4 + 2]  = -f.z;

	modelview[3 * 4 + 0]  = - s.dot(location);
	modelview[3 * 4 + 1]  = - u.dot(location);
	modelview[3 * 4 + 2]  = + f.dot(location);
	
	return modelview * perspective;
}

void Camera::resetPerspectiveMatrix()
{
	double tanHalfFov = tan( ( fov * M_PI / 180.0 ) / 2.0);

	perspective[0 * 4 + 0]  = 1.0 / ( aspect * tanHalfFov);
	perspective[1 * 4 + 1]  = 1.0 / tanHalfFov;
	perspective[2 * 4 + 2] = -(zFar + zNear) / (zFar - zNear);
	perspective[2 * 4 + 3] = -1.0;
	perspective[3 * 4 + 2] = -(2.0 * zFar * zNear) / (zFar - zNear);
}


void Camera::setLocation(float x, float y, float z)
{
	location.x = x;
	location.y = y;
	location.z = z;
}

void Camera::setDirection(float x, float y, float z)
{
	direction.x = x;
	direction.y = y;
	direction.z = z;
}

void Camera::setLocation(const math::Vec3& loc)
{
	setLocation(loc.x, loc.y, loc.z);
}

const math::Vec3& Camera::getLocation() {
	return location;
}

void Camera::forward() {
	location += direction * movementSpeed;
}

void Camera::back() {
	location -= direction * movementSpeed;
}

void Camera::left() {
	location -= direction.cross(up) * movementSpeed;
}

void Camera::right() {
	location += direction.cross(up) * movementSpeed;
}

void Camera::setDirectionFromScreen(int xrel, int yrel)
{
	float x, y;

	pitch += xrel * -0.1;
	yaw   += yrel * -0.1;

	if ( yaw >  89.0 ) yaw =  89.0;
	if ( yaw < -89.0 ) yaw = -89.0;

	x = pitch * M_PI / 180.0;
	y = yaw   * M_PI / 180.0;
	
	direction.x = cos(y) * sin(x);
	direction.y = sin(y);
	direction.z = cos(y) * cos(x);
}

