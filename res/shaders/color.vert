#version 150

in vec3 vertex;
in vec3 normal;
in vec2 texcoord;
in vec3 color;

out vec3 glNormal;
out vec3 glModelSpacePos;
out vec3 glLightPos;
out vec3 glColor;

uniform mat4 MVP;
uniform mat4 MV;

void main()
{
	mat4 NM = transpose(inverse(MV));

	glNormal = vec3( NM * vec4(normal, 1.0) );
	glModelSpacePos = vec3( MV * vec4(vertex, 1.0) );
	glLightPos = vec3(0, 0, 0);

	glColor = color;

	gl_Position = MVP * vec4(vertex, 1.0);
}
