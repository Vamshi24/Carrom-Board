/*******************************              AUTHOR : SRITEJA  ***********************************/

#include "GL/freeglut.h"
#include "math.h"
#include "GL/gl.h"
#include "GL/glut.h"
#include "stdio.h"

#define PI 3.14

// function declarations
void handleKeypress1(unsigned char key, int x, int y);
void handleKeypress2(int key, int x, int y);
void handleKeypress3(unsigned char key, int x, int y);
void handleKeypress4(unsigned char key, int x, int y);
void update();
void mouseStriker();
void drawFilledCircle(float , float, float);
void game_starts();
bool is_correct();
int flag=0;
int flags[10];
int  score = 30;
float pointer,speed;
float place1_x,place1_y,place2_y,place2_x;
int zero;
class COIN {
            public:
                void set_circle(float x, float  y, float r)
                {
                    centre_x = x;
                    centre_y = y;
                    rad = r;
                }
                void drawFilledCircle(float centre_x, float centre_y, float radius)
                {
    
                    int i;
                    int triangleAmount = 41; //# of triangles used to draw circle
                    //GLfloat radius = 0.8f; //radius
                    float twicePi = 2.0f * PI;
                    glBegin(GL_TRIANGLE_FAN);
                    glVertex2f(centre_x, centre_y); // center of circle
                    for(i = 0; i <= triangleAmount;i++) 
                    { 
                        glVertex2f(centre_x+(radius*cos(i *twicePi/triangleAmount)),centre_y + (radius*sin(i*twicePi/triangleAmount)));
                    }
                    glEnd();
                }
                
            
                float centre_x;
                float centre_y;
                float rad;
                double velocity_x;
                double velocity_y;
                float mass;
};


COIN white[10];
//COIN black[5];
float striker_centre_x = -0.28f;
float striker_centre_y = -0.524f;
float lift_x = 1.9f;
float lift_y = 0.0f;
float striker_velx,striker_vely;
int i,j;
void drawFilledCircle(float x, float y, float radius)
                {
    
                    int i;
                    int triangleAmount = 41; //# of triangles used to draw circle
                    //GLfloat radius = 0.8f; //radius
                    float twicePi = 2.0f * PI;
                    glBegin(GL_TRIANGLE_FAN);
                    glVertex2f(x, y); // center of circle
                    for(i = 0; i <= triangleAmount;i++) 
                    { 
                        glVertex2f(x+(radius*cos(i *twicePi/triangleAmount)),y + (radius*sin(i*twicePi/triangleAmount)));
                    }
                    glEnd();
                    
                }

void renderFunction()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    
    // cream color of the board
    glPushMatrix();
    glTranslatef(-0.2f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glColor3f(0.2f, 0.0f, 0.0f);
        glVertex2f(-0.55f  , -0.75f);
        glVertex2f(-0.55f , 0.75f);
        glVertex2f(0.55f , 0.75f);
        glVertex2f(0.55f , -0.75f);
    glEnd();
    glPopMatrix();

    // brown-color border of the board
    glPushMatrix();
    glTranslatef(-0.2f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.8f, 0.45f);
        glVertex2f(-0.5f , -0.7f);
        glVertex2f(-0.5f , 0.7f);
        glVertex2f(0.5f , 0.7f);
        glVertex2f(0.5f , -0.7f);
    glEnd();
    glPopMatrix();

    // red border on the board
    glPushMatrix();
    glBegin(GL_LINE_LOOP);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-0.58f, -0.55f);
        glVertex2f(-0.58f, 0.55f);
        glVertex2f(0.17f, 0.55f);
        glVertex2f(0.17f, -0.55f);
        glVertex2f(-0.581f, -0.552f);
        glVertex2f(-0.581f, 0.552f);
        glVertex2f(0.172f, 0.552f);
        glVertex2f(0.172f, -0.552f);
        glVertex2f(-0.5811f, -0.5521f);
        glVertex2f(-0.5811f, 0.5521f);
        glVertex2f(0.1722f, 0.5522f);
        glVertex2f(0.1722f, -0.5522f);
    glEnd();
    glPopMatrix();
     
    // right-down corner of the board    
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    drawFilledCircle(0.27f, -0.67f, 0.03f);
    glEnd();
    glPopMatrix();

    // right-top corner of the board
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    drawFilledCircle(0.27f, 0.67f, 0.03f);
    glEnd();
    glPopMatrix();

    // left-top corner of the board
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0.0f,0.0f,0.0f);
    drawFilledCircle(-0.67f, 0.67f, 0.03f);
    glEnd();
    glPopMatrix();

    // left-down corner of the board
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0.0f,0.0f,0.0f);
    drawFilledCircle(-0.67f, -0.67f, 0.03f);
    glEnd();
    glPopMatrix();

    glBegin(GL_QUADS);
    // circular border at the centre of the board
    float x1,y1,x2,y2;
    float angle;
    float radius=0.13;
    x1 = -0.22,y1=0;
    for (angle=0.0f;angle<20.0f;angle+=0.2f)
    {
        glPushMatrix();
        glBegin(GL_QUADS);
        glColor3f(0.0,0.0,0.0);
        radius=radius+0.0001;
        x2 = x1+cos(angle)*radius;
        y2 = y1+sin(angle)*radius;
        glVertex2f(x2,y2);
    }
    glEnd();
    glPopMatrix();

    //red coin
    //COIN red;
    if(flags[9]!=44)
    {
    white[9].set_circle(white[9].centre_x, white[9].centre_y, 0.02f);
    glPushMatrix();
    glColor3f(1.0,0.0,0.0);
    white[9].drawFilledCircle(white[9].centre_x, white[9].centre_y, 0.02f);
    glEnd();
    glPopMatrix();
    } 
    // white 1
    //COIN white1;
    if(flags[1]!=44){
    white[1].set_circle(white[1].centre_x, white[1].centre_y, 0.02f);
    glPushMatrix();
    glColor3f(0.8f,0.4f,0.0f);
    white[1].drawFilledCircle(white[1].centre_x, white[1].centre_y, 0.02f);
    glEnd();
    glPopMatrix();
}

    // white 2
    //COIN white2;
if(flags[2]!=44){
    white[2].set_circle(white[2].centre_x, white[2].centre_y, 0.02f);
    glPushMatrix();
    glColor3f(0.8f,0.4f,0.0f);
    white[2].drawFilledCircle(white[2].centre_x, white[2].centre_y, 0.02f);
    glEnd();
    glPopMatrix();
}
    // white 3
    //COIN white3;
if(flags[3]!=44){
    white[3].set_circle(white[3].centre_x, white[3].centre_y, 0.02f);
    glPushMatrix();
    glColor3f(0.8f,0.4f,0.0f);
    white[3].drawFilledCircle(white[3].centre_x, white[3].centre_y, 0.02f);
    glEnd();
    glPopMatrix();

}
    // white 4 
    //COIN white4;
if(flags[4]!=44){
    white[4].set_circle(white[4].centre_x, white[4].centre_y, 0.02f);
    glPushMatrix();
    glColor3f(0.8f,0.4f,0.0f);
    white[4].drawFilledCircle(white[4].centre_x, white[4].centre_y, 0.02f);
    glEnd();
    glPopMatrix();
}
    // black 1
    //COIN black1;
    if(flags[5]!=44){
    white[5].set_circle(white[5].centre_x, white[5].centre_y, 0.02f);
    glPushMatrix();
    glColor3f(0.0f,0.0f,0.0f);
    white[5].drawFilledCircle(white[5].centre_x, white[5].centre_y, 0.02f);
    glEnd();
    glPopMatrix();
}
    // black 2
    if(flags[6]!=44){//COIN black2;
    white[6].set_circle(white[6].centre_x, white[6].centre_y, 0.02f);
    glPushMatrix();
    glColor3f(0.0f,0.0f,0.0f);
    white[6].drawFilledCircle(white[6].centre_x, white[6].centre_y, 0.02f);
    glEnd();
    glPopMatrix();
}
    // black 3
    if(flags[7]!=44){//COIN black3;
    white[7].set_circle(white[7].centre_x, white[7].centre_y, 0.02f);
    glPushMatrix();
    glColor3f(0.0f,0.0f,0.0f);
    white[7].drawFilledCircle(white[7].centre_x, white[7].centre_y, 0.02f);
    glEnd();
    glPopMatrix();
}
    // black 4
    if(flags[8]!=44){//COIN black4;
    white[8].set_circle(white[8].centre_x, white[8].centre_y, 0.02f);
    glPushMatrix();
    glColor3f(0.0f,0.0f,0.0f);
    white[8].drawFilledCircle(white[8].centre_x, white[8].centre_y, 0.02f);
    glEnd();
    glPopMatrix();
}
    if(flags[0]!=44){// striker
    white[0].set_circle(white[0].centre_x, white[0].centre_y, 0.025f);
    glPushMatrix();
    glColor3f(0.0,1.0,0.0);
    white[0].drawFilledCircle(white[0].centre_x, white[0].centre_y, 0.025f);
    glEnd();
    glPopMatrix();
}
    glColor3f(0.0,0.7,1.0);
    drawFilledCircle(lift_x,lift_y,0.006f);
    glEnd();
    if(flag==11){
        glPushMatrix();
        glBegin(GL_LINES);
        glColor3f(0.0,0.0,0.0);
        glVertex2f(lift_x,lift_y);
        glVertex2f(white[0].centre_x,white[0].centre_y);

        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.0,0.0,0.3);
        glVertex2f(lift_x,lift_y);
        glVertex2f(white[0].centre_x,white[0].centre_y);
        glEnd();
        glPopMatrix();
    }

    // speedometer
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(0.55,-0.75);
    glVertex2f(0.5,-0.75);
    glVertex2f(0.5,pointer);
    glVertex2f(0.55,pointer);
    glColor3f(1.0,0.0,0.1);
    glVertex2f(0.5,0.7);
    glVertex2f(0.55,0.7);
    glVertex2f(0.55,pointer);
    glVertex2f(0.5,pointer);
    glEnd();
    //glBegin(GL_LINES);
    glColor3f(0.4,0.3,0.1);
    glVertex2f(0.48,pointer);
    glVertex2f(0.55,pointer);
    //glEnd();
    glPopMatrix();
        //glutSwapBuffers();
    glutSwapBuffers();
}

void game_starts()
{
    int g,v;
    g = 1; //is_correct();
    if(g==1)
    {
        // then the pointer is in the correct position
        // keep the point 
        v = 1; // set_speed()
        //update();
    }
}
   
  


bool is_correct()
{
    // check whether the point is in the red box or not
    
}


float marker_x;
float marker_y;
void motion(int , int);
void mouseStriker(int button, int state, int x, int y)
{
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN)
            {   
                glColor3f(0.0,1.0,0.0);
                marker_x = ((2.0 / float(1300)) * x*1.0) - 1.0;
                marker_y = ((2.0 / float(715)) * y*1.0) - 1.0;
                printf("%f\n",marker_x);
                printf("%f\n",marker_y);
                glVertex2f(marker_x,marker_y);
                
            }
            break;
    }
}
float striker_x,x19;
float striker_y,y19;
void motion(int x, int y)
{
    striker_x = x * 1.0;
    striker_y = y * 1.0;
    striker_x = ((2.0 / float(1300)) * striker_x) - 1.0;
    striker_y = ((2.0 / float(715)) * striker_y) - 1.0;
    striker_y = -striker_y;
                //printf("=====%f\n",striker_y );
                //printf("%f\n",striker_x );
    if(striker_x < 0.13 && striker_x > -0.57)
    {
        white[0].set_circle(striker_x, -0.524f, 0.025f);
        glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        striker_centre_x = striker_x;
        striker_centre_y = -0.524f;
        white[0].centre_y = striker_centre_y;
        white[0].centre_x = striker_centre_x;
        //printf("%f %f\n",white[0].centre_x,white[0].centre_y);
        glEnd();
        glPopMatrix();
        glutSwapBuffers();
    }
    else if(striker_x < -0.57)
                    white[0].centre_x = -0.57;
    else if(striker_x > 0.13)
                    white[0].centre_x = 0.135;

    //glutPostRedisplay();
}

void dec_coins()
{
    puts("dec\n");
    white[0].centre_x = -0.28;
    white[0].centre_y = -0.524;
    white[1].centre_x = -0.32;
    white[1].centre_y = -0.005;
    white[2].centre_x = -0.12;
    white[2].centre_y = -0.005;
    white[3].centre_x = -0.22;
    white[3].centre_y = 0.0995;
    white[4].centre_x = -0.22;
    white[4].centre_y = -0.0995;
    white[5].centre_x = -0.154; 
    white[5].centre_y = -0.075;
    white[6].centre_x = -0.28; 
    white[6].centre_y = -0.075;
    white[7].centre_x = -0.28; 
    white[7].centre_y = 0.07;
    white[8].centre_x = -0.154; 
    white[8].centre_y = 0.07;
    white[9].centre_x = -0.22; 
    white[9].centre_y = -0.005;
    pointer = -0.3;
    for(i=1;i<10;i++)
    {
        white[i].rad = 0.02;
        white[i].velocity_x = 0.0;
        white[i].velocity_y = 0.0;
        white[i].mass = 1.0;
        flags[i]=0;
    }
    white[0].rad = 0.025;
    white[0].mass = 5.0;
    flags[0]=0;
    place1_y = -0.3;
    place1_x = 0.8;
    place2_x = 0.8;
    place2_y = -0.3+0.08;
    zero = 0;
}

int main(int argc, char** argv)
{
    dec_coins();
    //Initialising GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glEnable(GL_TEXTURE_2D);

    // Create Window
    int w = glutGet(GLUT_SCREEN_WIDTH);
    int h = glutGet(GLUT_SCREEN_HEIGHT);
    int windowWidth = w * 2 / 3;
    int windowHeight = h * 2 / 3;

    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition((w - windowWidth) / 2, (h - windowHeight) / 2);
glutCreateWindow("CSE251_sampleCode");  // Setup the window
    //Set handler functions
    glutDisplayFunc(renderFunction);
    glutIdleFunc(renderFunction);
    glutKeyboardFunc(handleKeypress1);
    glutSpecialFunc(handleKeypress2);
    //glutMouseFunc(mouseStriker);   
    //glutMotionFunc(motion);
    //glutTimerFunc(0, update, 10);

    glutMainLoop();    
    return 0;
}
float theta;
float slope;
float count = 1.0;
float final_velocity_x,final_velocity_y,f_velocity_y,f_velocity_x;
//float white[i].velocity;
void update(int value)
{
    for(i=0;i<10;i++)
    {
        if(white[i].centre_x - white[i].rad <= -0.7 || white[i].centre_x + white[i].rad >= 0.3)
            white[i].velocity_x *= -1;
        if(white[i].centre_y - white[i].rad <= -0.7 || white[i].centre_y + white[i].rad >= 0.7)
            white[i].velocity_y *= -1;
    }

    for(i=0;i<10;i++)
    {
        //white[i].centre_x += white[i].velocity_x/count;
        //white[i].centre_y += white[i].velocity_y/count;
        for(j=i+1;j<10;j++)
        {
            float dom = white[i].centre_x - white[j].centre_x;
            float dom2 = white[i].centre_y - white[j].centre_y;
            float total_dist = sqrt(dom*dom + dom2*dom2);
            if(total_dist <= white[i].rad + white[j].rad)
            {
                final_velocity_x = -((white[i].mass - white[j].mass) / (white[i].mass + white[j].mass)) * white[j].velocity_x + (2 * white[i].mass * white[i].velocity_x) / (white[i].mass + white[j].mass);;
                final_velocity_y = -((white[i].mass - white[j].mass) / (white[i].mass + white[j].mass)) * white[j].velocity_y + (2 * white[i].mass * white[i].velocity_y) / (white[i].mass + white[j].mass);
                f_velocity_x = ((white[i].mass - white[j].mass) / (white[i].mass + white[j].mass)) * white[i].velocity_x + (2 * white[j].mass * white[j].velocity_x) / (white[i].mass + white[j].mass);
                f_velocity_y = ((white[i].mass - white[j].mass) / (white[i].mass + white[j].mass)) * white[i].velocity_y + (2 * white[j].mass * white[j].velocity_y) / (white[i].mass + white[j].mass) ;
              printf("%f %f %f %f \n",final_velocity_x,final_velocity_y,f_velocity_x,f_velocity_y);

                white[j].velocity_x = final_velocity_x;
                white[j].velocity_y = final_velocity_y;
                white[i].velocity_x = f_velocity_x;
                white[i].velocity_y = f_velocity_y;
            }
            white[i].centre_x += white[i].velocity_x/count;
            white[i].centre_y += white[i].velocity_y/count;
            white[j].centre_x += white[j].velocity_x/count;
            white[j].centre_y += white[j].velocity_y/count;
            
        }
       // printf("%lf %lf\n",white[i].velocity_x, white[i].velocity_y);
      
        white[i].centre_x += white[i].velocity_x/count;
        white[i].centre_y += white[i].velocity_y/count;
        if(white[i].centre_x >= 0.25 && white[i].centre_y <= -0.65 || white[i].centre_x >= 0.25 && white[i].centre_y >= 0.65 || white[i].centre_x <= -0.65 && white[i].centre_y >= 0.65 || white[i].centre_x <= -0.65 && white[i].centre_y <= -0.65)
        {
            flags[i] = 45;
            white[i].velocity_x = 0.0;
            white[i].velocity_y = 0.0;
            if(i==0)
            {
                flags[0]=0;
                white[0].centre_x = -0.28;
                white[0].centre_y = -0.524;
                score = score - 2;
            }
            if(i>=1 && i<=4 || i == 9)
            {
                score = score + 10;
                white[i].centre_x = place1_x;
                white[i].centre_y = place1_y;
                place1_x -= 0.05;
                place1_y = -0.3 ;
                if(i == 9)
                {
                    score = score + 5;
                }
            }
            if(i>=5 && i<=8)
            {
                
                score = score - 5;
                white[i].centre_x = place2_x;
                white[i].centre_y = place2_y;
                place2_x -= 0.05;
                place2_y = -0.3 + 0.08;
               
            }
        }

        
        
       // printf("%f %f\n",white[i].velocity_x,white[i].velocity_y);

    }
                
    count=count * 1.0002;
    //printf("score --> %d\n",score);
    //printf("%f %f\n",white[0].velocity_x,white[0].velocity_y);
    
    
    if(value > 0)
    glutTimerFunc(0, update, value - 1);
    if(value == 0)
    {
        white[0].centre_x = -0.28;
            white[0].centre_y = -0.524;
            
    }
      
    //printf("value---> %d\n",value);
}

void handleKeypress1(unsigned char key, int x, int y) {

    if (key == 27) {
        exit(0);     // escape key is pressed
    }
    if (key == 32)
    {
        slope = (lift_y - white[0].centre_y) / (lift_x - white[0].centre_x);
        theta = atan(slope);
        if(theta<0)
            theta+=PI;
            //if(pointer <= 0.5)
            //{
                speed = pointer + 0.9;
            //} 
            //else
            //speed = pointer; 
        striker_velx = speed * 0.0001;
        count = 1.0;
        for(i=1;i<10;i++)
        {
            white[i].velocity_x = 0.0;
            white[i].velocity_y = 0.0;
        }
        white[0].velocity_x = striker_velx * cos(theta);
        white[0].velocity_y = striker_velx * sin(theta);
        printf("%f %f\n",white[0].velocity_x,white[0].velocity_y);
        glutTimerFunc(0, update, 40000);
     //   printf("%f %f\n",white[0].velocity_x,white[0].velocity_y);
    }
    if(key == 'r')
    {
        dec_coins();
    }
    if(key == 13)
    {
        lift_x = 0.0f;
        lift_y = 0.0f;
        flag=11;
    }

    if(key == 97 && lift_x >=-0.7 && lift_x<=0.7 && lift_y>=-0.7 && lift_y<=0.7)
        lift_x -= 0.01f;
    if(key == 115 && lift_x >=-0.7 && lift_x<=0.7 && lift_y>=-0.7 && lift_y<=0.7)
        lift_y -= 0.01f;
    if(key == 100 && lift_x >=-0.7 && lift_x<=0.7 && lift_y>=-0.7 && lift_y<=0.7)
        lift_x += 0.01f;
    if(key == 119 && lift_x >=-0.7 && lift_x<=0.7 && lift_y>=-0.7 && lift_y<=0.7)
        lift_y += 0.01f;
    if(lift_y < -0.7f)
        lift_y = -0.70;
    else if(lift_y > 0.7f)
        lift_y = 0.7f;
    else if(lift_x < -0.7f)
       lift_x = -0.7f;
    else if(lift_x > 0.3f)
        lift_x = 0.3f;
    //printf("%f %f\n",lift_x,lift_y);
    return;
}

void handleKeypress2(int key, int x, int y) 
{

    if(key == GLUT_KEY_UP && pointer <= 0.65)
    {
        pointer += 0.07; 
    }
    if(key == GLUT_KEY_DOWN && pointer >= -0.7)
    {
        pointer -= 0.07;
    }
    if (key == GLUT_KEY_LEFT && white[0].centre_x >=-0.57f && white[0].centre_x <= 0.13f)
        white[0].centre_x -= 0.01;
    else if (key == GLUT_KEY_RIGHT && white[0].centre_x >= -0.57f && white[0].centre_x <= 0.13f)
        white[0].centre_x += 0.01;
    else if (white[0].centre_x < -0.57)
        white[0].centre_x = -0.57;
    else if (white[0].centre_x > 0.13)
        white[0].centre_x = 0.13;
}

