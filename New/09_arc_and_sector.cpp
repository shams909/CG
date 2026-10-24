#include <GL/freeglut.h>
#include <cmath>
const double PI=3.14159265358979323846;
void display(){
    glClear(GL_COLOR_BUFFER_BIT);glColor3f(0,0,0);
    int xc=210,yc=240,r=110;
    glBegin(GL_LINE_STRIP);
    for(double d=20;d<=300;d+=1){double t=d*PI/180;glVertex2d(xc+r*cos(t),yc+r*sin(t));}
    glEnd();
    // Sector: 30 to 140 degrees
    glColor3f(0.1f,0.3f,0.85f);
    glBegin(GL_TRIANGLE_FAN);glVertex2i(470,240);
    for(double d=30;d<=140;d+=1){double t=d*PI/180;glVertex2d(470+r*cos(t),240+r*sin(t));}
    glEnd();
    glColor3f(0,0,0);glBegin(GL_LINES);
    double a=30*PI/180,b=140*PI/180;
    glVertex2i(470,240);glVertex2d(470+r*cos(a),240+r*sin(a));
    glVertex2i(470,240);glVertex2d(470+r*cos(b),240+r*sin(b));
    glEnd();glFlush();
}
void init(){glClearColor(1,1,1,1);gluOrtho2D(0,640,0,480);}
int main(int argc,char** argv){glutInit(&argc,argv);glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);glutInitWindowSize(640,480);glutCreateWindow("Arc and Sector");init();glutDisplayFunc(display);glutMainLoop();}
