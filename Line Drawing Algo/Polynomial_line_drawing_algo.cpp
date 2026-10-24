#if defined(_WIN32)
#include <windows.h>
#endif
#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

int x1i, y1i, x2i, y2i;

void plot(int x, int y) {
    glVertex2i(x, y);
}

void polynomialLine() {
    int dx = x2i - x1i;
    int dy = y2i - y1i;

    if (dx == 0) {
        int startY = (y1i < y2i) ? y1i : y2i;
        int endY = (y1i > y2i) ? y1i : y2i;
        for (int y = startY; y <= endY; y++) {
            plot(x1i, y);
        }
        return;
    }

    float m = static_cast<float>(dy) / dx;
    float c = y1i - m * x1i;

    if (fabs(m) <= 1.0f) {
        int startX = (x1i < x2i) ? x1i : x2i;
        int endX = (x1i > x2i) ? x1i : x2i;
        for (int x = startX; x <= endX; x++) {
            plot(x, static_cast<int>(round(m * x + c)));
        }
    } else {
        int startY = (y1i < y2i) ? y1i : y2i;
        int endY = (y1i > y2i) ? y1i : y2i;
        for (int y = startY; y <= endY; y++) {
            plot(static_cast<int>(round((y - c) / m)), y);
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    polynomialLine();
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
    glutCreateWindow("Polynomial Line");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
