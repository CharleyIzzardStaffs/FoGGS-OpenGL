#include "HelloGL.h"
#include "GLUTCallbacks.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(400, 100);
	glutCreateWindow("Window Title");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800); 	// Set the viewport to be the entire window
	gluPerspective(45, 1, 0, 1000);	// Set the correct perspective.
	glMatrixMode(GL_MODELVIEW);
	camera = new Camera();
	cube;
	/*camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;*/
	camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -5.0f;
	camera->centre.x = 0.0f; camera->centre.y = 0.0f; camera->centre.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glutMainLoop(); //!!Make sure is always loaded last!!
}
void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT); //CLEARS THE SCENE
	cube->Draw();
	glFlush(); //Flushes the scene drawn to the graphics card
	glutSwapBuffers();

}
void HelloGL::Update()
{
	glLoadIdentity();
	glutPostRedisplay();
	cube->Update();
	//rotation += 0.5f;
	/*if (camerazoom >= 360.0f)
		camerazoom = 0.0f;*/
		//Sleep(10);
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->centre.x, camera->centre.y, camera->centre.z, camera->up.x, camera->up.y, camera->up.z);
}
//
//AAAAAAAAAAAAAAAAAAAAA
void HelloGL::Keyboard(unsigned char key, int x, int y)
{

}
HelloGL::~HelloGL(void)
{
	/*HelloGL::camera;*/
}
