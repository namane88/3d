#version 150

in vec3 glNormal;
in vec3 glModelSpacePos;
in vec3 glLightPos;
in vec3 glColor;

float Ns = 92.156863;
vec3 Ka = vec3( 0.000000, 0.000000, 0.000000 );
vec3 Kd = vec3( 0.640000, 0.640000, 0.640000 );
vec3 Ks = vec3( 0.250000, 0.250000, 0.250000 );
float Ni = 1.000000;
float d  = 0.000000;
float illum = 2;


out vec4 glFragColor;

void main()
{
	//vec3 lightDir = normalize( glLightPos - glModelSpacePos );

	//float intensity = max(dot(normalize(glNormal), lightDir), 0.0);

	glFragColor = vec4(glColor, 1.0); //vec4(Kd, 0) * intensity + vec4(Ks, 0) * intensity;
}
