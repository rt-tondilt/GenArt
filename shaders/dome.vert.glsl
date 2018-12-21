#version 400

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

layout(location = 0) in vec3 position;
layout(location = 2) in vec2 uv;
out vec3 interpolatedColor;
out vec2 fraguv;

void main(void) {
    interpolatedColor = vec3(0.5, 0.5, 0.5);
    fraguv = uv;
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(position, 1.0);
}
