#pragma once
#include <Windows.h>//needed for opengl
#include <gl/GL.h>//opengl
#include <gl/GLU.h>//OpenGL utilities
#include "GL\freeglut.h" //freeglut
#include <iostream>
#include <sstream>
#define REFRESHRATE 16

class HelloGL
{
public:
	
	HelloGL(int argc, char* argv[]);

	~HelloGL(void);

	void Display();
	void DrawPolygon();
	void Update();

private:
	float rotation;
};

