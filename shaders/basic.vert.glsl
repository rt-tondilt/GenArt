#version 400
#extension GL_ARB_explicit_uniform_location : enable

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;
layout(location = 2) uniform float time;

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;
layout(location = 2) in vec2 uv;
out vec3 interpolatedColor;
out vec2 fraguv;

void main(void) {
    interpolatedColor = color;
    fraguv = uv;
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(position, 1.0);
}
