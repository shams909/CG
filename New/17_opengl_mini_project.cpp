#include <GL/freeglut.h>
#include <cmath>
float angle=0;
void circle(float cx,float cy,float r){
    glBegin(GL_TRIANGLE_FAN);glVertex2f(cx,cy);
    for(int i=0;i<=360;i++){float t=i*3.14159265f/180;glVertex2f(cx+r*cos(t),cy+r*sin(t));}
    glEnd();
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT); 
    // simple colorful solar-system-style animation
    glColor3f(1.0f,0.75f,0.05f);circle(320,240,45);
    glPushMatrix();glTranslatef(320,240,0);glRotatef(angle,0,0,1);glTranslatef(125,0,0);
    glColor3f(0.1f,0.35f,0.95f);circle(0,0,18);
    glPushMatrix();glRotatef(angle*2,0,0,1);glTranslatef(35,0,0);glColor3f(.65f,.65f,.65f);circle(0,0,7);glPopMatrix();
    glPopMatrix();
    glColor3f(0,0,0);glBegin(GL_LINE_LOOP);for(int i=0;i<360;i++){float t=i*3.14159265f/180;glVertex2f(320+125*cos(t),240+125*sin(t));}glEnd();
    glutSwapBuffers();
}
void timer(int){angle+=0.6f;if(angle>=360)angle-=360;glutPostRedisplay();glutTimerFunc(16,timer,0);}
void init(){glClearColor(1,1,1,1);gluOrtho2D(0,640,0,480);}
int main(int argc,char** argv){glutInit(&argc,argv);glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);glutInitWindowSize(640,480);glutCreateWindow("OpenGL Mini Project: Orbit Animation");init();glutDisplayFunc(display);glutTimerFunc(16,timer,0);glutMainLoop();}
