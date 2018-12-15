#version 400
#extension GL_ARB_explicit_uniform_location : enable

layout(location = 2) uniform float time;

in vec3 interpolatedColor;
in vec2 fraguv;
out vec4 fragColor;

void main(void) {
    fragColor = vec4(0.0 , 0.0, abs(sin(time)), 1.0);
}
