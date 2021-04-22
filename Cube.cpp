#include "Cube.h"
Vertex* Cube::indexedVertices = nullptr; 
//Color* Cube::indexedColors = nullptr;
GLushort* Cube::indices = nullptr;
int Cube::numVertices = 0;
//int Cube::numColors = 0;
int Cube::numIndices = 0;
Cube::Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z) :  SceneObject(mesh, texture)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
	_rotation = 1.0f;
	_FlyingSpeed = 0; //(rand() % 2 + 1);
	_texture = texture;
}
Cube::~Cube() { //destructor
}
void Cube::Update() {
	_rotation += (rand() % 7);
	if (_rotation == 360)
		_rotation = 0;
	_position.z += _FlyingSpeed;
	if (_position.z == 3)
		_position.z = -100;
}
void Cube::Draw()
{
	if (_mesh->Vertices != nullptr && /*_mesh->Colors != nullptr &&*/ _mesh->Indices != nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnable(GL_NORMAL_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glNormalPointer(GL_FLOAT, 0, _mesh->Normal);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);
		Materials();
		glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->Ambient.x));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->Ambient.x));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->Ambient.x));
		glPushMatrix();
			glTranslatef(_position.x, _position.y, _position.z); //translate before rotate
			glRotatef(_rotation, 1.0f, 1.0f, 1.0f);
			glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT,_mesh->Indices);
		glPopMatrix();
		glDisable(GL_NORMAL_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
}
void Cube::Materials() {
	_material = new Material();
	_material->Ambient.x = 0.8; _material->Ambient.y = 0.05; _material->Ambient.z = 0.05; //x = red, y = blue, z = green
	_material->Ambient.w = 1.0;
	_material->Diffuse.x = 0.8; _material->Diffuse.y = 0.05; _material->Diffuse.z = 0.05;
	_material->Diffuse.w = 1.0;
	_material->Specular.x = 1.0; _material->Specular.y = 1.0; _material->Specular.z = 1.0;
	_material->Specular.w = 1.0;
	_material->Shininess = 100.0f;
}