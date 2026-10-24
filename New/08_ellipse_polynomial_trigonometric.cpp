#include <GL/freeglut.h>
#include <cmath>
const double PI=3.14159265358979323846;
void display(){
    glClear(GL_COLOR_BUFFER_BIT);glPointSize(2);
    int xc=320,yc=240,rx=180,ry=90;
    glColor3f(0,0,0); glBegin(GL_POINTS);
    // Polynomial ellipse: y = +/- ry*sqrt(1-x^2/rx^2)
    for(int x=-rx;x<=rx;x++){
        double q=1.0-(double)x*x/(rx*rx);
        if(q>=0){int y=(int)std::lround(ry*std::sqrt(q));glVertex2i(xc+x,yc+y);glVertex2i(xc+x,yc-y);}
    }
    glEnd();
    // Trigonometric ellipse, drawn in a second color
    glColor3f(0.1f,0.25f,0.85f);glBegin(GL_POINTS);
    for(double t=0;t<2*PI;t+=0.001)
        glVertex2i((int)std::lround(xc+rx*std::cos(t)),(int)std::lround(yc+ry*std::sin(t)));
    glEnd();glFlush();
}
void init(){glClearColor(1,1,1,1);gluOrtho2D(0,640,0,480);}
int main(int argc,char** argv){glutInit(&argc,argv);glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);glutInitWindowSize(640,480);glutCreateWindow("Ellipse: Polynomial Black, Trigonometric Blue");init();glutDisplayFunc(display);glutMainLoop();}
