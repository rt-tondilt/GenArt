#version 400
#extension GL_ARB_explicit_uniform_location : enable

layout (location = 2) uniform float time;

in vec3 interpolatedColor;
in vec2 fraguv;
out vec4 fragColor;

#define PI 3.141592653
void main(void) {
    vec2 uv = fraguv;
    uv = uv * 2. - 1.;//remap

    float dist = length( abs( uv ) - 0.5); // distance from "center"
    float distfieldred = fract( dist * abs( sin( time * 0.5 + PI * .5 ) ) * 20.); // create distance field
    float distfieldgreen = fract( dist * abs( sin( time * 0.2 )) * 20.); // create distance field
    float distfieldblue = fract( dist * abs( sin( time * 0.9 + PI * 0.3)) * 10.); // create distance field
    fragColor = vec4( vec3(distfieldred, distfieldgreen, distfieldblue), 1. );
}

