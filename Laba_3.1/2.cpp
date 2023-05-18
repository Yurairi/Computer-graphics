#include <glut.h>
#include <math.h>
#include "windows.h"
GLfloat scale = 1;
GLfloat angle = 0;
GLfloat pos = 1.0;
GLfloat rot = 0.5;
void init(void)
{
	glClearColor(1.0, 1.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void myDisplay()
{
	glPushMatrix(); //Сохраняем VM = 1
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	gluLookAt(pos * 5, pos * 3, pos * 0, 0, 0, 0, 0, 1, 0); // VM=Fwe 2.8 поменять первые 3 параматера для изменения координат наблюдателя 
	GLfloat myLightPosition[] = { 5.0, 5.0, 2.0, 1.0 }; // Источник света в CKw 2.7 изменить координаты для перемещения света 
	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition); /*Позиция источ-ника света будет преобразована в CKe*/
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix(); //Сохраняем VM=Fwe 
	//glRotatef(angle, 1, 0, 0); // VM=Fwe*R 2.4 оставить только эту строку для вращения вокург оси Х
	glRotatef(-angle, 0, 1, 0); // VM=Fwe*R*R 2.5 оставить только эту строку для вращения вокург оси Y
	//2.6 добавить - для вращения в обратную сторону
	//glRotatef(angle, 0, 0, 1); // VM=Fwe*R*R*R
	glutSolidCube(0.95 * scale);// 2.1 меняем на следующую строчку для прозрачности
	//glutSolidSphere(0.5 * scale, 10, 10); // 2.9 заменить куб на сферу
	//glutWireCube(0.95);
	glPopMatrix(); // Восстанавливаем VM=Fwe
	glDisable(GL_LIGHTING); //Выключаем освещение
	glBegin(GL_LINES);
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(1, 0, 0);
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 1, 0);
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 1);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, 1, 1); glVertex3f(5, 5, 2); glVertex3f(0.0, 0.0, 0.0);
	glEnd();
	glPopMatrix();
	Sleep(50);// 2.3 Добавляем задержку
	glutSwapBuffers();
}
void Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) { scale += 0.1; }
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) { scale -= 0.1; }
}
void Keys(unsigned char key, int x, int y) {
	if (key == 'V' || key == 'v') { rot = -1 * rot; }
	if (key == 'X' || key == 'x') { pos -= 0.1; }
	if (key == 'Z' || key == 'z') { pos += 0.1; }
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
	angle += rot;
	if (angle > 360.0) angle = 0;
	glutPostRedisplay();
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("my window");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutIdleFunc(myIdle);
	glutMouseFunc(Mouse);
	glutKeyboardFunc(Keys);
	init();
	glutMainLoop();
}
