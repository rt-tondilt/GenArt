#version 400
#extension GL_ARB_explicit_uniform_location : enable

#define PI 3.141592

layout(location = 2) uniform float time;
in vec3 interpolatedColor;
in vec2 fraguv;
out vec4 fragColor;
//speed is in teeth/rotation
float gear(in vec2 _uv, in vec2 center, in float size, in float teeth, in float teethsize, in float speed) {
    _uv = center - _uv;
	float r = length(_uv)*3.0; //radius
    float a = atan(_uv.y,_uv.x);//  this whole function gets "wrapped around" the center (cos(angle + (phaseshift * speed)))
    float f = smoothstep(-.8, .7, cos(a*teeth + (floor(time) + pow(fract(time), 5.)) * 2 * PI * speed)) * 0.2 * teethsize * size + 0.5 * size;
    return 1.-smoothstep(f, f+0.02, r);
}

void main(){
    vec2 uv = fraguv;
    vec3 color = vec3(0.0);

    vec2 pos = vec2(0.5)-uv;


    float g1 = gear(uv, vec2(0.350,0.610), 1., 10., 1., 1.);
    float g2 = gear(uv, vec2(0.670,0.410), 0.752, 7., 1.,  -1.);
    float g3 = gear(uv, vec2(0.540,0.180), 0.352, 5., 2.392,  1.);
    float g4 = gear(uv, vec2(0.660,0.990), 1.336, 15., 0.700, -1.);

    color = vec3(g1 + g2 + g3 + g4);

    fragColor = vec4(color, 1.0);
}




