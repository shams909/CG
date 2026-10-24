#include <GL/freeglut.h>
#include <vector>
#include <algorithm>
#include <cmath>
const int LEFT=1,RIGHT=2,BOTTOM=4,TOP=8;
const double xmin=150,xmax=480,ymin=100,ymax=360;
int code(double x,double y){int c=0;if(x<xmin)c|=LEFT;else if(x>xmax)c|=RIGHT;if(y<ymin)c|=BOTTOM;else if(y>ymax)c|=TOP;return c;}
bool cohen(double &x1,double &y1,double &x2,double &y2){
    int c1=code(x1,y1),c2=code(x2,y2);
    while(true){
        if(!(c1|c2))return true;if(c1&c2)return false;
        int out=c1?c1:c2;double x,y;
        if(out&TOP){x=x1+(x2-x1)*(ymax-y1)/(y2-y1);y=ymax;}
        else if(out&BOTTOM){x=x1+(x2-x1)*(ymin-y1)/(y2-y1);y=ymin;}
        else if(out&RIGHT){y=y1+(y2-y1)*(xmax-x1)/(x2-x1);x=xmax;}
        else{y=y1+(y2-y1)*(xmin-x1)/(x2-x1);x=xmin;}
        if(out==c1){x1=x;y1=y;c1=code(x1,y1);}else{x2=x;y2=y;c2=code(x2,y2);}
    }
}
void line(double x1,double y1,double x2,double y2){glVertex2d(x1,y1);glVertex2d(x2,y2);}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);glColor3f(0,0,0);glBegin(GL_LINE_LOOP);glVertex2d(xmin,ymin);glVertex2d(xmax,ymin);glVertex2d(xmax,ymax);glVertex2d(xmin,ymax);glEnd();
    // Original lines in gray; clipped portions in blue
    glColor3f(.65f,.65f,.65f);glBegin(GL_LINES);line(70,140,560,400);line(100,300,550,180);line(200,50,420,430);glEnd();
    double a[][4]={{70,140,560,400},{100,300,550,180},{200,50,420,430}};
    glColor3f(0,0,1);glBegin(GL_LINES);for(auto &p:a){double x1=p[0],y1=p[1],x2=p[2],y2=p[3];if(cohen(x1,y1,x2,y2))line(x1,y1,x2,y2);}glEnd();
    // Sutherland-Hodgman polygon clipping: clip a triangle to same rectangle
    struct P{double x,y;};
    std::vector<P> poly={{100,150},{330,420},{530,170}};
    for(int edge=0;edge<4;edge++){
        std::vector<P> out;if(poly.empty())break;
        auto inside=[&](P p){if(edge==0)return p.x>=xmin;if(edge==1)return p.x<=xmax;if(edge==2)return p.y>=ymin;return p.y<=ymax;};
        auto intersect=[&](P a,P b){P q{};if(edge<2){q.x=edge==0?xmin:xmax;q.y=a.y+(b.y-a.y)*(q.x-a.x)/(b.x-a.x);}else{q.y=edge==2?ymin:ymax;q.x=a.x+(b.x-a.x)*(q.y-a.y)/(b.y-a.y);}return q;};
        P S=poly.back();for(P E:poly){if(inside(E)){if(!inside(S))out.push_back(intersect(S,E));out.push_back(E);}else if(inside(S))out.push_back(intersect(S,E));S=E;}poly=out;
    }
    glColor3f(0,.55f,0);glBegin(GL_LINE_LOOP);for(P p:poly)glVertex2d(p.x,p.y);glEnd();glFlush();
}
void init(){glClearColor(1,1,1,1);gluOrtho2D(0,640,0,480);}
int main(int argc,char** argv){glutInit(&argc,argv);glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);glutInitWindowSize(640,480);glutCreateWindow("Line and Polygon Clipping");init();glutDisplayFunc(display);glutMainLoop();}
