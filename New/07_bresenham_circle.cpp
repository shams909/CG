#include <GL/freeglut.h>
void plot8(int xc,int yc,int x,int y){
    glVertex2i(xc+x,yc+y);glVertex2i(xc-x,yc+y);glVertex2i(xc+x,yc-y);glVertex2i(xc-x,yc-y);
    glVertex2i(xc+y,yc+x);glVertex2i(xc-y,yc+x);glVertex2i(xc+y,yc-x);glVertex2i(xc-y,yc-x);
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);glColor3f(0,0,0);glPointSize(2);
    int xc=320,yc=240,r=120,x=0,y=r,d=3-2*r;
    glBegin(GL_POINTS);
    while(x<=y){
        plot8(xc,yc,x,y);
        if(d<0)d=d+4*x+6;
        else{d=d+4*(x-y)+10;--y;}
        ++x;
    }
    glEnd();glFlush();
}
void init(){glClearColor(1,1,1,1);gluOrtho2D(0,640,0,480);}
int main(int argc,char** argv){glutInit(&argc,argv);glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);glutInitWindowSize(640,480);glutCreateWindow("Bresenham Circle");init();glutDisplayFunc(display);glutMainLoop();}
