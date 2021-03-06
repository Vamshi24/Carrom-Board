#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include <stdio.h>
#include "box1.h"
#include "hole1.h"
using namespace std;
#define PI 3.141592653589
#define DEG2RAD(deg) (deg * PI / 180)
Box u,u1,u2,u3;
hole hol[4],s[1],hole[8],coin[9],p,c;
float theta = 0.0f;
float pointer=0.0f; 
float lx = 0.0f;
float ly = 0.4f;

void initRendering() 
{
	glEnable(GL_DEPTH_TEST);        // Enable objects to be drawn ahead/behind one another
	glEnable(GL_COLOR_MATERIAL);    // Enable coloring
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);   // Setting a background color(coin)
}

void drawScene() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); 
	//brown color of the board
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -8.0f);
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-3.0f  , -3.0f);
	glVertex2f(-3.0f , 3.0f);
	glVertex2f(3.0f , 3.0f);
	glVertex2f(3.0f , -3.0f);
	glEnd();
	glPopMatrix();
	//cream color of the board
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -8.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.8f, 0.45f);
	glVertex2f(-2.75f , -2.75f);
	glVertex2f(-2.75f , 2.75f);
	glVertex2f(2.75f , 2.75f);
	glVertex2f(2.75f , -2.75f);
	glEnd();
	glPopMatrix();
	//holes
        glTranslatef(0.0f, 0.0f, -8.0f);
	glPushMatrix();
	hol[0].drawhole(hol[0].a,hol[0].c,-8.0f,0.0f,0.0f,0.0f,0.37f);
	glPopMatrix();
	glPushMatrix();
	hol[0].drawhole(hol[1].a,hol[1].c,-8.0f,0.0f,0.0f,0.0f,0.37f);
	glPopMatrix();
	glPushMatrix();
	hol[0].drawhole(hol[2].a,hol[2].c,-8.0f,0.0f,0.0f,0.0f,0.37f);
	glPopMatrix();
	glPushMatrix();
	hol[0].drawhole(hol[3].a,hol[3].c,-8.0f,0.0f,0.0f,0.0f,0.37f);
	glPopMatrix();
	//circle at centre
	glPushMatrix();
	c.drawCircle(0.0f,0.0f,-8.0f,0.0f,0.0f,0.0f,1.50f);
	glPopMatrix();
	//striker box
	glPushMatrix();
	u.drawstrikerbox(7.0f,0.58f,0.0f,4.0f,-8.0f,0.0f,0.0f,0.0f);
	glPopMatrix();
	//striker box
	glPushMatrix();
	u1.drawstrikerbox(7.0f,0.58f,0.0f,-4.0f,-8.0f,0.0f,0.0f,0.0f);
	glPopMatrix();
	//striker box
	glPushMatrix();
	u2.drawstrikerbox(0.58f,7.0f,4.0f,0.0f,-8.0f,0.0f,0.0f,0.0f);
	glPopMatrix();
	//striker box
	glPushMatrix();
	u3.drawstrikerbox(0.58f,7.0f,-4.0f,0.0f,-8.0f,0.0f,0.0f,0.0f);
	glPopMatrix();
        //stricker box holes
	glPushMatrix();
	hole[0].drawhole(3.5f,4.0f,-8.0f,1.0f,0.0f,0.0f,0.3f);
	glPopMatrix();
	glPushMatrix();
	hole[1].drawhole(-4.0f,3.5f,-8.0f,1.0f,0.0f,0.0f,0.3f);
	glPopMatrix();
	glPushMatrix();
	hole[2].drawhole(-3.5f,-4.0f,-8.0f,1.0f,0.0f,0.0f,0.3f);
	glPopMatrix();
	glPushMatrix();
	hole[3].drawhole(4.0f,-3.5f,-8.0f,1.0f,0.0f,0.0f,0.3f);
	glPopMatrix();
	glPushMatrix();
	hole[4].drawhole(3.5f,-4.0f,-8.0f,1.0f,0.0f,0.0f,0.3f);
	glPopMatrix();
	glPushMatrix();
	hole[5].drawhole(4.0f,3.5f,-8.0f,1.0f,0.0f,0.0f,0.3f);
	glPopMatrix();
	glPushMatrix();
	hole[6].drawhole(-3.5f,4.0f,-8.0f,1.0f,0.0f,0.0f,0.3f);
	glPopMatrix();
	glPushMatrix();
	hole[7].drawhole(-4.0f,-3.5f,-8.0f,1.0f,0.0f,0.0f,0.3f);
	glPopMatrix();
	//coins
	glPushMatrix();
	coin[0].drawcoin(coin[0].a,coin[0].c,-8.0f,0.0f,0.0f,0.0f,0.2f);
	glPopMatrix();
	glPushMatrix();
	coin[1].drawcoin(coin[1].a,coin[1].c,-8.0f,0.0f,0.0f,0.0f,0.2f);
	glPopMatrix();
	glPushMatrix();
	coin[2].drawcoin(coin[2].a,coin[2].c,-8.0f,0.0f,0.0f,0.0f,0.2f);
	glPopMatrix();
	glPushMatrix();
	coin[3].drawcoin(coin[3].a,coin[3].c,-8.0f,0.0f,0.0f,0.0f,0.2f);
	glPopMatrix();
	glPushMatrix();
	coin[4].drawcoin(coin[4].a,coin[4].c,-8.0f,0.8f,0.4f,0.0f,0.2f);
	glPopMatrix();
	glPushMatrix();
	coin[5].drawcoin(coin[5].a,coin[5].c,-8.0f,0.8f,0.4f,0.0f,0.2f);
	glPopMatrix();
	glPushMatrix();
	coin[6].drawcoin(coin[6].a,coin[6].c,-8.0f,0.8f,0.4f,0.0f,0.2f);
	glPopMatrix();
	glPushMatrix();
	coin[7].drawcoin(coin[7].a,coin[7].c,-8.0f,0.8f,0.4f,0.0f,0.2f);
	glPopMatrix();
	glPushMatrix();
	coin[8].drawcoin(coin[8].a,coin[8].c,-8.0f,1.0f,0.0f,0.0f,0.2f);
	glPopMatrix();
	// striker
	glPushMatrix();
	s[0].drawstriker(s[0].a,s[0].c,-8.0f,0.5f,0.5f,0.5f,0.3f);
	glPopMatrix();
	//striker pointer
	glPushMatrix();
	glTranslatef(s[0].a,s[0].c,-8.0f);
	glColor3f(0.0f,0.0f,0.0f);
	glRotatef(theta,0.0f,0.0f,-1.0f);
	glBegin(GL_LINES);
	glVertex2f(0.0f,0.0f);
	glVertex2f(lx,ly);
	glEnd();
	glPopMatrix();
	// speedometer
        glTranslatef(10.0f, -2.4f, -8.0f);
        glPushMatrix();
        glBegin(GL_QUADS);
        glColor3f(0.0,1.0,0.0);
        glVertex2f(2.75,-7.0);
        glVertex2f(2.0,-7.0);
        glVertex2f(2.0,pointer);
        glVertex2f(2.75,pointer);
        glColor3f(1.0,0.0,0.1);
        glVertex2f(2.0,10.0);
        glVertex2f(2.75,10.0);
        glVertex2f(2.75,pointer);
        glVertex2f(2.0,pointer);
        glEnd();
        glColor3f(0.4,0.3,0.1);
        glVertex2f(0.48,pointer);
        glVertex2f(0.55,pointer);
        glPopMatrix();
	glEnd();
	glutSwapBuffers();
}

void handleResize(int w, int h) 
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float)w / (float)h, 0.1f, 200.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void handleKeypress1(unsigned char key, int x, int y) 
{
	if (key == 27) 
	{
		exit(0);     // escape key is pressed
	}
	if (key == 32)
	{
		s[0].velx = ((pointer+7)*1.0f/17)*(sin(DEG2RAD(theta)));
		s[0].vely = ((pointer+7)*1.0f/17)*(cos(DEG2RAD(theta)));
	}
	if (key == 97)      //key a
		theta -=5;
	if (key == 100)     //key d
		theta +=5;
}

void handleKeypress2(int key, int x, int y) 
{
	if (key == GLUT_KEY_LEFT && s[0].a > -5.25f)
		s[0].a -= 0.1;
	if (key == GLUT_KEY_RIGHT && s[0].a < 5.25f)
		s[0].a += 0.1;
	if (key == GLUT_KEY_UP && pointer < 10.5f)
		pointer += 0.75;
	if (key == GLUT_KEY_DOWN && pointer > -6.75f)
		pointer -= 0.75;
}

void handleMouseclick(int button, int state, int x, int y) 
{
	if (state == GLUT_DOWN)
	{
		if (button == GLUT_LEFT_BUTTON)
		{
			theta -= 5;
		}
		else if (button == GLUT_RIGHT_BUTTON)
		{
			theta += 5;
		}
	}

}

void update(int value)
{
	 if (s[0].velx != 0.0f || s[0].vely != 0.0f)
	 {
	 	if (s[0].a + s[0].rad > 8.0f || s[0].a - s[0].rad < -7.7f)
    			s[0].velx *=-1;
    		if (s[0].c + s[0].rad > 7.35f || s[0].c - s[0].rad < -8.35f)
    			s[0].vely *=-1;
		for (int i = 0; i < 9; ++i)
   		{
   			if (coin[i].a + coin[i].rad > 8.0f || coin[i].a - coin[i].rad < -7.7f)
   				coin[i].velx *=-1;
   			if (coin[i].c + coin[i].rad > 7.35f || coin[i].c - coin[i].rad < -8.35f)
   				coin[i].vely *=-1;
   		}
	 	// stiker-coin collision
   		for (int i = 0; i < 9; ++i)
   		{
   			float dx = s[0].a - coin[i].a;
   			float dy = s[0].c - coin[i].c;
   			float sumRad = s[0].rad + coin[i].rad;
   			float sqrRad = sumRad * sumRad;
   			float sqrDistance = pow(dx,2) + pow(dy,2);
   			if (sqrDistance <= sqrRad)
   			{
   				float d = sqrt(sqrDistance);
   				float collision[2];
   				collision[0] = (dx)/d; collision[1] = (dy)/d; // cos and sin respectively
   				float new1[2],new2[2];
   				new1[0] = (s[0].velx)*collision[0] + (s[0].vely)*collision[1];
   				new2[0] = (coin[i].velx)*collision[0] + (coin[i].vely)*collision[1];
   				new1[1] = (s[0].vely)*collision[0] - (s[0].velx)*collision[1];
   				new2[1] = (coin[i].vely)*collision[0] - (coin[i].velx)*collision[1];
   				// similar to 1-d collision along line joining centre
   				float a1 = (new1[0] + new2[0]*2)/3; //v1n
   				float a2 = (4*new1[0] - new2[0])/3; // v2n
   				float final1[2],final2[2];
   				final1[0] = a1*collision[0] - new1[1]*collision[1];
   				final1[1] = a1*collision[1] + new1[1]*collision[0];
   				final2[0] = a2*collision[0] - new2[1]*collision[1];
   				final2[1] = a2*collision[1] + new2[1]*collision[0];
   				s[0].velx = final1[0];
   				s[0].vely = final1[1];
   				coin[i].velx = final2[0];
   				coin[i].vely = final2[1];
   			}
   		}
		//coin-coin collision
		for (int i = 0; i < 9; ++i)
		{
			for (int j = i + 1 ; j < 9; ++j)
			{
				float dx = coin[i].a - coin[j].a;
				float dy = coin[i].c - coin[j].c;
				float d = sqrt(pow(dx,2) + pow(dy,2));
				float sumRad = coin[i].rad + coin[j].rad;
				if (d <= sumRad)
				{
					float collision[2];
   					collision[0] = (dx)/d; collision[1] = (dy)/d; // cos and sin respectively
   					float new1[2],new2[2];
   					new1[0] = (coin[i].velx)*collision[0] + (coin[i].vely)*collision[1];
   					new2[0] = (coin[j].velx)*collision[0] + (coin[j].vely)*collision[1];
   					new1[1] = (coin[i].vely)*collision[0] - (coin[i].velx)*collision[1];
   					new2[1] = (coin[j].vely)*collision[0] - (coin[j].velx)*collision[1];
   					// similar to 1-d collision along line joining centre
   					float a1 = new2[0]; //v1n
   					float a2 = new1[0]; //v2n
   					float final1[2],final2[2];
   					final1[0] = a1*collision[0] - new1[1]*collision[1];
   					final1[1] = a1*collision[1] + new1[1]*collision[0];
   					final2[0] = a2*collision[0] - new2[1]*collision[1];
   					final2[1] = a2*collision[1] + new2[1]*collision[0];
   					coin[i].velx = final1[0];
   					coin[i].vely = final1[1];
   					coin[j].velx = final2[0];
   					coin[j].vely = final2[1];
				}
			}
		}
		// coin into hole
		// for (int i = 0; i < 9; ++i)
		// {
		// 	for (int j = 0; j < 4; ++j)
		// 	{
		// 		hole[j].checkPocketing(&coin[i]);
		// 	}
		// }
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				float d = sqrt(pow((hol[j].a - coin[i].a),2) + pow((hol[j].c - coin[i].c),2));
				if (d <= hol[j].rad)
				{
					coin[i].rad = 0.0f;
					coin[i].velx = 0.0f;
					coin[i].vely = 0.0f;
				}
			}
		}
		if (s[0].velx != 0.00f)
			s[0].velx /=1.01f;
		if (s[0].vely != 0.00f)
			s[0].vely /= 1.01f;
		for (int i = 0; i < 9; ++i)
		{
			if (coin[i].velx != 0.00f)
				coin[i].velx /=1.01f;
			if (coin[i].vely != 0.00f)
				coin[i].vely /= 1.01f;
		}
		int count=0;
		for(int i=0;i<9;i++)
		{
			if(s[0].velx < 0.001f && s[0].vely < 0.001f && coin[i].velx < 0.001f && coin[i].vely < 0.001f && s[0].velx > -0.001f && s[0].vely > -0.001f && coin[i].velx > -0.001f && coin[i].vely > -0.001f)
			{
				count +=1;							
			}
		}
		if(count ==9)
		{
			s[0].velx=0.0f;
			s[0].vely=0.0f;
		}
		if(s[0].velx == 0.0f && s[0].vely == 0.0f)
		{
			s[0].a = 0.0f;
			s[0].c = -4.0f;
		}
		for (int i = 0; i < 9; ++i)
		{
			coin[i].a +=coin[i].velx;
			coin[i].c +=coin[i].vely;
		}
		s[0].a += s[0].velx;
		s[0].c += s[0].vely;
	}
	glutTimerFunc(10,update,0);
}

void init()
{
    hol[0].a = -5.1f; 
    hol[0].c = 5.1f;
    hol[1].a = -5.1f; 
    hol[1].c = -5.1f;
    hol[2].a = 5.1f; 
    hol[2].c = -5.1f;
    hol[3].a = 5.1f; 
    hol[3].c = 5.1f;
    s[0].a = 0.0f;
    s[0].c = -4.0f;
    coin[0].a = -0.85f; 
    coin[0].c =0.85f;
    coin[1].a = -0.85f;
    coin[1].c = -0.85f;
    coin[2].a = 0.85f;
    coin[2].c = -0.85f;
    coin[3].a = 0.85f;
    coin[3].c = 0.85f;
    coin[4].a = 0.0f;
    coin[4].c = 1.25f;
    coin[5].a = -1.25f; 
    coin[5].c = 0.0f;
    coin[6].a = 0.0f; 
    coin[6].c = -1.25f;
    coin[7].a = 1.25f; 
    coin[7].c = 0.0f;
    coin[8].a = 0.0f; 
    coin[8].c = 0.0f;
    for(int i=0;i<9;i++)
    {
        coin[i].rad = 0.2f;
        coin[i].velx = 0.0;
        coin[i].vely = 0.0;
    }
    s[0].velx=0.0f;
    s[0].vely=0.0f;
    s[0].rad = 0.3f;
}

int main(int argc, char **argv) 
{
	init();
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	int w = glutGet(GLUT_SCREEN_WIDTH);
	int h = glutGet(GLUT_SCREEN_HEIGHT);
	int windowWidth = w * 3 / 4;
	int windowHeight = h * 3 / 4;
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition((w - windowWidth) / 2, (h - windowHeight) / 2);
	glutCreateWindow("CARROM BOARD");  // Setup the window
	initRendering();
	// Register callbacks
	glutDisplayFunc(drawScene);
	glutIdleFunc(drawScene);
	glutKeyboardFunc(handleKeypress1);
	glutSpecialFunc(handleKeypress2);
	glutMouseFunc(handleMouseclick);
	glutReshapeFunc(handleResize);
	glutTimerFunc(10, update, 0);
	glutMainLoop();
	return 0;
}

