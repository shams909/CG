#include <GL/freeglut.h>
#include <cmath>
void drawCircle(double cx,double cy,double r){
    glBegin(GL_LINE_LOOP);for(int i=0;i<360;i++){double t=i*3.141592653589793/180;glVertex2d(cx+r*cos(t),cy+r*sin(t));}glEnd();
}
void drawShapes(double px,double py,double scale){
    // circle: scale every point relative to the fixed point (px,py)
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<360;i++){double t=i*3.141592653589793/180;double x=150+45*cos(t),y=140+45*sin(t);glVertex2d(px+(x-px)*scale,py+(y-py)*scale);}
    glEnd();
    glBegin(GL_LINE_LOOP);
    double tri[3][2]={{250,100},{350,100},{300,190}};
    for(auto &p:tri)glVertex2d(px+(p[0]-px)*scale,py+(p[1]-py)*scale);
    glEnd();
    glBegin(GL_LINE_LOOP);
    double rec[4][2]={{400,100},{520,100},{520,170},{400,170}};
    for(auto &p:rec)glVertex2d(px+(p[0]-px)*scale,py+(p[1]-py)*scale);
    glEnd();
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);glColor3f(0.65f,0.65f,0.65f);drawShapes(320,240,1.0);
    glColor3f(0,0,0);drawShapes(320,240,1.35);
    glPointSize(7);glBegin(GL_POINTS);glVertex2i(320,240);glEnd();glFlush();
}
void init(){glClearColor(1,1,1,1);gluOrtho2D(0,640,0,480);}
int main(int argc,char** argv){glutInit(&argc,argv);glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);glutInitWindowSize(640,480);glutCreateWindow("Magnify Circle Triangle Rectangle About Point");init();glutDisplayFunc(display);glutMainLoop();}
