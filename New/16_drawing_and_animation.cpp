#include <GL/freeglut.h>
#include <cmath>
float x=60,dir=2;
void display(){
    glClear(GL_COLOR_BUFFER_BIT);glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);glVertex2i(80,80);glVertex2i(160,80);glVertex2i(160,160);glVertex2i(80,160);glEnd();
    glColor3f(0.1f,0.3f,0.9f);glBegin(GL_TRIANGLE_FAN);glVertex2f(x,280);for(int i=0;i<=360;i++){double t=i*3.141592653589793/180;glVertex2f(x+35*cos(t),280+35*sin(t));}glEnd();
    glColor3f(0,0,0);glBegin(GL_LINES);glVertex2f(x-55,280);glVertex2f(x+55,280);glEnd();
    glutSwapBuffers();
}
void timer(int){x+=dir;if(x>580||x<60)dir=-dir;glutPostRedisplay();glutTimerFunc(16,timer,0);}
void init(){glClearColor(1,1,1,1);gluOrtho2D(0,640,0,480);}
int main(int argc,char** argv){glutInit(&argc,argv);glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);glutInitWindowSize(640,480);glutCreateWindow("Drawing Objects and Animation");init();glutDisplayFunc(display);glutTimerFunc(16,timer,0);glutMainLoop();}
