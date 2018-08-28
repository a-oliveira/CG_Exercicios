#include <iostream>
#include <GL/glut.h>
#include "GL/glui.h"
#include <math.h>
void display 	(void);
void init 		(void);
void plano 		(void);
void grafico 	(void);
int opcao;

int main(int argc, char *argv[])
{
	int janela_principal;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	// Cria janela principal
	janela_principal = glutCreateWindow("Seno"); 
	glutDisplayFunc(display);

	// Cria janela com interface
	GLUI *glui 				= GLUI_Master.create_glui("CG", 0); 
	glui->add_statictext("Selecione uma das opcoes abaixo:");

	// Add painel de opções
	GLUI_Panel *painel 		= glui->add_panel("Partes:");
	GLUI_RadioGroup *botoes = glui->add_radiogroup_to_panel(painel, &opcao, 4);

	// Add botões
	glui->add_radiobutton_to_group( botoes, "6 partes" );
	glui->add_radiobutton_to_group( botoes, "12 partes" );
	glui->add_radiobutton_to_group( botoes, "180 partes" ); 

	// Insere botão de sair
	glui->add_button( "Sair", 2,(GLUI_Update_CB)exit );
	glui->set_main_gfx_window( janela_principal );

	glutMainLoop();

	return 0;
}

void init (void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 390, -2, 2, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	plano();
	grafico();
	glutSwapBuffers();
}

void plano(void)
{
	glBegin(GL_LINES);
		glColor3f (0.5, 0.0, 1.0);
		glVertex3f (-10.0, 0.0, 0.5);
		glVertex3f (390.0, 0.0, 0.5);

		glColor3f (0.5, 0.7, 0.2);
		glVertex3f (0.0, -2.0, 0.5);
		glVertex3f (0.0, 2.0, 0.5);
    glEnd();
}

void grafico(void)
{
	float pi = 3.1415;
	if (opcao == 0)
	{
		glBegin(GL_LINE_STRIP);
			glColor3f(1.0,0.0,0.0);
			glVertex3f(0.0, sin(0), 0.5);
			glVertex3f(60.0,sin(60*pi/180),0.5);
			//glVertex3f(120.0,sin(120*pi/180),0.5);
			//glVertex3f(180.0, sin(180*pi/180), 0.5);
			//glVertex3f(240.0,sin(240*pi/180),0.5);
			//glVertex3f(300.0,sin(300*pi/180),0.5);
		glEnd();
	}
	else if (opcao == 1);
	else if (opcao == 2);
	
	
}

void controle(void)
{

}