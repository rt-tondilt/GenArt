#version 400
#extension GL_ARB_explicit_uniform_location : enable

const float PI = 3.1415926535897932384626433832795;


layout(location = 2) uniform float time;
in vec3 interpolatedColor;
in vec2 fraguv;
out vec4 fragColor;

mat2 rotate2d(float theta) {
    return mat2(-cos(theta), -sin(theta), sin(theta), cos(theta));
}

float rand(float x) {
    return fract(sin(x*133.)*1152.13);
}

void main() {
    vec2 uv = fraguv;
    const vec3 purp = vec3(0.5, 0., 1.);
    const vec3 green = vec3(0., 0.6, 0.3);
    uv.y *= 2.;
    uv *= rotate2d(2.816);

    float stat = rand( floor(uv.x * 500.));
    float stat2 = (sin(rand(floor(uv.x*500.))) - 0.2) * PI;
    float moving1, moving2;
    moving1 = clamp(sin(time * 9.592 * stat + uv.y * (7.096/(stat + -2.336))) - 0.9, 0., 1.008)* 7.960 ;
    moving2 = clamp(sin(time * 5.112 * stat2 + uv.y * (7.096/(stat2 + -0.344))) - 0.95, 0., 1.) * 20. ;

    vec3 final = vec3(moving1 * purp * stat + moving2 * green * stat2);

    fragColor = vec4(final,1.0);
}
