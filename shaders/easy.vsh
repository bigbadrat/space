#version 330 core

uniform mat4 ModelViewProj;
uniform mat4 Model;
uniform vec3 diffuse;
uniform vec3 light_dir;

layout(location=0) in vec3 vPosition;
layout(location=1) in vec3 vNormal;
layout(location=2) in vec3 vVertColor;

out vec3 vColor;

void main()
{
    gl_Position = ModelViewProj * vec4(vPosition,1.0);
    vec4 surface_world_normal = normalize(Model*vec4(vNormal,1.0));

    float surface_dot_light = dot(surface_world_normal.xyz,light_dir);
	vColor = vVertColor*surface_dot_light;

}