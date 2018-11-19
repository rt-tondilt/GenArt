#version 400

in vec3 interpolatedColor;
in vec2 fraguv;
out vec4 fragColor;

void main(void) {
    fragColor = vec4(fraguv, 0.0, 1.0);
}
