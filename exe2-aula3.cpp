#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

float shoulder = 0.0f, elbow = 0.0f, wrist = 0.0f;
float temp1 = 80, temp2 = 110;

int selected = 1;

void init(void)
{
	printf("Pressione as setas direita e esquerda para mover o braco.\n");
	printf("Selecione as teclas 1 e 2 para escolher o segmento a ser movido.\n");
	printf("Pressione ESC para sair.\n");

   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);

   glEnable(GL_LIGHT0);                   // habilita luz 0
   glEnable(GL_COLOR_MATERIAL);           // Utiliza cor do objeto como material
   glColorMaterial(GL_FRONT, GL_DIFFUSE);

   glEnable(GL_LIGHTING);                 // Habilita luz
   glEnable(GL_DEPTH_TEST);               // Habilita Z-buffer
   glEnable(GL_CULL_FACE);                // Habilita Backface-Culling
}

void desenhaEixos()
{
	glDisable(GL_LIGHTING);
   glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(10.0f, 0.0f, 0.0f);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 10.0f, 0.0f);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 10.0f);
   glEnd();
	glEnable(GL_LIGHTING);
}
void garra (void)
{
	/* Transformações são cumulativas
	os valores do segundo cubo levam
	em consideração os do primeiro */

    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(1.2,0.8, 0.3);
    glRotatef(70.0, 0.0, 0.0, 1.0); // rotaciona em relação à origem

    /* Base da garra */
    glPushMatrix();
        glScalef(1.0,0.3,0.3);
        glutSolidCube(1.3);
    glPopMatrix();

    glTranslatef(-1.2,-0.8, 0.0);
    glRotatef(250.0, 0.0, 0.0, 1.0);
    
    glPushMatrix();
        glScalef(1.0,0.3,0.3);
        glutSolidCube(1.3);
    glPopMatrix();

    /* * * * * * * * * */

    //glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(0.5,0.3, 0.0);
    glRotatef(temp1, 0.0, 0.0, 1.0);
    
    glPushMatrix();
        glScalef(0.8,0.3,0.3);
        glutSolidCube(1.3);
    glPopMatrix();

    //glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(0.9,1.7, 0.0);
    glRotatef(temp2, 0.0, 0.0, 1.0);
   
    glPushMatrix();
        glScalef(0.8,0.3,0.3);
        glutSolidCube(1.3);
    glPopMatrix();
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   desenhaEixos();

   glPushMatrix();

      glColor3f(1.0f, 1.0f, 0.0f);
		glRotatef (shoulder, 0.0, 0.0, 1.0); // rotação inicial da base (ombro) do braço
		glTranslatef (1.0, 0.0, 0.0); // Translada 1.0, pois o braço terá 2.0 de comprimento
		glPushMatrix();
			glScalef (2.0, 0.5, 0.5);
			glutSolidCube (1.2);
		glPopMatrix();

		glTranslatef (1.0, 0.0, 0.0); // origem posicionada no cotovelo
		glRotatef (elbow, 0.0, 0.0, 1.0); // faz rotação em relação ao cotovelo
		glTranslatef (1.0, 0.0, 0.0); // posiciona antebraço de tamanho 2 na posição correta
		glPushMatrix();
			glScalef (2.0, 0.5, 0.5);
			glutSolidCube (1.2);
		glPopMatrix();

      glTranslatef (1.0, 0.0, 0.0); /* desloca mais à frente */
      glRotatef(wrist, 0.0, 0.0,1.0); /*rotaciona */
      glTranslatef(1.0, 0.0, 0.0); /* desloca pra frente */
      glPushMatrix();
         glScalef(2.0,0.5,0.5); /* cria na origem */
         glutSolidCube(1.2);
      glPopMatrix();

      garra();

   glPopMatrix(); // origem volta para o sistema de coordenadas original
   glutSwapBuffers();
}

void reshape (int w, int h)
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(100.0, (GLfloat) w/(GLfloat) h, 1.0, 200.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity ();
   gluLookAt (6.0, 6.0, 6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key)
   {
   case '1':
		selected = 1;
   break;
   case '2':
		selected = 2;
	break;
   case '3':
      selected = 3;
   break;
   case 27:
      exit(0);
      break;
   default:
      break;
   }
}

// Special Keys callback
void specialKeys(int key, int x, int y)
{
   switch(key)
   {
      case GLUT_KEY_LEFT:
			if(selected == 1) shoulder = ((int) shoulder + 5) % 360;
			if(selected == 2) elbow    = ((int) elbow + 5) % 360;
         if(selected == 3) wrist       = ((int) wrist + 5) % 360;
      break;
      case GLUT_KEY_RIGHT:
			if(selected == 1) shoulder = ((int) shoulder - 5) % 360;
			if(selected == 2) elbow    = ((int) elbow - 5) % 360;
         if(selected == 3) wrist       = ((int) wrist - 5) % 360;
      break;

      case GLUT_KEY_UP:
      		temp1 = temp1 - 5;
      		temp2 = temp2 + 5;
      break;

      case GLUT_KEY_DOWN:
      		temp1 = temp1 + 5;
      		temp2 = temp2 - 5;
      break;
   }
   glutPostRedisplay();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (640, 640);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc( specialKeys );
   glutMainLoop();
   return 0;
}
