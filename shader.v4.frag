#version 330 core

in vec3 color;
in vec3 pos;
in vec3 norm;
in vec2 texCoord;

uniform sampler2D colorTex;
uniform sampler2D specularTex;
uniform sampler2D emiTex;

out vec4 outColor;

//Variables uniformes
//Prop obj
vec3 Ka = vec3(1,0,0);
vec3 Kd =  vec3(1,0,0);
vec3 Ks = vec3(1);
vec3 Ke;
float n = 100.;

//Prop fuentes de luz
vec3 Ia = vec3(0.1); //Luz ambiental

//Prop fuente de luz 1
vec3 Il = vec3(1.0); //Intensidad de la luz 1
vec3 pl = vec3(0.0); //Posicion de la luz 2 en el sistema de coordenadas de la camara

//Prop fuente de luz 2
vec3 Il2 = vec3(1.0, 0.3, 0.3);
vec3 pl2 = vec3(-3.0); //Esta en el sistema de coordenadas de la camara


//Variables locales
vec3 N; //N en coordenadas de la camara
vec3 p;



vec3 shade()
{
	vec3 c = vec3(0);
	
	vec3 Iamb = Ia * Ka;
	c += Iamb;

	N =normalize(N);
	//Luz difusa de la primera fuente
	vec3 L = normalize(pl-p);
	vec3 Idiff = Il * Kd * max(0,dot(N,L));
	c += Idiff;
	 
	//Luz difusa de la segunda fuente 
    vec3 L2 = normalize(pl2 - p);
    vec3 Idiff2 = Il2 * Kd * max(0, dot(N, L2));
    c += Idiff2;


	vec3 R = normalize(reflect(-L,N));
	vec3 V = normalize(-p);
	vec3 Ispc = Il * Ks * pow(max(0,dot(R,V)),n);

	c+= Ispc;

	c += Ke;

	return c;
}




void main()
{
	Ke = texture(emiTex,texCoord).rgb;
	Kd = texture(colorTex,texCoord).rgb;
	Ka = Kd;
	Ks = texture(specularTex,texCoord).rgb;
	
	N = norm;
	p = pos;
	outColor = vec4 (shade(),1.0); 
}
