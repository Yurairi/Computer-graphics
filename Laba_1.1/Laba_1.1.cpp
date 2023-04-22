#include <iostream>
#include <glut.h>
#include <math.h>
#define M_PI 3.14159265358979323846

void init();
void draw();

//Главная функция
int main(int argc, char** argv)
{
    glutInit(&argc, argv); //инициализация библиотеки GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //устанавливается режим дисплея; использовать один буфер для кадра; цвета представлять как смесь RGB.
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(300, 150);
    glutCreateWindow("Лаба_1.1");
    init();
    glutDisplayFunc(draw); //функция draw( ) регистрируется как функция обратного вызова для события открытия или обновления экранного окна.
    glutMainLoop(); //переводит программу в бесконечный цикл ожидания события.


    return 0;
}

//Функция инициализации
void init()
{
    glClearColor(0.9, 0.85, 0.9, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-8.0, 8.0, -2, 2);
}

//Функция рисования
void draw()
{
    GLfloat x, y, a = 1, b = 2;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glViewport(0, 0, 640, 480);

    //оси Ox и Oy
    glBegin(GL_LINES);
    glVertex2f(-8.0, 0.0); glVertex2f(8.0, 0.0);
    glVertex2f(0.0, 1.5); glVertex2f(0.0, -1.5);
    //стрелки
    glVertex2f(7.8, 0.1); glVertex2f(8.0, 0.0);
    glVertex2f(7.8, -0.1); glVertex2f(8.0, 0.0);
    glVertex2f(-0.2, 1.4); glVertex2f(0.0, 1.5);
    glVertex2f(0.2, 1.4); glVertex2f(0.0, 1.5);
    glEnd();

    //график функции y=sin(a*x)
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    for (x = -2 * M_PI - 2; x <= 2 * M_PI + 2; x += M_PI / 180)
    {
        y = sin(a * x);
        glVertex2f(x, y);
    }
    glEnd();

    //график функции y=cos(b*x)
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    for (x = -2 * M_PI - 2; x <= 2 * M_PI + 2; x += M_PI / 180)
    {
        y = cos(b * x);
        glVertex2f(x, y);

    }
    glEnd();

    glFlush();
}