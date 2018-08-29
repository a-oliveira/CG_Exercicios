#include <iostream>
#include <GL/glut.h>
#include <GL/glui.h>
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
	glutInitWindowSize(600,600);
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
}

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);

	// Define área de visualização
	// p/  exibir somente a segunda metade do gráfico
	glViewport((int) -1, (int)0, 600, 600);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 390, -2, 2, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	plano();
	grafico();
	glutSwapBuffers();
	glutPostRedisplay();
}

void plano(void)
{
	glBegin(GL_LINES);
		glColor3f (1.0, 1.0, 1.0);
		glVertex3f (-10.0, 0.0, 0.5);
		glVertex3f (390.0, 0.0, 0.5);

		glColor3f (1.0, 1.0, 1.0);
		glVertex3f (0.0, -2.0, 0.5);
		glVertex3f (0.0, 2.0, 0.5);
    glEnd();

    glColor3f(1.0,0.0,0.0);
    glPointSize(10.0f);
	glBegin(GL_POINTS);
		glVertex3f (0.0, 0.0, 0.5);
	glEnd();
}

void grafico(void)
{
	float y, pi = 3.1415;
	int i;
	if (opcao == 0) i = 360/6;
	else if (opcao == 1) i = 360/12;
	else if (opcao == 2) i = 360/180;

	for (int x = 0; x < 360; x = x+i)
	{
		glColor3f(0.0,1.0,0.6);
		glBegin(GL_LINE_STRIP);

			y	 = sin(x*pi/180);

			glVertex3f(x, y, 0.5);
			glVertex3f(x+i,sin((x+i)*pi/180),0.5);

		glEnd();
	}
	
	
}

void controle(void)
{

}