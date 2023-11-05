#version 330 core

in vec2 vtexcoord;
out vec4 outColor;

uniform sampler2D colorTex;

void main()
{
   
    if (pow(vtexcoord.x - 0.5, 2) + pow(vtexcoord.y - 0.5, 2) > 0.2) {
        discard;
    }
	outColor = texture(colorTex, vtexcoord);
	//outColor = vec4(vtextcoord, 1,1);
	
}
