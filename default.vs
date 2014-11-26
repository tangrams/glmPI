uniform mat4 u_modelViewProj;
uniform float u_time;

attribute vec4 a_position;
attribute vec4 a_color;
attribute vec3 a_normal;
attribute vec2 a_texcoord;

varying vec4 v_color;
varying vec3 v_normal;
varying vec2 v_texcoord;

void main() {
  	v_normal = normalize(a_normal);
  	v_texcoord = a_texcoord;
	v_color = a_color;
  	gl_Position = a_position;
  	// gl_Position = u_modelViewProj * a_position;
}
