/*program to create a cylinder and a parallelepiped by extruding a circle and a quad..*/

#include<iostream.h>
#include<stdlib.h>
#include<GL/glut.h>

//GLint r,xc,yc;
 //GLint x1,y1,x2,y2,x3,y3,x4,y4;
 GLint xc=50,yc=75,r=40;
  GLint x1=100,y1=150,x2=250,y2=150,x3=250,y3=300,x4=100,y4=300;

     

void draw_pixel(GLint cx,GLint cy)
{
     glClearColor(0.0,0.0,0.0,0.0);
     glColor3f(0.0,1.0,0.0);
     glBegin(GL_POINTS);
     glVertex2i(cx,cy);
     glEnd();
     
     
}


void plotpixel(GLint h,GLint k,GLint x,GLint y)
{
 
 draw_pixel(x+h,y+k);
 draw_pixel(-x+h,y+k);
 draw_pixel(x+h,-y+k);
 draw_pixel(-x+h,-y+k);
 draw_pixel(y+h,x+k);
 draw_pixel(-y+h,x+k);
 draw_pixel(y+h,-x+k);
 draw_pixel(-y+h,-x+k);
 
}


void circle(GLint h,GLint k,GLint r)
{
     GLint d=1-r,x=0,y=r;
     while(y>x)
     {
                plotpixel(h,k,x,y);
                if(d<0)
                     d+=2*x+3;
                     else
                     {
                         d+=2*(x-y)+5;
                         --y;
                         }
                          x++;
                          
                          
                          plotpixel(h,k,x,y);
                          
                          }
}



void cylinder()
{
     GLint i,n=60;
     for(i=0;i<n;i+=4)
     {
                      circle(xc,yc+i,r);
      }
      
      
}


void quadri(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
     glClearColor(0.0,0.0,0.0,0.0);
     glColor3f(1.0,0.0,0.0);
     glBegin(GL_LINE_LOOP);
          glVertex2i(x1,y1);
          glVertex2i(x2,y2);
          glVertex2i(x3,y3);
          glVertex2i(x4,y4);
          glEnd();
          glFlush();
          
}


void parallelepiped()
{
     GLint i,n=50;
     for(i=0;i<n;i+=3)
     {
                      quadri(x1+i,y1+i,x2+i,y2+i,x3+i,y3+i,x4+i,y4+i);
       }
}


void init()
{
      glClearColor(0.0,0.0,0.0,0.0);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(0.0,500.0,0.0,500.0);
      glMatrixMode(GL_MODELVIEW);
      
}


void display()
{ 
   
     glClear(GL_COLOR_BUFFER_BIT);
     glLoadIdentity();
     glPointSize(2.0);
     cylinder();
      glEnd();
     glFlush();
     parallelepiped();
     glEnd();
     glFlush();
     
}



int main(int argc,char **argv)
{  
    
  
  // cout<<"enter the centre of circle:\n";     
    
    // cin>>xc>>yc;
   //  cout<<"enter the radius:\n";
    // cin>>r;
    // cout<<"enter the 1st vertex";
     //cin>>x1>>y1;
    // cout<<"enter the 2nd vertex";
     //cin>>x2>>y2;
    // cout<<"enter the 3rd vertex";
     //cin>>x3>>y3;
    // cout<<"enter the 4th vertex";
     //cin>>x4>>y4;
    
     
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
     glutInitWindowSize(700,570);
     glutInitWindowPosition(350,150);
    // glutInitWindowSize(500,500);
    // glutInitWindowPosition(0,0);
     glutCreateWindow("Cylinder and parallelepiped");
     glutDisplayFunc(display);
     init();
     glutMainLoop();
     return 0;
     
     }
     
     
     
                 
                                                
        
                      
                      
                      
                                                         
    
