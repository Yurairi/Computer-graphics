#include <glut.h>
#include <atlbase.h>
#include <atlconv.h>
#include <iostream>
#include <string>
#include <C:\Users\USER\Desktop\кг\glaux.h>
#pragma comment(lib, "glaux.lib")
#pragma comment(lib, "legacy_stdio_definitions.lib")
#include <stdlib.h>

GLfloat angle = 0, plus = 0;
GLfloat angle2 = 0, plus2 = 0;
int fl1 = 0, fl2 = 0;
GLuint list = 0, list2 = 0;

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 15);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	AUX_RGBImageRec* img1 = auxDIBImageLoadA("C:\\Users\\USER\\Desktop\\кг\\text\\1.bmp"); //для загрузки в оперативную память изображения
	AUX_RGBImageRec* img2 = auxDIBImageLoadA("C:\\Users\\USER\\Desktop\\кг\\text\\2.bmp");
	AUX_RGBImageRec* img3 = auxDIBImageLoadA("C:\\Users\\USER\\Desktop\\кг\\text\\3.bmp");
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	list = glGenLists(1); //генерирование одного или более незадействованных индексов.
    glNewList(list, GL_COMPILE); //Определение дисплейного списка
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img1->sizeX, img1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, img1->data);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	
	// грань f0
	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
	glTexCoord2f(1, 0); glVertex3f(1, 1, 0);
	glTexCoord2f(0, 1); glVertex3f(2, 0, 0);
	glEnd();
	// грань f1
	glBegin(GL_POLYGON);
	glNormal3f(-2, 2, 0);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(0, 0, 2);
	glTexCoord2f(1, 0); glVertex3f(1, 1, 2);
	glTexCoord2f(1, 1); glVertex3f(1, 1, 0);
	glEnd();

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img3->sizeX, img3->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, img3->data);
	
	// грань f2
	glBegin(GL_POLYGON);
	glNormal3f(-2, -2, 0);
	glTexCoord2f(0, 0); glVertex3f(1, 1, 0);
	glTexCoord2f(0, 1); glVertex3f(1, 1, 2);
	glTexCoord2f(1, 0); glVertex3f(2, 0, 2);
	glTexCoord2f(1, 1); glVertex3f(2, 0, 0);
	glEnd();

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img2->sizeX, img2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, img2->data);
	
	// грань f3
	glBegin(GL_POLYGON);
	glNormal3f(-1, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(1, 1, 2);
	glTexCoord2f(1, 0); glVertex3f(0, 0, 2);
	glTexCoord2f(0, 1); glVertex3f(2, 0, 2);
	glEnd();
	// грань f4
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glTexCoord2f(0, 0); glVertex3f(2, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(2, 0, 2);
	glTexCoord2f(1, 0); glVertex3f(0, 0, 2);
	glTexCoord2f(1, 1); glVertex3f(0, 0, 0);
	glEnd();

	glEndList();

	list2 = glGenLists(1); //генерирование одного или более незадействованных индексов.
	glNewList(list2, GL_COMPILE);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(2, 0, 0);
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 2, 0);
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 2);
	glEnd();

	glEndList();
}
void myDisplay()
{
	glPushMatrix(); //Сохраняем VM = 1
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //вместе с очисткой буфера цвета предусмотреть очистку буфера глубины
	glEnable(GL_DEPTH_TEST); //включение режима удаления невидимых (проверка глубины)
	gluLookAt(3, 3, 7, 0, 0, 0, 0, 1, 0); // VM=Fwe // позиция наблюдателя
	GLfloat myLightPosition[] = { 1.0, 2.0, 2.0, 1.0 }; // Источник света в CKw
	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition); /*Позиция источника света будет преобразована в CKe*/
	glPushMatrix(); //Сохраняем VM=Fwe
	glRotatef(angle2, 0, 1, 0); // вращаем источник света
	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
	glBegin(GL_LINES); // Рисуем направление к источнику света в CKe
	glColor3f(1, 1, 1); glVertex3f(myLightPosition[0], myLightPosition[1], myLightPosition[2]); glVertex3f(0.0, 0.0, 0.0);
	glEnd();
	glPopMatrix(); // Восстанавливаем VM=Fwe
	glEnable(GL_LIGHTING); // Включение расчета освещенности
	glEnable(GL_LIGHT0); // включаем этот конкретный источник
	glPushMatrix(); //Сохраняем VM=Fwe
	glRotatef(angle, 0, 1, 0); // VM=Fwe*R

	GLfloat myAmbient[] = { 0.25, 0.25, 0.25, 1.0 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, myAmbient);
	GLfloat myDiffuse[] = { 0.4, 0.4, 0.4, 1.0 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, myDiffuse);
	GLfloat myShininess[] = { 76.8 };
	glMaterialfv(GL_FRONT, GL_SHININESS, myShininess);

	glCallList(list); //установка состояния, и команды рисования
	glPopMatrix(); // Восстанавливаем VM=Fwe
	glDisable(GL_LIGHTING); //Выключаем освещение
	glCallList(list2); //установка состояния, и команды рисования
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

void mouseButton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON) {
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL); //объект излучает свет согласно заданной текстуре
	}
	else if (button == GLUT_RIGHT_BUTTON) {
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	}
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
	setlocale(LC_ALL, "");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); // устанавливая режим дисплея в функции main(), 
	//предусмотрено использованиебуфера глубины
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Laba 5");
	glutDisplayFunc(myDisplay);
	glutMouseFunc(mouseButton);
	glutKeyboardFunc(keys);
	glutReshapeFunc(myReshape);
	glutIdleFunc(myIdle);
	init();
	glutMainLoop();
}
