#include <GL/freeglut.h>
#include <cstdlib>
void pixel(int x,int y){glVertex2i(x,y);}
void line(int x1,int y1,int x2,int y2){
    int dx=std::abs(x2-x1), dy=std::abs(y2-y1);
    int sx=(x1<x2)?1:-1, sy=(y1<y2)?1:-1, err=dx-dy;
    while(true){
        pixel(x1,y1); if(x1==x2 && y1==y2) break;
        int e2=2*err;
        if(e2>-dy){err-=dy;x1+=sx;}
        if(e2< dx){err+=dx;y1+=sy;}
    }
}
void display(){glClear(GL_COLOR_BUFFER_BIT);glColor3f(0,0,0);glPointSize(3);glBegin(GL_POINTS);line(70,80,560,350);line(80,400,500,100);line(100,180,280,440);glEnd();glFlush();}
void init(){glClearColor(1,1,1,1);gluOrtho2D(0,640,0,480);}
int main(int argc,char** argv){glutInit(&argc,argv);glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);glutInitWindowSize(640,480);glutCreateWindow("Bresenham Line");init();glutDisplayFunc(display);glutMainLoop();}
