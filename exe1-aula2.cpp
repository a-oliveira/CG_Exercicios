#include <GL/glut.h>
#include <iostream>
using namespace std;


float angulo = 0, escala = 1.0;
float posx = 0;
float posy = 0;
float posz = 0;

void desenha(void);
void inicia(void);
void plano(void);
void teclado(unsigned char tecla, int x, int y);
void especiais(int tecla, int x, int y);

//void mouse(int botao, int estado, int posX, int posY);

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB);
	glutInitWindowSize(640,640);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Transformacoes 2D");

	inicia();
	glutKeyboardFunc(teclado);
	glutSpecialFunc(especiais);
	glutDisplayFunc(desenha);

	glutMainLoop();

	return 0;
}

void inicia(void)
{
   // selecionar cor de fundo (preto)
   glClearColor (0.0, 0.0, 0.0, 0.0);

   // inicializar sistema de viz.
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

}

void desenha(void)
{
	glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	plano();

	glColor3f(1.0,1.0,1.0);

	glPushMatrix();
	    glTranslatef(posx, posy, 0.0);
	    glRotatef(angulo, 0.0, 0.0, 1.0);
	    glScalef(escala, escala, escala);
	    glutWireCube(10);
	glPopMatrix();

	glutSwapBuffers();
	glutPostRedisplay();
}

void plano(void)
{
	glColor3f (0.8, 0.2, 0.65);
	glBegin(GL_LINES);
		glVertex2f (0.0, -100.0);
		glVertex2f (0.0, 100.0);
		glVertex2f (-100.0, 0.0);
		glVertex2f (100.0, 0.0);
   glEnd();
}

void teclado(unsigned char tecla, int x, int y)
{
	switch (tecla)
	{
		case '+':
			escala += 1;
			break;

		case '-':
			escala -= 1;
			break;

		case 'r':
			angulo -= 10;
			break;

		case 'R':
			angulo += 10;
			break;

		case 27:
			exit(0);
			break;

		default:
			cout << "Opcao invalida!" << endl;
	}
	glutPostRedisplay();
}

void especiais(int tecla, int x, int y)
{
	switch (tecla)
	{
		case GLUT_KEY_LEFT :
			//cout << posx << endl;
			if((int)posx == -100) posx = 100;
			else posx-=10;
			break;

		case GLUT_KEY_RIGHT :
			if((int)posx == 100) posx = -100;
			else posx +=10;
			break;

		case GLUT_KEY_UP :
			if((int)posy == 100) posy = -100;
			else posy+=10;
			break;

		case GLUT_KEY_DOWN :
			if((int)posy == -100) posy = 100;
			else posy-=10;
			break;

		case 27:
			exit(0);
			break;

		default:
			cout << "Opcao invalida!" << endl;
	}
	glutPostRedisplay();
}

