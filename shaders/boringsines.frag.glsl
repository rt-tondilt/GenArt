#version 400
#extension GL_ARB_explicit_uniform_location : enable

const float PI = 3.1415926535897932384626433832795;
const vec3 BLUE = vec3(0.15, 0.34, 0.67);
const vec3 MAGENTA = vec3(0.75, 0.1, 0.54);


layout(location = 2) uniform float time;
in vec3 interpolatedColor;
in vec2 fraguv;
out vec4 fragColor;

void main(){
    vec2 uv = fraguv;
	uv.x *= uv.x * 3.;
	uv = fract(uv);
	uv = uv * 2. * PI - PI;//make tiles from -uvi to uvi
	uv.y *= 0.6;

	vec3 line = vec3(0.0);
	for (float i = -1.; i < 1.; i+= 0.3) {
		float offset = i * 200. * PI / 100.;
		line += (0.009/abs(uv.y + sin(uv.x + time * offset) + i * 0.8)) * MAGENTA;
		line += (0.009/abs(uv.y + cos(uv.x + time * offset + time) + i * 0.5)) * BLUE;
	}

    fragColor = vec4(line, 1.0);
}
