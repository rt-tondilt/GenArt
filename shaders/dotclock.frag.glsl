#version 400
#extension GL_ARB_explicit_uniform_location : enable

const float PI = 3.1415926535897932384626433832795;


layout(location = 2) uniform float time;
in vec3 interpolatedColor;
in vec2 fraguv;
out vec4 fragColor;


void main( void ) {
	vec2 pos = fraguv * 2. - 1.; // -1 to 1
	vec2 pos2 = pos, pos3 = pos;
	float col=0.0, col2=0.0, col3=0.0;

	for(int i=0;i<50;i++){
		pos += vec2(sin(time)/sin(time)*(0.1*sin(time)), cos(time)/50.);
		pos2 += vec2(cos(time)/10.0, sin(time)/50.);
		pos3 += vec2(tan(time*0.5)*0.05, sin(time)*0.05);

		col+=0.002/distance(vec2(0.0), pos);
		col2 += 0.002/distance(vec2(0.0), pos2);
		col3 += 0.002/distance(vec2(0.0), pos3);
	}

	vec3 color=vec3(col, col2, col3);

	fragColor=vec4(color, 1.0);
}
