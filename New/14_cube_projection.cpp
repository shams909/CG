#include <GL/freeglut.h>
int mode=0;
void cube(){
    glBegin(GL_QUADS);
    glColor3f(1,0,0);glVertex3f(-1,-1,1);glVertex3f(1,-1,1);glVertex3f(1,1,1);glVertex3f(-1,1,1);
    glColor3f(0,1,0);glVertex3f(-1,-1,-1);glVertex3f(-1,1,-1);glVertex3f(1,1,-1);glVertex3f(1,-1,-1);
    glColor3f(0,0,1);glVertex3f(-1,1,-1);glVertex3f(-1,1,1);glVertex3f(1,1,1);glVertex3f(1,1,-1);
    glColor3f(1,1,0);glVertex3f(-1,-1,-1);glVertex3f(1,-1,-1);glVertex3f(1,-1,1);glVertex3f(-1,-1,1);
    glColor3f(1,0,1);glVertex3f(1,-1,-1);glVertex3f(1,1,-1);glVertex3f(1,1,1);glVertex3f(1,-1,1);
    glColor3f(0,1,1);glVertex3f(-1,-1,-1);glVertex3f(-1,-1,1);glVertex3f(-1,1,1);glVertex3f(-1,1,-1);
    glEnd();
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);glMatrixMode(GL_MODELVIEW);glLoadIdentity();glTranslatef(0,0,-5);glRotatef(25,1,1,0);
    if(mode==0)glMatrixMode(GL_PROJECTION),glLoadIdentity(),glOrtho(-3,3,-3,3,1,100),glMatrixMode(GL_MODELVIEW);
    else glMatrixMode(GL_PROJECTION),glLoadIdentity(),gluPerspective(60,1.0,1,100),glMatrixMode(GL_MODELVIEW);
    cube();glutSwapBuffers();
}
void key(unsigned char k,int,int){if(k=='p'||k=='P')mode=1-mode;glutPostRedisplay();}
void init(){glEnable(GL_DEPTH_TEST);glClearColor(1,1,1,1);}
int main(int argc,char** argv){glutInit(&argc,argv);glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);glutInitWindowSize(600,600);glutCreateWindow("Cube Projection: press P to toggle");init();glutDisplayFunc(display);glutKeyboardFunc(key);glutMainLoop();}
