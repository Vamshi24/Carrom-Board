#include <iostream>
#include <GL/glut.h>
using namespace std;

#define PI 3.141592653589
#define DEG2RAD(deg) (deg * PI / 180)

class hole
{
	public :
		 float a;
		 float c;
		 float d;
		 float red; 
		 float green;
		 float blue;
		 float rad;
         	 float velx;
		 float vely;
		 float check;
		 hole()
		 {
		 	check = 0;
		 	velx=0.0f;
			vely=0.0f;
		 }
		void drawhole(float a,float c,float d,float r,float g,float b,float rad)
		{
            		glTranslatef(a,c,d);
			red = r;
			green = g;
			blue = b;
			glColor3f(r,g,b);
			glBegin(GL_TRIANGLE_FAN);
   			for(int i=0 ; i<360 ; i++)
			{
       				glVertex2f(rad * cos(DEG2RAD(i)), rad * sin(DEG2RAD(i)));
   			}
   			glEnd();
		}
                void drawstriker(float a,float c,float d,float r,float g,float b,float rad)
		{
            		glTranslatef(a,c,d);
			red = r;
			green = g;
			blue = b;
			glColor3f(r,g,b);
			glBegin(GL_TRIANGLE_FAN);
   			for(int i=0 ; i<360 ; i++) 
			{
       				glVertex2f(rad * cos(DEG2RAD(i)), rad * sin(DEG2RAD(i)));
   			}
   			glEnd();
		}
                void drawcoin(float a,float c,float d,float r,float g,float b,float rad)
		{
            		glTranslatef(a,c,d);
			red = r;
			green = g;
			blue = b;
			glColor3f(r,g,b);
			glBegin(GL_TRIANGLE_FAN);
   			for(int i=0 ; i<360 ; i++)
			{
       				glVertex2f(rad * cos(DEG2RAD(i)), rad * sin(DEG2RAD(i)));
   			}
   			glEnd();
		}
		void drawCircle(float a,float c,float d,float r,float g,float b,float rad)
		{
			glTranslatef(a,c,d);
			red = r;
			green = g;
			blue = b;
			glColor3f(r,g,b);	
			glBegin(GL_LINE_STRIP);
			for(int i=0 ; i<360 ; i++)
			{
       				glVertex2f(rad * cos(DEG2RAD(i)), rad * sin(DEG2RAD(i)));
   			}
   			glEnd();
		}
};
