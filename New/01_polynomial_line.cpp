#include <GL/freeglut.h>
#include <cmath>
#include <algorithm>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    glPointSize(2);
    int x1=70, y1=80, x2=560, y2=350;
    double dx=x2-x1, dy=y2-y1;
    glBegin(GL_POINTS);
    if (std::abs(dx) >= std::abs(dy)) {
        double m = dy/dx;
        int start=std::min(x1,x2), finish=std::max(x1,x2);
        for(int x=start; x<=finish; ++x) {
            double y = y1 + m*(x-x1);
            glVertex2i(x, (int)std::lround(y));
        }
    } else {
        double invM = dx/dy;
        int start=std::min(y1,y2), finish=std::max(y1,y2);
        for(int y=start; y<=finish; ++y) {
            double x = x1 + invM*(y-y1);
            glVertex2i((int)std::lround(x), y);
        }
    }
    glEnd();
    glFlush();
}
void init(){ glClearColor(1,1,1,1); gluOrtho2D(0,640,0,480); }
int main(int argc,char** argv){ glutInit(&argc,argv); glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); glutInitWindowSize(640,480); glutCreateWindow("Polynomial Line Algorithm"); init(); glutDisplayFunc(display); glutMainLoop(); }
