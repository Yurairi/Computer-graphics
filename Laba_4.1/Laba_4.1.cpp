#include <glut.h>
#include <cmath>
#include <math.h>
#include <stdlib.h>

GLfloat angle = 0, plus = 0;
GLfloat angle2 = 0, plus2 = 0;
int fl1 = 0, fl2 = 0;

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void myDisplay()
{
	glPushMatrix(); //Сохраняем VM = 1
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //вместе с
	//очисткой буфера цвета предусмотреть очистку буфера глубины
	glEnable(GL_DEPTH_TEST); //включение режима удаления невидимых
	//(проверка глубины)
	gluLookAt(3, 3, 3, 0, 0, 0, 0, 1, 0); // VM=Fwe // позиция наблюдателя
	GLfloat myLightPosition[] = { 1.0, 2.0, 2.0, 1.0 }; // Источник света в CKw
	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition); /*Позиция
	источника света будет преобразована в CKe*/
	glEnable(GL_LIGHTING); // Включение расчета освещенности
	glEnable(GL_LIGHT0); // включаем этот конкретный источник
	glPushMatrix(); //Сохраняем VM=Fwe
	glRotatef(angle2, 0, 1, 0); // вращаем источник света
	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
	glBegin(GL_LINES);
	glColor3f(1, 1, 1); glVertex3f(1, 2, 2); glVertex3f(0.0, 0.0, 0.0);
	glEnd();
	glPopMatrix(); // Восстанавливаем VM=Fwe
	glPushMatrix(); //Сохраняем VM=Fwe
	glRotatef(angle, 0, 1, 0); // VM=Fwe*R

	// грань f0
	glBegin(GL_POLYGON);
	glNormal3f(0.577, 0.577, 0.577); glVertex3f(1, 0, 0); glVertex3f(0, 1, 0);
	glVertex3f(0, 0, 1);
	glEnd();
	// грань f1
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1); glVertex3f(0, 0, 0); glVertex3f(0, 1, 0); glVertex3f(1, 0, 0);
	glEnd();
	// грань f2
	glBegin(GL_POLYGON);
	glNormal3f(-1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(0, 0, 1); glVertex3f(0, 1, 0);
	glEnd();
	// грань f3
	glBegin(GL_POLYGON);

	glNormal3f(0, -1, 0); glVertex3f(1, 0, 0); glVertex3f(0, 0, 1); glVertex3f(0, 0, 0);
	glEnd();

	glPopMatrix(); // Восстанавливаем VM=Fwe
	glDisable(GL_LIGHTING); //Выключаем освещение
	glBegin(GL_LINES); //Рисуем координатные оси разного цвета в CKe
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(2, 0, 0);
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 2, 0);
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 2);
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
}

void myReshape(int width, int height)
{
	if (height != 0) {
		if (width / height < 1) glViewport(0, 0, width, width);
		else glViewport(0, 0, height, height);
	}
}

void myIdle()
{
	angle += plus; if (angle > 360.0) angle = 0;
	angle2 += plus2; if (angle2 > 360.0) angle2 = 0;
	glutPostRedisplay();
}

void keys(unsigned char key, int x, int y)
{
	if (key == 'o' || key == 'O') {
		if (fl1 % 2 == 0) plus = 0.1;
		else plus = 0;
		fl1++;
	}
	 if (key == 'l' || key == 'L') {
		if (fl2 % 2 == 0) plus2 = 0.1;
		else plus2 = 0;
		fl2++;
	}
	if (key == 'f' || key == 'F') {
		glCullFace(GL_BACK);
		glEnable(GL_CULL_FACE);
	}
	else if (key == 'b' || key == 'B') {
		glCullFace(GL_FRONT);
		glEnable(GL_CULL_FACE);
	}
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); // устанавливая режим дисплея в функции main(), 
	//предусмотрено использованиебуфера глубины
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Laba 4.1");
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(keys);
	glutReshapeFunc(myReshape);
	glutIdleFunc(myIdle);
	init();
	glutMainLoop();
}