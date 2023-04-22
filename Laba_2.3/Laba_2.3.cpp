#include <glut.h>
#include <math.h>
GLfloat angle = 0;
GLfloat rad = 0;
GLfloat R = 640 / 640;

void init(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-15, 15, -15, 15);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

}

void figure1(void)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 100; i++)
	{
		rad = (float)i / 100 * 3.14 * 2;
		glVertex2f(cos(rad) * 6, sin(rad) * 6);
	}
	glEnd();
}

void figure2(void)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(0, 2);
	glVertex2f(-3, 0);
	glVertex2f(3, 0);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 100; i++)
	{
		rad = (float)i / 100 * 3.14 * 2;
		glVertex2f(cos(rad) * 2., sin(rad) * 1);
	}
	glEnd();
}

void reshape(GLsizei W, GLsizei H)
{
	if (R > W / H) glViewport(0, 0, W, W / R);
	else glViewport(0, 0, H * R, H);
}

void axis(void) // рисование осей
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(0, -5);
	glVertex2f(0, 5);
	glVertex2f(-5, 0);
	glVertex2f(5, 0);
	glEnd();
}

void display(void)	//функция рисования и обновления окна
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	axis();
	figure1();
	glTranslatef(8, 0, 0);
	figure2();
	glLoadIdentity();
	glTranslatef(0, 8, 0);
	glRotatef(90, 0, 0, 1);
	figure2();
	glLoadIdentity();
	glTranslatef(0, -8, 0);
	glRotatef(-90, 0, 0, 1);
	figure2();
	glLoadIdentity();
	glTranslatef(-8, 0, 0);
	glRotatef(180, 0, 0, 1);
	figure2();
	glFlush();
}


void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Laba_2.3");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}
