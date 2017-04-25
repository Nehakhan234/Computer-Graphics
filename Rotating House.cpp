/*Lab Program 4: Program to create a house like figure and rotate it about a
given fixed point using OpenGL functions. */


#include<stdlib.h>
#include<stdio.h>
#include<GL/glut.h>
GLfloat theta=10.0,inc=35.0;

void myinit()
{
glClearColor(0.0,0.0,0.0,1.0);
glColor3f(1.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-500,1000,-500,1000);
glMatrixMode(GL_MODELVIEW);
}

void house()
{
glBegin(GL_LINE_LOOP);
glVertex2i(120,60);
glVertex2i(350,60);
glVertex2i(350,280);
glVertex2i(120,280);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2i(195,60);
glVertex2i(290,60);
glVertex2i(290,200);
glVertex2i(195,200);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2i(120,280);
glVertex2i(350,280);
glVertex2i(240,390);
glEnd();
}



void display()
{
     
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glRotatef(theta,0.0,0.0,1.0);
house();
glFlush();
}



void rotate()
{
theta +=inc;
glutPostRedisplay();
}



int main(int argc,char **argv)
{
   
//printf("Enter the angle and increment\n");
//scanf("%f%f",&theta,&inc);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

glutInitWindowSize(700,570);
glutInitWindowPosition(350,150);
glutCreateWindow("Rotate-House");

glutDisplayFunc(display);
//glutIdleFunc(rotate);
myinit();
glutMainLoop();
return 0;
}
