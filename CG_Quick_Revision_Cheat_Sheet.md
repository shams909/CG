# Computer Graphics Lab - Quick Revision Cheat Sheet

## 1) Common FreeGLUT Skeleton (same in all files)

```cpp
#if defined(_WIN32)
#include <windows.h>
#endif
#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

// take needed globals (x1,y1,x2,y2 or xc,yc,r)

void plot(int x, int y) {
    glVertex2i(x, y);
}

void algorithm() {
    // only this part changes
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    algorithm();
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
    // input
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("CG Lab");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
```

## 2) Circle: 8-Way Symmetry Helper

```cpp
void plotCirclePoints(int xc, int yc, int x, int y) {
    plot(xc + x, yc + y);
    plot(xc - x, yc + y);
    plot(xc + x, yc - y);
    plot(xc - x, yc - y);
    plot(xc + y, yc + x);
    plot(xc - y, yc + x);
    plot(xc + y, yc - x);
    plot(xc - y, yc - x);
}
```

## 3) Midpoint Circle Core

```cpp
int x = 0, y = r;
int p = 1 - r;
while (x <= y) {
    plotCirclePoints(xc, yc, x, y);
    x++;
    if (p < 0) p += 2 * x + 1;
    else {
        y--;
        p += 2 * (x - y) + 1;
    }
}
```

## 4) Bresenham Circle Core

```cpp
int x = 0, y = r;
int d = 3 - 2 * r;
while (x <= y) {
    plotCirclePoints(xc, yc, x, y);
    if (d < 0) d += 4 * x + 6;
    else {
        d += 4 * (x - y) + 10;
        y--;
    }
    x++;
}
```

## 5) Trigonometric Circle Core

```cpp
const float pi = 3.14159265f;
for (int a = 0; a < 360; a++) {
    float t = a * pi / 180.0f;
    int x = (int)round(r * cos(t));
    int y = (int)round(r * sin(t));
    plot(xc + x, yc + y);
}
```

## 6) Polynomial Circle Core

```cpp
for (int x = 0; x <= r; x++) {
    int y = (int)round(sqrt((float)(r * r - x * x)));
    plotCirclePoints(xc, yc, x, y);
}
```

## 7) DDA Line Core

```cpp
int dx = x2 - x1, dy = y2 - y1;
int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
float xInc = (float)dx / steps;
float yInc = (float)dy / steps;
float x = (float)x1, y = (float)y1;
for (int i = 0; i <= steps; i++) {
    plot((int)round(x), (int)round(y));
    x += xInc;
    y += yInc;
}
```

## 8) Bresenham Line Core

```cpp
int x = x1, y = y1;
int dx = abs(x2 - x1), dy = abs(y2 - y1);
int sx = (x1 < x2) ? 1 : -1;
int sy = (y1 < y2) ? 1 : -1;
int err = dx - dy;

while (true) {
    plot(x, y);
    if (x == x2 && y == y2) break;
    int e2 = 2 * err;
    if (e2 > -dy) { err -= dy; x += sx; }
    if (e2 < dx)  { err += dx; y += sy; }
}
```

## 9) Polynomial Line Core

```cpp
int dx = x2 - x1, dy = y2 - y1;
if (dx == 0) {
    for (int y = min(y1, y2); y <= max(y1, y2); y++) plot(x1, y);
} else {
    float m = (float)dy / dx;
    float c = y1 - m * x1;
    if (fabs(m) <= 1.0f) {
        for (int x = min(x1, x2); x <= max(x1, x2); x++)
            plot(x, (int)round(m * x + c));
    } else {
        for (int y = min(y1, y2); y <= max(y1, y2); y++)
            plot((int)round((y - c) / m), y);
    }
}
```

## 10) 20-Minute Study Plan

1. Memorize the common skeleton first.
2. Memorize circle symmetry helper once.
3. Learn Midpoint and Bresenham circle together (only decision term differs).
4. Learn DDA and Bresenham line together.
5. Keep trig/polynomial as formula-based backup methods.

## 11) Super Short Memory Triggers

- Midpoint circle: `p = 1 - r`
- Bresenham circle: `d = 3 - 2r`
- DDA line: `steps = max(|dx|, |dy|)`
- Bresenham line: `err = dx - dy`
- Polynomial line: `y = mx + c` or `x = (y-c)/m`
