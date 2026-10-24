#include <GL/freeglut.h>
#include <cmath>
#include <algorithm>
void display(){
    glClear(GL_COLOR_BUFFER_BIT); glColor3f(0,0,0); glPointSize(3);
    int x1=70,y1=80,x2=560,y2=350, dx=x2-x1,dy=y2-y1;
    int steps=std::max(std::abs(dx),std::abs(dy));
    double x=x1,y=y1, xInc=(double)dx/steps, yInc=(double)dy/steps;
    glBegin(GL_POINTS);
    for(int i=0;i<=steps;i++){ glVertex2i((int)std::lround(x),(int)std::lround(y)); x+=xInc; y+=yInc; }
    glEnd(); glFlush();
}
void init(){glClearColor(1,1,1,1);gluOrtho2D(0,640,0,480);}
int main(int argc,char** argv){glutInit(&argc,argv);glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);glutInitWindowSize(640,480);glutCreateWindow("DDA Line");init();glutDisplayFunc(display);glutMainLoop();}
