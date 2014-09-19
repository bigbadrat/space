#version 330 core

uniform mat4 ModelViewProj;
uniform mat4 Model;
uniform mat4 ITModel;
uniform vec3 diffuse;
uniform vec3 light_dir;

layout(location=0) in vec3 vPosition;
layout(location=1) in vec3 vNormal;


out vec3 vColor;
out vec3 vLightDir;
out vec3 vVNormal;

void main()
{
    gl_Position = ModelViewProj * vec4(vPosition,1.0);
    vec3 surface_world_normal = normalize( (ITModel*vec4(vNormal,0.0)).xyz );

    vLightDir = light_dir;
    vVNormal = surface_world_normal;
	vColor = diffuse;//*surface_dot_light;
}