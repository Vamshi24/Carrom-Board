int avinash ;
float str_angle;
void mouse(int button,int state,int x,int y)
{
	if(state == GLUT_DOWN)
	{
		if(button == GLUT_LEFT_BUTTON)
		{
			int ww = glutGet(GLUT_WINDOW_WIDTH);
			int wh = glutGet(GLUT_WINDOW_HEIGHT);
			float hw = (float)ww/2;
			float hh = (float)wh/2;
			float xx = ((float)x - hw)/hw;
			float yy = ((float)y - hh)/-hh;
			float yo = yy - s[0].a;
			float xo = xx - s[0].c;
			str_angle = atan(yo/xo) * 180/PI ;
			if(str_angle < 0.0)
			{
				str_angle += 180.0f;
			}
			if((yy >= -0.60f && xx >= -0.85) && (xx <= 0.85 && yy <= 0.85))
			{
				float dis = sqrt(1.60 * 1.60 + 1.50 * 1.50);
				float nw = sqrt((xx - s[0].a) * (xx - s[0].a) + (yy - s[0].c) * (yy - s[0].c));  
			//	indicator_ball += ((yy + 0.60) * 0.8)/1.45;
			}
		//	indicator_ball += 0.05;
		}

		if(button == GLUT_RIGHT_BUTTON)
		{
			avinash = 1;
		}
	}

	if(state == GLUT_UP)
	{
		if(button == GLUT_LEFT_BUTTON)
		{
			c[9].spdX = (0.1 * cos(DEG2RAD(str_angle));
			c[9].spdY = (0.1 * sin(DEG2RAD(str_angle));
		}

		if(button == GLUT_RIGHT_BUTTON)
		{
			avinash = 0;
		}
	}
}


void mouse_motion(int x,int y)
{

	int ww = glutGet(GLUT_WINDOW_WIDTH);
	int wh = glutGet(GLUT_WINDOW_HEIGHT);
	float hw = (float)ww/2;
	float hh = (float)wh/2;
	float ab = ((float)x - hw)/hw;
	float cd = ((float)y - hh)/-hh;
			if((ab <= 3.45 && ab >= -3.45) && (cd <= -0.35 && cd >= -0.45))
			{
				s[0].a = ab;	
			     //   c[9].posY = cd;
			}
}

glutMouseFunc(mouse);
glutMotionFunc(mouse_motion);
