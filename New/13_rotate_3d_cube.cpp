#include <GL/freeglut.h>
float angleX=25,angleY=35,angleZ=0;
void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);glLoadIdentity();glTranslatef(0,0,-6);
    glRotatef(angleX,1,0,0);glRotatef(angleY,0,1,0);glRotatef(angleZ,0,0,1);
    glBegin(GL_QUADS);
    glColor3f(1,0,0);glVertex3f(-1,-1,1);glVertex3f(1,-1,1);glVertex3f(1,1,1);glVertex3f(-1,1,1);
    glColor3f(0,1,0);glVertex3f(-1,-1,-1);glVertex3f(-1,1,-1);glVertex3f(1,1,-1);glVertex3f(1,-1,-1);
    glColor3f(0,0,1);glVertex3f(-1,1,-1);glVertex3f(-1,1,1);glVertex3f(1,1,1);glVertex3f(1,1,-1);
    glColor3f(1,1,0);glVertex3f(-1,-1,-1);glVertex3f(1,-1,-1);glVertex3f(1,-1,1);glVertex3f(-1,-1,1);
    glColor3f(1,0,1);glVertex3f(1,-1,-1);glVertex3f(1,1,-1);glVertex3f(1,1,1);glVertex3f(1,-1,1);
    glColor3f(0,1,1);glVertex3f(-1,-1,-1);glVertex3f(-1,-1,1);glVertex3f(-1,1,1);glVertex3f(-1,1,-1);
    glEnd();glutSwapBuffers();
}
void timer(int){angleX+=0.5f;angleY+=0.7f;angleZ+=0.2f;glutPostRedisplay();glutTimerFunc(16,timer,0);}
void reshape(int w,int h){if(h==0)h=1;glViewport(0,0,w,h);glMatrixMode(GL_PROJECTION);glLoadIdentity();gluPerspective(60,(float)w/h,1,100);glMatrixMode(GL_MODELVIEW);}
int main(int argc,char** argv){glutInit(&argc,argv);glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);glutInitWindowSize(700,550);glutCreateWindow("Rotating 3D Cube");glEnable(GL_DEPTH_TEST);glutDisplayFunc(display);glutReshapeFunc(reshape);glutTimerFunc(16,timer,0);glutMainLoop();}
