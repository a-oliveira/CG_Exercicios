#include <iostream>
#include <GL/glut.h>
#include "GL/glui.h"
#include <math.h>

void display 	(void);
void init 		(void);
void plano 		(void);

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Viewports"); 
	glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}