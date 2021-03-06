#pragma once
#include <Windows.h> // required for opengl on windows
#include <gl/GL.h> // Opengl
#include <gl/GLU.h> // opengl utilities
#include "GL\freeglut.h" // freeglut library
#include "Structures.h"
#include "SceneObject.h"
#include "fstream"
#include "iostream"
#include "Texture2D.h"

class Cube : public SceneObject {
private:
	static Vertex* indexedVertices;
	//static Color* indexedColors;
	static GLushort* indices;
	static int numVertices, numIndices;
	GLfloat _rotation;
	Vector3 _position;
	GLfloat _FlyingSpeed;
public:
	Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	~Cube();
	//Mesh* _mesh;
	void Draw();
	void Update();
	void Materials();
	Material* _material;
};