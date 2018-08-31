#include <GL/glut.h>
#include <iostream>
using namespace std;

float xtrans      = 0, ytrans = 0, ztrans = 0;
float x           = 0, y = 0, z = 0;
float desiredFPS  = 15;
float var         = 0.0f;
float dir         = 1.0f;

void desenha (void);
void inicia  (void);
void plano ();
void showMenu();
void mouse(int button, int state, int x, int y);
void idle(void);

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB);
   glutInitWindowSize (300, 300);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Tabuleiro");
   glutIdleFunc(idle);
   glutMouseFunc(mouse);

   inicia ();
   glutDisplayFunc(desenha);


   glutMainLoop();

   return 0;
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

     /*
     *UPDATE ANIMATION VARIABLES
     */

      if(xtrans < x) xtrans += dir * 1;
      else if (xtrans > x) xtrans += dir * -1;

      if(ytrans < y) ytrans += dir * 1;
      else if (ytrans > y) ytrans += dir * -1;

      if(angle < temp1) angle += dir * 1;
      else if (angle > temp1) angle += dir * -1;

      if(scale < temp2) scale += dir * 1;
      else if (scale > temp2) scale += dir * -1; 

      glutPostRedisplay(); 
    /* Update tLast for next time, using static local variable */
    tLast = t;
}