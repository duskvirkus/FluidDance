#version 150

uniform sampler2DRect tex0;
uniform vec2 u_window;
uniform float u_section;
uniform float u_offset;

in vec2 v_texcoord;
out vec4 color;

float createMask(float section, float offset, float coordCompoent) {
	// section of the screen, 1/2 solid, 1/2 gradient, ex. 4.0 is 1/4 of the screen
	// offset, range -0.5 to 0.5

    float amt = coordCompoent + (offset - (1.0 / (section * 2.0)));
    
    float mask;

    if (amt < 0.5) {
        mask = step(0.5, (section * amt) - ((section / 2.0) - 1.0)); // bottom
    } else {
        mask = (section * (1.0 - amt)) - ((section / 2.0) - 1.0); // top
    }

	return mask;
}

void main()
{
	float y = gl_FragCoord.y / u_window.y;

    vec4 tex = texture(tex0, v_texcoord);

	color = tex * vec4(vec3(1.0), createMask(u_section, u_offset, y));

}