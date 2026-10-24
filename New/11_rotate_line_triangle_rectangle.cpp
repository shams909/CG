#include <GL/freeglut.h>
#include <cmath>
const double PI=3.14159265358979323846;
void vertexRot(double x,double y,double px,double py,double a){
    double c=cos(a),s=sin(a),dx=x-px,dy=y-py;
    glVertex2d(px+dx*c-dy*s,py+dx*s+dy*c);
}
void drawShape(double px,double py,double a){
    // line
    glBegin(GL_LINES);vertexRot(70,80,px,py,a);vertexRot(180,120,px,py,a);glEnd();
    // triangle
    glBegin(GL_LINE_LOOP);vertexRot(240,80,px,py,a);vertexRot(330,80,px,py,a);vertexRot(285,170,px,py,a);glEnd();
    // rectangle
    glBegin(GL_LINE_LOOP);vertexRot(390,80,px,py,a);vertexRot(520,80,px,py,a);vertexRot(520,150,px,py,a);vertexRot(390,150,px,py,a);glEnd();
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);glColor3f(0.65f,0.65f,0.65f);drawShape(320,240,0);
    glColor3f(0,0,0);drawShape(320,240,PI/4);
    glPointSize(7);glBegin(GL_POINTS);glVertex2i(320,240);glEnd();glFlush();
}
void init(){glClearColor(1,1,1,1);gluOrtho2D(0,640,0,480);}
int main(int argc,char** argv){glutInit(&argc,argv);glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);glutInitWindowSize(640,480);glutCreateWindow("Rotate Line Triangle Rectangle About Point");init();glutDisplayFunc(display);glutMainLoop();}
