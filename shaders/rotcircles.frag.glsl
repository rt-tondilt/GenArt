
#version 400
#extension GL_ARB_explicit_uniform_location : enable

const float PI = 3.1415926535897932384626433832795;
const float N = 7.;


layout(location = 2) uniform float time;
in vec3 interpolatedColor;
in vec2 fraguv;
out vec4 fragColor;

float flipflop(float step) {
    if (mod(step, 2.) == 1.) {
        return -1.;
    } else {
        return 1.;
    }
}

float rand(float seed) {
    return floor(fract(sin(seed * 11245.432)) * 2.) + 1.;
}
float colrand(float seed) {
    return fract(sin(seed * 15145.432));
}


void main() {
    vec2 uv = fraguv;
    uv = (uv * 2.) - 1.;
    float step = mod(floor(time/2.), 30.) + 1.;
    uv *= 0.25 * step;

    vec2 fc = fract(uv) * 2. - 1.;
    vec2 fi = floor(uv);
    float f = 0.;

    for (float i = 0.; i < 4.; i++){
    float s = sin(flipflop(rand(step )) * time + PI * i/2.) * 0.35;
    float c = cos(flipflop(step) * time + PI * i/2.) * 0.35;
    f += 0.012 / abs(length(fc + vec2(s, c)) - 0.6);
    }

	vec3 color = vec3(colrand(step * 500.) * f, colrand(fi.y + step * 200.) * f, colrand(fi.x + step * 200.) * f * 0.5);
	fragColor = vec4( color, 1. );
}
