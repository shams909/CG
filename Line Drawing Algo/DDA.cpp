#if defined(_WIN32)
#include <windows.h>
#endif

#if __has_include(<GL/freeglut.h>)
#include <GL/freeglut.h>
#elif __has_include(<GL/glut.h>)
#include <GL/glut.h>
#elif __has_include(<glut.h>)
#include <glut.h>
#else
#include <GL/glut.h>
#endif
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
};

vector<Point> g_points;
double g_left = -100.0;
double g_right = 100.0;
double g_bottom = -100.0;
double g_top = 100.0;

void plot(int x, int y) {
    g_points.push_back({x, y});
}

void ddaLine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = max(abs(dx), abs(dy));

    if (steps == 0) {
        plot(x1, y1);
        return;
    }

    float xInc = static_cast<float>(dx) / static_cast<float>(steps);
    float yInc = static_cast<float>(dy) / static_cast<float>(steps);

    float x = static_cast<float>(x1);
    float y = static_cast<float>(y1);

    for (int i = 0; i <= steps; i++) {
        plot(static_cast<int>(lround(x)), static_cast<int>(lround(y)));
        x += xInc;
        y += yInc;
    }
}

void computeBounds() {
    if (g_points.empty()) {
        return;
    }

    int minX = g_points[0].x;
    int maxX = g_points[0].x;
    int minY = g_points[0].y;
    int maxY = g_points[0].y;

    for (const Point &p : g_points) {
        minX = min(minX, p.x);
        maxX = max(maxX, p.x);
        minY = min(minY, p.y);
        maxY = max(maxY, p.y);
    }

    const int pad = 20;
    g_left = minX - pad;
    g_right = maxX + pad;
    g_bottom = minY - pad;
    g_top = maxY + pad;

    if (g_left == g_right) {
        g_left -= 1.0;
        g_right += 1.0;
    }
    if (g_bottom == g_top) {
        g_bottom -= 1.0;
        g_top += 1.0;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    for (const Point &p : g_points) {
        glVertex2i(p.x, p.y);
    }
    glEnd();
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(g_left, g_right, g_bottom, g_top);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int, int) {
    if (key == 27 || key == 'q' || key == 'Q') {
        exit(0);
    }
}

int main(int argc, char **argv) {
    int x1, y1, x2, y2;
    cout << "Enter x1 y1 x2 y2: ";
    cin >> x1 >> y1 >> x2 >> y2;

    ddaLine(x1, y1, x2, y2);
    computeBounds();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("DDA Line - GLUT");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glPointSize(3.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}