#include <iostream>
#include <glut.h>

void init();
void draw();

//    Главная функция
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(650, 480);
    glutInitWindowPosition(300, 150);
    glutCreateWindow("Лаба_1.2");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}

//Функция инициализации
void init()
{
    glClearColor(0.9, 0.85, 0.9, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5.0, 5.0, -5, 5);
}

//    Функция рисования
void draw()
{
    GLfloat r = 0.7, g = 0.0, b = 0.2;
    GLint x = 0, y = 0, w = 60, h = 60;
    int fl_r = 0, fl_b = 0, fl_g = 0;
    glClear(GL_COLOR_BUFFER_BIT);
    for (x = 0; x <= 600; x += w) {
        for (y = 0; y <= 480; y += h) {
            glViewport(x, y, w, h);    //создание порта просмотра
            glColor3f(r, g, b);
            //color
            if (r <= 0) { fl_r = 0; }
            if (r < 1.0 && !fl_r) { r += 0.05; }
            else { r -= 0.05; fl_r = 1; } // изменение красного цвета
            if (g <= 0) { fl_g = 0; }
            if (g < 1.0 && !fl_g) { g += 0.05;}
            else { g -= 0.05; fl_g = 1; } // изменение зеленого цвета
            if (b <= 0) { fl_b = 0; }
            if (b < 1.0 && !fl_b) { b += 0.05;}
            else { b -= 0.05; fl_b = 1 ; } // изменение голубого цвета
            //geometry
            glBegin(GL_POLYGON); // рисуем изображение
            glVertex2f(0, 0.25);
            glVertex2f(-2.5, -1);
            glVertex2f(-0.5, 2);
            glVertex2f(-3, 2);
            glVertex2f(-0.75, 2);
            glVertex2f(0, 4);
            glVertex2f(0.75, 2);
            glVertex2f(3, 2);
            glVertex2f(0.5, 2);
            glVertex2f(2.5, -1);
            glVertex2f(0, 0.25);
            glEnd();
        }
    }
    glFlush();
}