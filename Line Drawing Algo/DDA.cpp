#if defined(_WIN32)
#include <windows.h>
#endif
#include <GL/glut.h>
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

int x1i, y1i, x2i, y2i;

void plot(int x, int y) {
    glVertex2i(x, y);
}

void ddaLine() {
    int dx = x2i - x1i;
    int dy = y2i - y1i;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    if (steps == 0) {
        plot(x1i, y1i);
        return;
    }

    float xInc = static_cast<float>(dx) / steps;
    float yInc = static_cast<float>(dy) / steps;

    float x = static_cast<float>(x1i);
    float y = static_cast<float>(y1i);

    for (int i = 0; i <= steps; i++) {
        plot(static_cast<int>(round(x)), static_cast<int>(round(y)));
        x += xInc;
        y += yInc;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    ddaLine();
    glEnd();
    glFlush();
}

void init() {
    glClearColor(0, 0, 0, 1);
    glColor3f(0, 1, 0);
    glPointSize(3);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-300, 300, -300, 300);
}

int main(int argc, char** argv) {
    cout << "Enter x1 y1 x2 y2: ";
    cin >> x1i >> y1i >> x2i >> y2i;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("DDA Line");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
