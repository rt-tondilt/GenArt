#version 400
uniform float time;

in vec3 interpolatedColor;
in vec2 fraguv;
out vec4 fragColor;

void main(void) {
    vec2 uv = fraguv;

    uv *= 5.;
    if (fract(uv.y * 0.5) > 0.5) {
        uv.x += fract(time);
    } else {
        uv.x -= fract(time);
    }
    uv = fract(uv);//tile


    fragColor = vec4(uv, 0.0, 1.0);

}
