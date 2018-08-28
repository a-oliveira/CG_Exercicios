#include <iostream>
#include <GL/glut.h>
#include <GL/glui.h>
#include <math.h>

void desenha 	(void);
void inicia 	(void);
void plano 		(void);
void teclado 	(unsigned char key, int x, int y);

void triangulo	(void);
void poligono 	(void);

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Viewports"); 
	inicia();
	glutDisplayFunc(desenha);
	glutKeyboardFunc(teclado);
	glutMainLoop();
}
void inicia (void)
{
   glClearColor(0.0,0.0, 0.0, 0.0);
   glShadeModel(GL_SMOOTH);
}

void desenha(void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// canto inferior esquerdo
	glViewport ((int) 10, (int) 10, (int) 210, (int) 210);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glOrtho(-10.0, 1.0, -10.0, 1.0, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	plano();
	triangulo();

	// canto inferior direito
	glViewport ((int) 250, (int) 10, (int) 210, (int) 210);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glOrtho(-1.0, 10.0, 1.0, -10.0, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	plano();
	triangulo();

	// canto superior direito
	glViewport ((int) 240, (int) 240, (int) 210, (int) 210);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glOrtho(-1.0, 10.0, -1.0, 10.0, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	plano();
	triangulo();

	// canto superior esquerdo
	glViewport ((int) 10, (int) 240, (int) 210, (int) 210);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glOrtho(-10.0, 10.0, -10.0, 10.0, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	plano();
	triangulo();

	glutSwapBuffers();
	glutPostRedisplay();
}
void plano(void)
{
	glBegin(GL_LINES);

      glColor3f (1.0, 0.0, 0.0);
      glVertex3f(-10.0, 0.0, 0.0);
      glVertex3f( 10.0, 0.0, 0.0);

      glColor3f ( 0.0,  1.0, 0.0);
      glVertex3f(0.0, -10.0, 0.0);
      glVertex3f(0.0,  10.0, 0.0);
   glEnd();
}

void triangulo(void)
{
	glColor3f(1.0, 1.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // triângulo preenchido

	glBegin(GL_POLYGON);
	    glVertex3f(2.0, 2.0, 0.0);
	    glVertex3f(8.0, 2.0, 0.0);
	    glVertex3f(2.0, 8.0, 0.0);
	glEnd();

	glColor3f(0.6, 0.0, 1.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // triângulo vazado

	glBegin(GL_POLYGON);
	    glVertex3f(2.0, -2.0, 0.0);
	    glVertex3f(8.0, -2.0, 0.0);
	    glVertex3f(2.0, -8.0, 0.0);
	glEnd();

	glBegin(GL_LINE_STRIP);
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(-2.0, -2.0, 0.0);
		glVertex3f(-8.0, -2.0, 0.0);
		glVertex3f(-2.0, -8.0, 0.0);
		glVertex3f(-8.0, -8.0, 0.0);

	glEnd();
}
void teclado(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27:
			exit(0);
			break;
	}

	glutPostRedisplay();
}