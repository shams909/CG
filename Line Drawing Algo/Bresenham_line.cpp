#if defined(_WIN32)
#include <windows.h>
#endif
#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
using namespace std;

int x1i, y1i, x2i, y2i;

void plot(int x, int y) {
    glVertex2i(x, y);
}

void bresenhamLine() {
    int x = x1i;
    int y = y1i;

    int dx = abs(x2i - x1i);
    int dy = abs(y2i - y1i);
    int sx = (x1i < x2i) ? 1 : -1;
    int sy = (y1i < y2i) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        plot(x, y);

        if (x == x2i && y == y2i) {
            break;
        }

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x += sx;
        }
        if (e2 < dx) {
            err += dx;
            y += sy;
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    bresenhamLine();
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
    glutCreateWindow("Bresenham Line");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
