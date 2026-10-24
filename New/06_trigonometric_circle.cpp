#include <GL/freeglut.h>
#include <cmath>
const double PI=3.14159265358979323846;
void display(){
    glClear(GL_COLOR_BUFFER_BIT);glColor3f(0,0,0);glPointSize(2);
    int xc=320,yc=240,r=120;
    glBegin(GL_POINTS);
    for(double t=0;t<2*PI;t+=0.001){
        glVertex2i((int)std::lround(xc+r*std::cos(t)),(int)std::lround(yc+r*std::sin(t)));
    }
    glEnd();glFlush();
}
void init(){glClearColor(1,1,1,1);gluOrtho2D(0,640,0,480);}
int main(int argc,char** argv){glutInit(&argc,argv);glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);glutInitWindowSize(640,480);glutCreateWindow("Trigonometric Circle");init();glutDisplayFunc(display);glutMainLoop();}
