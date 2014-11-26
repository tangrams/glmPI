uniform mat4 u_modelViewProj;
uniform float u_time;

varying vec4 v_color;
varying vec3 v_normal;
varying vec2 v_texcoord;

void main(void) {
	vec4 color = v_color;
  	gl_FragColor = color;
}