#include "HelloGL.h"
#include "GLUTCallbacks.h"


HelloGL::HelloGL(int argc, char* argv[])
{
	rotation = 0.0f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(400, 100);
	glutCreateWindow("Window Title");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutMainLoop();
}
void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT); //CLEARS THE SCENE
	HelloGL::DrawPolygon();
	glFlush(); //Flushes the scene drawn to the graphics card
	glutSwapBuffers();
}
void HelloGL::Update()
{
	glutPostRedisplay();
	rotation += 0.5f;
	if (rotation >= 360.0f)
		rotation = 0.0f;
	Sleep(10);
}
void HelloGL::DrawPolygon()
{
	glPushMatrix();
	{
		glRotatef(rotation, 0.0f, 0.0f, 45.0f);
		glBegin(GL_POLYGON);
		{
			glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
			//draw bottom square
			glRotatef(rotation, 0.0f, 0.0f, 45.0f);
			glVertex2f(-0.75, -0.2); //defines the first point of the polygon in the top left
			glVertex2f(0.75, -0.2); //second point is top right
			glVertex2f(0.75, -0.5); //Third point is bottom right
			glVertex2f(-0.75, -0.5); //fourth point is bottom left
			glEnd();
		}
	}
	{
		glRotatef(rotation, 0.0f, 0.0f, 45.0f);
		glBegin(GL_POLYGON);
		{
			glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
			//draw top square

			glVertex2f(-0.75, 0.2); //defines the first point of the polygon in the bottom left
			glVertex2f(0.75, 0.2); //second point is bottom right
			glVertex2f(0.75, 0.5); //Third point is top right
			glVertex2f(-0.75, 0.5); //fourth point is top left
			glEnd();
		}
	}
	glPopMatrix();
}
HelloGL::~HelloGL(void)
{

}
