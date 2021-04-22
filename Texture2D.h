#pragma once
#include <Windows.h>//needed for opengl
#include <gl/GL.h>//opengl
#include <gl/GLU.h>//OpenGL utilities
#include "GL\freeglut.h" //freeglut
#include <iostream>
#include <fstream>
#include <sstream>
class Texture2D
{
private:
	GLuint _ID; //texture ID
	int _width;
	int _height;
public:
	Texture2D();
	~Texture2D();
	bool Load(char* path, int width, int height);
	GLuint GetID() const { return _ID; }
	int GetWidth() const { return _width; }
	int GetHeight() const { return _height; }
};

