#if defined(_WIN32)
#include <windows.h>
#endif
#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

int xc, yc, r;

void plot(int x, int y) {
    glVertex2i(x, y);
}

void plotCirclePoints(int x, int y) {
    plot(xc + x, yc + y);
    plot(xc - x, yc + y);
    plot(xc + x, yc - y);
    plot(xc - x, yc - y);
    plot(xc + y, yc + x);
    plot(xc - y, yc + x);
    plot(xc + y, yc - x);
    plot(xc - y, yc - x);
}

void polynomialCircle() {
    for (int x = 0; x <= r; x++) {
        float value = static_cast<float>(r * r - x * x);
        int y = static_cast<int>(round(sqrt(value)));
        plotCirclePoints(x, y);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    polynomialCircle();
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
    cout << "Enter center (xc yc) and radius: ";
    cin >> xc >> yc >> r;

    if (r < 0) {
        cout << "Radius must be non-negative.\n";
        return 1;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Polynomial Circle");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
