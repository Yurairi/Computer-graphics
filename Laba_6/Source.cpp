#include <glut.h>
#include <cmath>
#include <math.h>
#include <iostream>

#define PI 3.1459
GLfloat A, AA;

int count = 0;
float* X;
float* Y;

//Функция инициализации
void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
}
//Функция рисования
void draw()
{
	GLfloat X = 0, Y = 0;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(-100, 0.0); glVertex2f(100, 0.0);
	glVertex2f(0.0, 100.0); glVertex2f(0.0, -100.0);
	glEnd();

	// Дуга окружности в заданной четверти в указанном направлении (1)
	GLfloat R = A;
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_STRIP);
	X = 0;
	Y = R;

	// 1 способ
	glVertex2f(X, Y);
	while (X > -A || Y > 0) {
		if ((pow(X, 2) + pow(Y, 2) - pow(R, 2)) > 0) {
			Y = Y - 1;
			glVertex2f(X, Y);
		}
		else if ((pow(X, 2) + pow(Y, 2) - pow(R, 2)) < 0) {
			X = X - 1;
			glVertex2f(X, Y);
		}
		else {
			if (X <= Y) X = X - 1;
			else Y = Y - 1;
			glVertex2f(X, Y);
		}
		std::cout << X << " " << Y << "\n";
	}
	glEnd();

	// 2 способ
	glColor3f(1.0, 0.0, 1.0);

	GLfloat dX, dY;
	X = 0; Y = AA;
	glBegin(GL_LINE_STRIP);
	glVertex2f(X, Y);
	while (X > -AA || Y > 0) {
		dX = X / AA;
		dY = Y / AA;
		Y = Y + dX;
		X = X - dY;
		glVertex2f(X, Y);
		std::cout << "2. " << X << " " << Y << "\n";
	}

	glEnd();

	glFlush();
}

void myReshape(int width, int height)
{
	if (height != 0) {
		if (width / height < 1) glViewport(10, 10, width - 50, width - 50);
		else glViewport(10, 10, height - 50, height - 50); 
	}
}

//Главная функция
int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите 1 радиус: \n";
	std::cin >> A;
	std::cout << "Введите 2 радиус: \n";
	std::cin >> AA;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Laba 6");
	glutDisplayFunc(draw);
	glutReshapeFunc(myReshape);
	init();
	glutMainLoop();
}