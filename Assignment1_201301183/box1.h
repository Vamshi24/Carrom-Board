#include <iostream>
#include <GL/glut.h>
using namespace std;
class Box
{
	public :
		float a;
		float c; 
		float red; 
		float green;
		float blue;
                float x;
                float y;
                float z;
                void drawstrikerbox(float a,float c,float x,float y,float z,float r, float g, float b)
		{
			glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
			glTranslatef(x,y,z);
			glBegin(GL_QUADS);
			red = r;
			green = g;
			blue = b;
			glColor3f(r,g,b);
			glVertex2f(-a/2,c/2);	
			glVertex2f(-a/2,-c/2);
			glVertex2f(a/2,-c/2);
			glVertex2f(a/2,c/2);
			glEnd();
			glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		}
};
class score
{
	public:
		float length,breadth;
		//translation vector coordinates
		float box_x,box_y,box_z;
		// color 
		float red,green,blue;
		int score1;
		score(float l , float b)
		{
			length = l;
			breadth = b;
		}
		void setColor(float r, float g , float b)
		{
			red = r;
			green = g;
			blue = b;
		}
		void setTranslationMatrix(float x, float y, float z)
		{
			box_x = x;
			box_y = y;
			box_z = z;
		}
		void setBoxLen(float l,float b)
		{
			length = l;
			breadth = b;
		}
		void drawBox()
		{
			glTranslatef(box_x,box_y,box_z);
			glColor3f(red,green,blue);
			glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
			glBegin(GL_QUADS);
	    	glVertex2f(-length / 2, -breadth / 2);
	    	glVertex2f(length / 2, -breadth / 2);
	    	glVertex2f(length / 2, breadth / 2);
	    	glVertex2f(-length / 2, breadth / 2);
    		glEnd();
    		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
		void drawText(const char *text,int length,float x, float y)
		{
			
			glRasterPos3f(x,y,0.0f);
			for(int i=0;i<length;i++)
    		{
        		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)text[i]);
    		}
		}
};
