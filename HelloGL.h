#pragma once
#include <Windows.h>//needed for opengl
#include <gl/GL.h>//opengl
#include <gl/GLU.h>//OpenGL utilities
#include "GL\freeglut.h" //freeglut
#include <iostream>
#include <sstream>
#define REFRESHRATE 16
struct Vector3
{
	float x;
	float y;
	float z;
};
struct Camera
{
	Vector3 eye;
	Vector3 centre;
	Vector3 up;
};
struct Color
{
	GLfloat r, g, b;
};
struct Vertex
{
	GLfloat x, y, z;
};

class HelloGL
{
public:

	HelloGL(int argc, char* argv[]);

	~HelloGL(void);

	void Display();
	void DrawPolygon();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	void DrawCube();
	void DrawCubeArray();
	void DrawIndexedCube();
	void DrawCubeArrayAlt();
	void DrawIndexedCubeAlt();
private:
	float rotation;
	Camera* camera;
	float camerazoom;
	static Vertex vertices[];
	static Color colors[];
	static Vertex indexedVertices[];
	static Color indexedColors[];
	static GLushort indices[];
};

