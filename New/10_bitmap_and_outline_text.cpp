#include <GL/freeglut.h>
void bitmapText(float x,float y,const char* s){
    glRasterPos2f(x,y);
    while(*s)glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*s++);
}
void strokeText(float x,float y,const char* s){
    glPushMatrix();glTranslatef(x,y,0);glScalef(0.18f,0.18f,1);
    while(*s)glutStrokeCharacter(GLUT_STROKE_ROMAN,*s++);
    glPopMatrix();
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);glColor3f(0,0,0);
    bitmapText(60,350,"BITMAP TEXT: Computer Graphics");
    strokeText(60,210,"OUTLINE / STROKE TEXT");
    glFlush();
}
void init(){glClearColor(1,1,1,1);gluOrtho2D(0,640,0,480);}
int main(int argc,char** argv){glutInit(&argc,argv);glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);glutInitWindowSize(640,480);glutCreateWindow("Bitmap and Outline Text");init();glutDisplayFunc(display);glutMainLoop();}
