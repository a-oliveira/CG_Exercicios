#include <GL/glut.h>
#include <iostream>
using namespace std;

int R             = 1;
int G             = 1;
int B             = 1;
float desiredFPS  = 60;
float var         = 0.0f;
float dir         = 1.0f;
int qtd           = 8;
int largura       = 400, altura = 400;
float xtrans      = (largura/qtd)/2, ytrans = (altura/qtd)/2, ztrans = 0;
int temp1         = xtrans, temp2 = ytrans;


void tabuleiro 	(void);
void peca 	 	(void);
void inicia  	(void);
void showMenu();
void trocaCor();
void mouse(int button, int state, int x, int y);
void idle(void);

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB);
   glutInitWindowSize (largura, altura);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Tabuleiro");
   glutIdleFunc(idle);
   glutMouseFunc(mouse);

   inicia ();
   glutDisplayFunc(tabuleiro);

   glutMainLoop();

   return 0;
}

void inicia(void)
{
  // selecionar cor de fundo (preto)
   glClearColor (0.9, 0.2, 0.7, 0.0);

   // inicializar sistema de viz.
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 400.0, 0.0, 400.0, 0.0, 400.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}
void tabuleiro (void)
{
  glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  int m = largura/qtd;
  int n = altura/qtd;

  for (int i = 0; i < largura; i += m)
  {
    for (int j = 0; j < altura; j += n)
    {
        glColor3f(R,G,B);
        glBegin(GL_QUADS);
          glVertex2f(i,j);
          glVertex2f(i+m,j);
          glVertex2f(i+m,j+n);
          glVertex2f(i,j+n);
        glEnd();
        trocaCor();  
    }
    
    trocaCor();
  }
 
  peca();
  glutSwapBuffers();
}
void peca (void)
{
	glPushMatrix();
		glColor3f(1.0,0,0);
		glTranslatef(xtrans, ytrans, ztrans);
		glutSolidSphere(((largura/qtd)/2)-1, 16, 16);
	glPopMatrix();
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	int m = largura/qtd;
	int n = altura/qtd;
	if( button == GLUT_LEFT_BUTTON and state == GLUT_DOWN)
  {
      /*x/m force o num de "colunas" que devem ser puladas
      +25 define que a esfera será posicionada no meio. */
    	temp1 = ((int) x/m * m) + 25;

      /* análogo ao xtrans, com a ressalva de altura - y pq
      a orientação da altura com relação ao mouse é diferente */
    	temp2 = ((int) (altura - y)/n * n) + 25;
  }

}
void idle (void)
{
    float t, desiredFrameTime, frameTime;
    static float tLast = 0.0;
    // Get elapsed time
    t = glutGet(GLUT_ELAPSED_TIME);
    // convert milliseconds to seconds
    t /= 1000.0;

    // Calculate frame time
    frameTime = t - tLast;
    // Calculate desired frame time
    desiredFrameTime = 1.0 / (float) (desiredFPS);

    // Check if the desired frame time was achieved. If not, skip animation.
    if( frameTime <= desiredFrameTime)
        return;

     
     //UPDATE ANIMATION VARIABLES

      if(xtrans < temp1) xtrans += dir * 1;
      else if (xtrans > temp1) xtrans += dir * -1;

      if(ytrans < temp2) ytrans += dir * 1;
      else if (ytrans > temp2) ytrans += dir * -1;

      glutPostRedisplay(); 

    /* Update tLast for next time, using static local variable */
    tLast = t;
}

void trocaCor()
{

  if(R == 1 and G == 1 and B == 1)
  {
    R = 0;
    G = 0;
    B = 0;
  }

  else
  {
    R = 1;
    G = 1;
    B = 1;
  }
}