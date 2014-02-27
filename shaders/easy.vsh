#version 330 core

uniform mat4 MVP;
uniform vec3 diffuse;

layout(location=0) in vec3 vPosition;

out vec3 vColor;

void main()
{
    gl_Position = MVP * vec4(vPosition,1.0);
	vColor = diffuse;
	//gl_Position = vec4(vPosition,1.0);
}