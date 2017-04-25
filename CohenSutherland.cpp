/* Lab Program 5: Program to implement the Cohen-Sutherland line-clipping algorithm. Make provision to specify the input line, window for clipping and view port
for displaying the clipped image.*/


#include<stdlib.h>
#include<stdio.h>
#include<GL/glut.h>
#define outcode int

double x0=50,y0=50,x1=300,y1=300;
double xmax=200,ymax=200,xmin=100,ymin=100;
double xvmin=250,yvmin=75,xvmax=375,yvmax=200;



const int TOP=1;
const int BOTTAM=2;
const int RIGHT=4;
const int LEFT=8;


outcode computecode(double x,double y)
{
outcode code=0;
if(y>ymax)
code |=TOP;
if(y<ymin)
code |=BOTTAM;
if(x>xmax)
code |=RIGHT;
if(x<xmin)
code |=LEFT;
return code;
}


void cohenclipanddraw(double x0,double y0,double x1,double y1)
{
outcode outcode0,outcode1,outcodeout;
double sx,sy,vx0,vy0,vx1,vy1;
int accept=0,done=0;
outcode0=computecode(x0,y0);
outcode1=computecode(x1,y1);
do
{
if(!(outcode0|outcode1))
{
accept=1;
done=1;
}
else if(outcode0&outcode1)
done=1;
else

{
double x,y;
outcodeout=outcode0?outcode0:outcode1;

if(outcodeout&TOP)
{
x=x0+(x1-x0)*(ymax-y0)/(y1-y0);
y=ymax;
}
else if(outcodeout&BOTTAM)
{
x=x0+(x1-x0)*(ymin-y0)/(y1-y0);
y=ymin;
}
else if(outcodeout&RIGHT)
{
y=y0+(y1-y0)*(xmax-x0)/(x1-x0);
x=xmax;
}
else
{
y=y0+(y1-y0)*(xmin-x0)/(x1-x0);
x=xmin;
}

if(outcodeout==outcode0)
{
x0=x;y0=y;
outcode0=computecode(x0,y0);
}
else
{
x1=x;y1=y;
outcode1=computecode(x1,y1);
}
}
}

while(!done);

glColor3f(0.0,1.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(xvmin,yvmin);
glVertex2f(xvmax,yvmin);
glVertex2f(xvmax,yvmax);
glVertex2f(xvmin,yvmax);
glEnd();

if(accept)
{
sx=(xvmax-xvmin)/(xmax-xmin);
sy=(yvmax-yvmin)/(ymax-ymin);

vx0=xvmin+(x0-xmin)*sx;
vy0=yvmin+(y0-ymin)*sy;
vx1=xvmin+(x1-xmin)*sx;
vy1=yvmin+(y1-ymin)*sy;

glColor3f(1.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2f(vx0,vy0);
glVertex2f(vx1,vy1);
glEnd();
}
}


void myinit()
{
glClearColor(0.0,0.0,0.0,1.0);
glColor3f(1.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,500.0,0.0,500.0);
glMatrixMode(GL_MODELVIEW);
}



void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2f(x0,y0);
glVertex2f(x1,y1);
glEnd();
glColor3f(0.0,0.0,1.0);
glBegin(GL_LINE_LOOP);
glVertex2f(xmin,ymin);
glVertex2f(xmax,ymin);
glVertex2f(xmax,ymax);
 glVertex2f(xmin,ymax); 
 glEnd(); 
 cohenclipanddraw(x0,y0,x1,y1); 
 glFlush();
  } 
  
  
  
  
 int main(int argc,char **argv)
  { 
     /* printf("enter the starting point\n"); 
      scanf("%lf%lf",&x0,&y0);
      printf("enter the end point\n"); 
      scanf("%lf%lf",&x1,&y1); 
      printf("enter the lower left of window\n");
      scanf("%lf%lf",&xmin,&ymin);
      printf("enter the upper right of window\n");
      scanf("%lf%lf",&xmax,&ymax);
      printf("enter the lower left of Viewport\n"); 
      scanf("%lf%lf",&xvmin,&yvmin);
      printf("enter the lower left of viewport\n"); 
      scanf("%lf%lf",&xvmax,&yvmax);*/
      
      
       glutInit(&argc,argv); 
       glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
       
       glutInitWindowSize(700,570);
glutInitWindowPosition(350,150);
             
          //   glutInitWindowSize(500,500); 
           //  glutInitWindowPosition(0,0);
             glutCreateWindow("Cohen-SutherLand Line Clipping Algorithm");
              glutDisplayFunc(display); 
              myinit();
             glutMainLoop(); 
             return 0;
          }
