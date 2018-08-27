#include <iostream>
#include <GL/glut.h>
using namespace std;

int func = 0;
// void desenha(void (* poligono)(void)); - passa função como parâmetro
void desenha(void);
void plano (void);
void trianguloA(void);
void trianguloB(void);
void trianguloC(void);
void poligonoD(void);
void inicia(void);
void teclado(unsigned char tecla, int x, int y);

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Triangles");
	inicia();
	glutKeyboardFunc(teclado);
	glutDisplayFunc(desenha);
	glutMainLoop();

	cout << "Pressione ESC para fechar" << endl;
}

void inicia(void)
{
	// selecionar cor de fundo (preto)
   glClearColor (0.0, 0.0, 0.0, 0.0);

   // inicializar sistema de vizualização
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();          
}

void desenha(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	plano();
	if 		(func == 1) trianguloA();
	else if (func == 2) trianguloB();
	else if (func == 3) trianguloC();
	else if (func == 4) poligonoD();
    glutSwapBuffers();

}

void plano(void)
{
	glBegin(GL_LINES);
		glColor3f (0.5, 0.0, 1.0);
		glVertex3f (-1.0, 0.0, 0.5);
		glVertex3f (1.0, 0.0, 0.5);

		glColor3f (0.5, 0.7, 0.2);
		glVertex3f (0.0, -1.0, 0.5);
		glVertex3f (0.0, 1.0, 0.5);
    glEnd();
}

void trianguloA (void)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);
		glColor3f(1.0,0.0,0.0);
		glVertex3f(0.0, 0.0, 0.5);

		glColor3f(0.0,1.0,0.0);
		glVertex3f(1.0,0.0,0.5);

		glColor3f(0.0,0.0,1.0);
		glVertex3f(0.5,0.5,0.5);
	glEnd();
	
}

void trianguloB (void)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLES);
		glColor3f(1.0,0.0,0.0);
		glVertex3f(0.0, 0.0, 0.5);

		glColor3f(0.0,1.0,0.0);
		glVertex3f(1.0,0.0,0.5);

		glColor3f(0.0,0.0,1.0);
		glVertex3f(0.5,0.5,0.5);
	glEnd();
	
}

void trianguloC (void)
{
	glBegin(GL_TRIANGLES);
		glColor3f(1.0,0.0,0.0);
		glVertex3f(0.0, 0.0, 0.5);

		glColor3f(0.0,1.0,0.0);
		glVertex3f(-1.0,0.0,0.5);

		glColor3f(0.0,0.0,1.0);
		glVertex3f(-0.5,-0.5,0.5);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glBegin(GL_TRIANGLES);
		glColor3f(1.0,0.0,0.0);
		glVertex3f(0.0, 0.0, 0.5);

		glColor3f(0.0,1.0,0.0);
		glVertex3f(1.0,0.0,0.5);

		glColor3f(0.0,0.0,1.0);
		glVertex3f(0.5,0.5,0.5);
	glEnd();
}

void poligonoD(void)
{
	glBegin(GL_LINE_STRIP);
		glColor3f (0.0, 1.0, 1.0);

		glVertex3f(0.25, 0.5, 0.5);
		glVertex3f(0.5, 0.0, 0.5);

		glVertex3f(0.25, -0.5, 0.5);
		glVertex3f(-0.25, -0.5, 0.5);

		glVertex3f(-0.5, 0.0, 0.5);
		glVertex3f(-0.25, 0.5, 0.5);

	glEnd();
}

void teclado(unsigned char tecla, int x, int y)
{

	switch(tecla)
	{
		case 27:
			exit(0);
			break;
		case 'a':
			func = 1;
			break;
		case 'b':
			func = 2;
			break;
		case 'c':
			func = 3;
			break;
		case 'd':
			func = 4;
			break;
		default:
			cout << "Opcao invalida!" << endl;
			break;
	}
	glutPostRedisplay();
}