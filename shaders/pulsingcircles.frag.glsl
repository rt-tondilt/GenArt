#version 400
uniform float time;

in vec3 interpolatedColor;
in vec2 fraguv;
out vec4 fragColor;

#define PI 3.141592653

float circle( in vec2 _uv, in float radius, in vec2 center ) {
    vec2 dist = _uv - center;
    return 1.-smoothstep(radius-(radius*0.01),
                 radius+(radius*0.01),
                 dot(dist,dist)*4.0);
}

void main(void) {
    vec2 uv = fraguv;

    float c1 = circle(
        uv,
        0.3 + pow(abs(sin(time)), 3.) * 0.8,
        vec2(0.800,0.820)
    );

    float c2 = circle(
        uv,
        (0.3 + pow( abs( sin( PI * 0.5 + time)), 4.)) * 0.076,
        vec2(0.230,0.550)
    );

    float c3 = circle(
        uv,
        (0.2 + pow( abs( sin( PI + time)), 6.)) * 0.2,
        vec2(0.300,0.130)
    );

    float c4 = circle(
        uv,
        (0.2 + pow( abs( sin( PI * 0.5 + time)), 3.)) * 0.2, // size function
        vec2(0.740,0.240)
    );

    float c5 = circle(
        uv,
        (0.2 + pow( abs( sin( PI * 0.5 + time)), 2.)) * 0.328,
        vec2(0.630,0.540)
    );
    float c6 = circle(
        uv,
        (0.6 + pow( abs( sin( PI * 0.5 + time)), 3.)) * 0.704,
        vec2(0.060,0.920)
    );

	vec3 color = vec3(c4 + c6, c2 + c5, c3 + c1);

    fragColor = vec4(color, 1.0);
}

