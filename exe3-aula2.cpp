#include <GL/glut.h>
#include <iostream>
using namespace std;

float xtrans      = 0, ytrans = 0, ztrans = 0;
float x           = 0, y = 0, z = 0;
float desiredFPS  = 15;
float var         = 0.0f;
float dir         = 1.0f;
int largura = 400, altura = 400;
int qtd           = 8;
int R = 1;
int G = 1;
int B = 1;

void desenha (void);
void inicia  (void);
void tabuleiro ();
void showMenu();
void trocaCor();
//void mouse(int button, int state, int x, int y);
void idle(void);

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB);
   glutInitWindowSize (largura, altura);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Tabuleiro");
   glutIdleFunc(idle);
  // glutMouseFunc(mouse);

   inicia ();
   glutDisplayFunc(desenha);

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
void desenha (void)
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
 
  glutSwapBuffers();
}
void idle (void)
{
    /*float t, desiredFrameTime, frameTime;
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

     /*
     *UPDATE ANIMATION VARIABLES
     

      if(xtrans < x) xtrans += dir * 1;
      else if (xtrans > x) xtrans += dir * -1;

      if(ytrans < y) ytrans += dir * 1;
      else if (ytrans > y) ytrans += dir * -1;

      if(angle < temp1) angle += dir * 1;
      else if (angle > temp1) angle += dir * -1;

      if(scale < temp2) scale += dir * 1;
      else if (scale > temp2) scale += dir * -1; 

      glutPostRedisplay(); 
    /* Update tLast for next time, using static local variable 
    tLast = t;*/
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