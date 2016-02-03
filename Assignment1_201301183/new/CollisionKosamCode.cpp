for(int i=0;i<10;i++)
	{
		for(int j=i+1;j<10;j++)
		{
			float a = c[i].posX - c[j].posX;
			float b = c[i].posY - c[j].posY;
			float sumrad = c[i].radius + c[j].radius ;
			float sqrrad = sumrad * sumrad ;
			float distsqr = (a * a) + (b * b);
			if( distsqr <= sqrrad )
			{
			
				float collision[2];
				collision[0]=a;
				collision[1]=b;
				float distance = sqrt((a*a) + (b*b)) ;
				float unor[2];   unor[0]=collision[0]/distance;  unor[1] = collision[1]/distance;
				float u1[2]; u1[0]=c[i].spdX; u1[1]=c[i].spdY;
				float u2[2]; u2[0]=c[j].spdX; u2[1]=c[j].spdY;
				float utang[2]; utang[0]=-1*unor[1]; utang[1]=unor[0];
				float u1n = unor[0] * u1[0] + unor[1] * u1[1];
				float u1t = utang[0] * u1[0] + utang[1] * u1[1];
				float u2n = unor[0] * u2[0] + unor[1] * u2[1];
				float u2t = utang[0] * u2[0] + utang[1] * u2[1];	
				float v1n = (u1n * (c[i].mass - c[j].mass)+ (2 * c[j].mass * u2n))/(c[i].mass + c[j].mass);
				float v2n = (u2n * (c[j].mass - c[i].mass)+ (2 * c[i].mass * u1n))/(c[i].mass + c[j].mass);
				float v1nf[2]; v1nf[0] = v1n * unor[0]; v1nf[1] = v1n * unor[1];
				float v1tf[2]; v1tf[0] = u1t * utang[0]; v1tf[1] = u1t * utang[1];
				float v2nf[2]; v2nf[0] = v2n * unor[0]; v2nf[1] = v2n * unor[1];
				float v2tf[2]; v2tf[0] = u2t * utang[0]; v2tf[1] = u2t * utang[1];
				float v1[2]; v1[0] = v1nf[0] + v1tf[0];  v1[1] = v1nf[1] + v1tf[1];
				float v2[2]; v2[0] = v2nf[0] + v2tf[0];  v2[1] = v2nf[1] + v2tf[1];
				c[i].spdX = v1[0];
				c[i].spdY = v1[1];
				c[j].spdX = v2[0];
				c[j].spdY = v2[1];
				c[i].spdX *= 0.98;
				c[i].spdY *= 0.98;
				c[j].spdX *= 0.98;
				c[j].spdY *= 0.98;
				c[i].posX += c[i].spdX;
				c[i].posY += c[i].spdY;
				c[j].posX += c[j].spdX;
				c[j].posY += c[j].spdY;

			}
		}
		c[i].spdX *= 0.98;
		c[i].spdY *= 0.98;
		c[i].posX += c[i].spdX;
		c[i].posY += c[i].spdY;
	}
