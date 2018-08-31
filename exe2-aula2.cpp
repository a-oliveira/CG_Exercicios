/*
  Name:        quad_transform.cpp
  Copyright:   Version 0.1
  Author:      Rodrigo Luis de Souza da Silva
  Edited:	   Bruno José Dembogurski
  Edited:      Andressa Silva de Oliveira
  Update:      30/08/2018
  Date:        16/09/2004
  Description: Transformations using of OpenGL commands
*/

#include <GL/glut.h>
#include<iostream>
using namespace std;

float angle       = 0, scale  = 1.0;
float temp1       = 0;
float temp2       = 1.0;
float xtrans      = 0, ytrans = 0, ztrans = 0;
float x           = 0, y = 0, z = 0;
int enableMenu    = 0;
float desiredFPS  = 15;
float var         = 0.0f;
float dir         = 1.0f;

void display(void);
void init (void);
void desenhaEixos();
void showMenu();
void mouse(int button, int state, int x, int y);
void idle(void);

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB);
   glutInitWindowSize (300, 300);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("hello");
   glutIdleFunc(idle);
   glutMouseFunc( mouse );
   init ();
   printf("Posicione as janelas e clique na janela do OpenGL para habilitar o menu.\n");
   glutDisplayFunc(display);
   glutMainLoop();

   return 0;
}

// Mouse callback
void mouse(int button, int state, int x, int y)
{
   if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
      enableMenu = 1;
   else
      enableMenu = 0;
}

void showMenu()
{
   int op;
   system("cls");
   printf("\n=== MENU ===");
   printf("\n1 - Translacao");
   printf("\n2 - Rotacao");
   printf("\n3 - Escala");
   printf("\n4 - Sair");
   printf("\nOpcao: ");

   scanf("%d", &op);
   switch(op)
   {
      case 1:
         printf("\n\nInforme o vetor de translacao (entre -100.0 e 100.0)");
         printf("\nX : ");
         scanf("%f", &x);
         printf("Y : ");
         scanf("%f", &y);
      break;
      case 2:
         printf("\n\nInforme o angulo de rotacao (em graus): ");
         scanf("%f", &temp1);
      break;
      case 3:
         printf("\n\nInforme o fator de escala: ");
         scanf("%f", &temp2);
      break;
      case 4:
         exit(1);
      break;
      default:
         printf("\n\nOpcao invalida\n\n");
      break;
   }
}

void desenhaEixos()
{
   glColor3f (0.0, 1.0, 0.0);
   glBegin(GL_LINES);
      glVertex2f (0.0, -100.0);
      glVertex2f (0.0, 100.0);
      glVertex2f (-100.0, 0.0);
      glVertex2f (100.0, 0.0);
   glEnd();

}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();
   desenhaEixos();

   glColor3f (1.0, 0.0, 0.0);
   glPushMatrix();
      glTranslatef(xtrans, ytrans, 0.0);
      glRotatef(angle, 0.0, 0.0, 1.0);
      glScalef(scale, scale, scale);
      glutWireCube(10);
   glPopMatrix();
   
   glutSwapBuffers ();
   if(enableMenu) showMenu();

   
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
void init (void)
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
