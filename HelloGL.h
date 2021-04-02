#pragma once
#include <Windows.h>//needed for opengl
#include <gl/GL.h>//opengl
#include <gl/GLU.h>//OpenGL utilities
#include "GL\freeglut.h" //freeglut
#include <iostream>
#include <sstream>
#include "Structures.h"
#include "Cube.h"
#define REFRESHRATE 16

class HelloGL
{
public:

	HelloGL(int argc, char* argv[]);

	~HelloGL(void);

	void Display();
	void Update();
	void Keyboard(unsigned char key, int x, int y);

private:
	Camera* camera;
	Cube* cube;
};

