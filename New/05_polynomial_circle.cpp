#include <GL/freeglut.h>
#include <cmath>
void display(){
    glClear(GL_COLOR_BUFFER_BIT);glColor3f(0,0,0);glPointSize(2);
    int xc=320,yc=240,r=120;
    glBegin(GL_POINTS);
    for(int x=-r;x<=r;x++){
        int y=(int)std::lround(std::sqrt((double)r*r-(double)x*x));
        glVertex2i(xc+x,yc+y);glVertex2i(xc+x,yc-y);
    }
    for(int y=-r;y<=r;y++){
        int x=(int)std::lround(std::sqrt((double)r*r-(double)y*y));
        glVertex2i(xc+x,yc+y);glVertex2i(xc-x,yc+y);
    }
    glEnd();glFlush();
}
void init(){glClearColor(1,1,1,1);gluOrtho2D(0,640,0,480);}
int main(int argc,char** argv){glutInit(&argc,argv);glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);glutInitWindowSize(640,480);glutCreateWindow("Polynomial Circle");init();glutDisplayFunc(display);glutMainLoop();}
