#version 400
#extension GL_ARB_explicit_uniform_location : enable

#define PI 3.141592

layout(location = 2) uniform float time;
in vec3 interpolatedColor;
in vec2 fraguv;
out vec4 fragColor;

// return
float rand(in vec2 _uv) {
    return fract(sin(dot(_uv.xy, vec2(67.325,55.1566))) * 500001.2415);
}

vec2 pattern(in vec2 _uv, in float rnd) {
    rnd = fract((( rnd - 0.5 ) * 2.));
    if (rnd > 0.75) {
        _uv = 1. - _uv; // mirror across diag
    } else if (rnd > 0.5) {
        _uv = vec2(1. - _uv.x, _uv.y);// mirror across horizontal
    } else if (rnd > 0.25) {
        _uv = vec2(_uv.x, 1. - _uv.y);// mirror across vertical
    }
    return _uv;
}

void main(){
    vec2 uv = fraguv;
    uv *= 12.;
    uv = (uv - 3.) * (abs(sin(time)) + 1.);
    uv.x += time * 8.;
    uv.y += sin(time) * 3;

    vec2 ipos = floor(uv);
    vec2 fpos = fract(uv);
    vec2 tile = pattern(fpos, rand(ipos));

    float color = step(tile.x, rand(vec2(abs(sin(time)*0.00000002)))) + rand(uv * sin(time));
    color *= step(tile.y, rand(vec2(abs(cos(time)*0.00000002))));

    fragColor = vec4(color, 0., rand(ipos) * color *  0.5, 1.0);
}




