#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>

int bckg=0,boat=0,wflag=1;
int n,mov;

void circle()
{
	float x1=1250,y1=1650,x2=10,y2=10;
	float angle;
	double radius=100;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1,y1);
	for (angle=1.0f;angle<361.0f;angle+=0.2)
	{
		x2 = x1+sin(angle)*radius;
		y2 = y1+cos(angle)*radius;
		glVertex2f(x2,y2);
	}
	glEnd();
	glutPostRedisplay();
	glFlush();
}

//To draw user BOAT
void drawboat()
{
	glColor3f(0.1,0.0,0.1);
	glBegin(GL_POLYGON);
	glVertex2f(700+n,950);
	glColor3f(.6,0.5,0.0);
	glVertex2f(800+n,800);
	glVertex2f(1200+n,800);
	glColor3f(0.1,0.0,0.1);
	glVertex2f(1400+n,950);
	glEnd();

    glColor3f(.6,0.5,0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(1200+n,950);
	glColor3f(.6,0.5,0.5);
	glVertex2f(1350+n,950);
	glColor3f(.0,0.2,0.6);
	glVertex2f(1000+n,1150);
	glEnd();
	glPointSize(9.0);
	glBegin(GL_LINES);
	glVertex2f(1000+n,950);
	glVertex2f(1000+n,1150);
	glEnd();

	glColor3f(0.1,0.0,0.1);
	glBegin(GL_POLYGON);
	glVertex2f(850+n,950);
	glVertex2f(1000+n,950);
	glVertex2f(1000+n,1000);
	glVertex2f(850+n,1000);
	glEnd();
}
void redrawboat()
{	if(boat==0)
	{
		if(n<1600)
		{

			n+=2;
			glutPostRedisplay();
		}
		else
		{	n=n-2400;
		glutPostRedisplay();
		}
	}
}

void redrawcar()
{	if(boat==0)
	{
		if(mov<1600)
		{

			mov+=2;
			glutPostRedisplay();
		}
		else
		{	mov=mov-2400;
		glutPostRedisplay();
		}
	}
}

void init()
{	
	glClearColor(.8,.5,0.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,2200.0,0.0,1800.0);
	glutPostRedisplay();
}

//To draw Mountain for DAY
void mountain()
{
	glColor3f(0.60,0.40,0.12);
    glBegin(GL_TRIANGLES);
	glVertex2f(250,1300);
	glColor3f(0.55,0.40,0.12);
	glVertex2f(0,1600);
	glColor3f(0.55,0.40,0.12);
	glVertex2f(0,1300);
	glEnd();
	glColor3f(0.60,0.40,0.12);
	glBegin(GL_POLYGON);
	glVertex2f(100,1300);
	glVertex2f(300,1600);
	glVertex2f(400,1600);
	glColor3f(0.55,0.40,0.12);
	glVertex2f(500,1650);
	glVertex2f(700,1630);
	glColor3f(0.55,0.40,0.12);
	glVertex2f(900,1300);
	glEnd();

	glColor3f(0.60,0.40,0.12);
	glBegin(GL_TRIANGLES);
	glVertex2f(300,1300);
	glColor3f(0.50,0.40,0.12);
	glVertex2f(700,1680);
	glColor3f(0.55,0.40,0.12);
	glVertex2f(900,1300);
	glEnd();
	
	glColor3f(0.60,0.42,0.12);
	glBegin(GL_POLYGON);
	glVertex2f(500,1300);
	glVertex2f(700,1500);
	glColor3f(0.50,0.40,0.12);
	glVertex2f(900,1650);
	glVertex2f(1300,1500);
	glColor3f(0.55,0.40,0.12);
	glVertex2f(1500,1450);
	glVertex2f(1600,1300);
	glEnd();

	glColor3f(0.62,0.42,0.12);
	glBegin(GL_POLYGON);
	glVertex2f(1400,1300);
	glVertex2f(1800,1600);
	glColor3f(0.50,0.40,0.12);
	glVertex2f(1850,1650);
	glVertex2f(1900,1600);
	glColor3f(0.55,0.40,0.12);
	glVertex2f(2000,1300);
	glColor3f(0.62,0.42,0.13);
	glBegin(GL_TRIANGLES);
	glVertex2f(2000,1300);
	glColor3f(0.50,0.40,0.12);
	glVertex2f(2200,1600);
	glColor3f(0.55,0.40,0.12);
	glVertex2f(2200,1300);
}

void draw_pixel(GLint cx,GLint cy)
{	
	glPolygonMode(GL_FRONT,GL_FILL);
	glBegin(GL_POINTS);
	glVertex2i(cx,cy);
	glEnd();
}



void plotpixels(GLint h,GLint k,GLint x,GLint y)
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

void circle_draw(GLint h,GLint k,GLint r)
{
	GLint d=1-r,x=0,y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0)
			d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}

void drawcar()
{
	glColor3f(0.1,0.0,0.1);

	glBegin(GL_POLYGON);
	glVertex2f(250+mov,450);
	glVertex2f(250+mov,400);
	
	glColor3f(1.0,0.0,0.0);
	glVertex2f(250+mov,300);
	glColor3f(0.1,0.0,0.2);
	glVertex2f(450+mov,300);

	glVertex2f(450+mov,400);
	glVertex2f(400+mov,450);
	glEnd();
	glColor3f(0.1,0.0,0.0);
	circle_draw(285+mov,300,12);
	circle_draw(385+mov,300,12);
}

//To Draw Mountain for Night

void mountain2()
{
	glColor3f(0.60,0.40,0.12);
    glBegin(GL_TRIANGLES);
	glVertex2f(250,1300);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(0,1600);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(0,1300);
	glEnd();

	glColor3f(0.60,0.40,0.12);
	glBegin(GL_POLYGON);
	glVertex2f(100,1300);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(300,1600);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(400,1600);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(500,1650);
	glVertex2f(700,1630);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(900,1300);
	glEnd();

	glColor3f(0.60,0.40,0.12);
	glBegin(GL_TRIANGLES);
	glVertex2f(300,1300);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(700,1680);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(900,1300);
	glEnd();

	glColor3f(0.60,0.42,0.12);
	glBegin(GL_POLYGON);
	glVertex2f(500,1300);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(700,1500);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(900,1650);
	glVertex2f(1300,1500);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(1500,1450);
	glVertex2f(1600,1300);
	glColor3f(0.62,0.42,0.12);

	glBegin(GL_POLYGON);
	glVertex2f(1400,1300);
	glVertex2f(1800,1600);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(1850,1650);
	glVertex2f(1900,1600);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(2000,1300);
	glEnd();

	glColor3f(0.62,0.42,0.13);
	glBegin(GL_TRIANGLES);
	glVertex2f(2000,1300);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(2200,1600);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(2200,1300);
	glEnd();

	//to draw road for Night
	glColor3f(0.10,0.10,0.0);
	glBegin(GL_POLYGON);
	glColor3f(0.4,0.4,0.4);
	glVertex2f(0,200);
	glVertex2f(0,500);
	glVertex2f(2200,500);
	glVertex2f(22000,200);
	glEnd();

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(0,345);
	glVertex2f(200,345);
	glVertex2f(200,355);
	glVertex2f(00,355);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2f(300,345);
	glVertex2f(550,345);
	glVertex2f(550,355);
	glVertex2f(300,355);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(650,345);
    glVertex2f(900,345);
	glVertex2f(900,355);
	glVertex2f(650,355);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(1000,345);
	glVertex2f(1250,345);
	glVertex2f(1250,355);
	glVertex2f(1000,355);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2f(1600,345);
	glVertex2f(1350,345);
	glVertex2f(1350,355);
	glVertex2f(1600,355);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(1950,345);
	glVertex2f(1700,345);
	glVertex2f(1700,355);
	glVertex2f(1950,355);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(2300,345);
	glVertex2f(2050,345);
	glVertex2f(2050,355);
	glVertex2f(2300,355);
	glEnd();
	drawcar();
}


//To draw Sea for DAY
void drawsea()
{
	glColor3f(0.0,0.6,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(2200,900);
	glColor3f(0.0,0.7,1.0);
	glVertex2f(2200,800);
	glVertex2f(2200,750);
	glVertex2f(1900,700);
	glColor3f(0.0,0.7,1.0);
	glColor3f(.0,0.7,.9);
	glVertex2f(400,600);
	glColor3f(0.0,0.6,.9);
	glColor3f(.0,0.7,.9);
	glVertex2f(0,650);
	glVertex2f(0,1300);
	glEnd();
}

//To draw sea for NIGHT
void drawsea2()
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(2800,1300);
	glColor3f(.0,0.0,.0);
	glVertex2f(2200,750);
	glColor3f(0.0,0.0,0.0);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(400,600);
	glColor3f(0.0,0.0,.0);
	glVertex2f(0,650);
	glColor3f(.0,0.0,.0);
	glVertex2f(0,1300);
	glEnd();
}

void night()
{	
	// to set the background color to black
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(2200,1800);
	glVertex2f(0,1800);
	glVertex2f(0,0);
	glVertex2f(2200,0);
	glEnd();

	//to draw the stars
	glPointSize(5.0);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POINTS);
	glVertex2f(900,1700);
	glVertex2f(800,1700);
	glVertex2f(200,1500);
	glVertex2f(1800,1700);
	glVertex2f(2000,1500);
	glEnd();
	mountain2();
	glColor3f(.7,.7,.7);
	drawsea2();

	//to draw boat
	drawboat();

	//to draw the moon
	glPointSize(9.0);
	glColor3f(1.0,1.0,1.0);
	circle();
}

void renderBitmapString(float x,float y,float z,void *font,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);
	for(c=string;*c!='\0';c++)
		glutBitmapCharacter(font,*c);
}

// keyboard function
void key(unsigned char key,int x,int y)
{
	if(key==13)
	{
		wflag=9;
		glutPostRedisplay();
	}
	if(key=='x')
	{
   	 n=n+10;
   	 if(n>2000) 
		 n=-800;
     glutPostRedisplay();
	}
	if(key=='f')
	{
   	 mov=mov+10;
   	 if(mov>2000) 
		 mov=-800;
     glutPostRedisplay();
	}

	if(key=='y')
	{
	n=n-10;
	if(n<-1400) 
		n=1400;
	glutPostRedisplay();
	}
	if(key=='s') //to stop boat
	{	boat=1;
		glutPostRedisplay();
	}
	if(key=='r') // to restart boat
	{	boat=0;
		glutPostRedisplay();
	}
}


void day()
{	//to set the sky color and ground color
	glColor3f(.8,.37,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(2200,1800);
	glColor3f(.7,.37,0.0);
	glVertex2f(0,1800);
	glColor3f(.4,.6,0.0);
	glVertex2f(0,0);
	glColor3f(.4,.6,0.0);
	glVertex2f(2200,0);
	glEnd();
	// to draw the mountains
	mountain();
	// to draw the sea
	drawsea();
	drawboat();
	//to draw road DAY
	glColor3f(0.10,0.10,0.0);
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(0,200);
	glVertex2f(0,500);
	glVertex2f(2200,500);
	glVertex2f(22000,200);
	glEnd();

	glColor3f(1.0,1.0,1.0);
	
	int j=0;
	for(int k=0;k<8;k++)
	{
		glBegin(GL_POLYGON);
	glVertex2f(0+j,345);
	glVertex2f(200+j,345);
	glVertex2f(200+j,355);
	glVertex2f(0+j,355);
	glEnd();
	j=j+300;
	}
	drawcar();
	// to draw the sun
	glPointSize(9.0);
	glColor3f(.9,0.2,0.0);
	circle();
	
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	if(wflag==1)
	{
	glColor3f(0.0,0.5,0.7);
	glRectf(0.0,0.0,100.0,10.0);//top
	glRectf(0.0,100.0,100.0,90.0);//bottom

	glColor3f(1.0,1.0,1.0);
	renderBitmapString(850,1500,0,GLUT_BITMAP_HELVETICA_18,"KLE INSTITUTE OF TECHNOLOGY, HUBLI");
	renderBitmapString(825,1400,0,GLUT_BITMAP_HELVETICA_18,"Department of Computer Science & Engineering");
	
	glColor3f(1.0,1.0,1.0);
	renderBitmapString(1100,1050,0,GLUT_BITMAP_HELVETICA_18,"BY");
	renderBitmapString(970,1000,0,GLUT_BITMAP_9_BY_15,"1. Prajwal V Shastrimath ");
	renderBitmapString(970,950,0,GLUT_BITMAP_9_BY_15,"2. Sachin M Sankonatti");
	
	glColor3f(1.0,1.0,0.0);
	renderBitmapString(875,1150,0,GLUT_BITMAP_9_BY_15,"A mini project on Computer Graphics");
	renderBitmapString(1050,1200,0,GLUT_BITMAP_TIMES_ROMAN_24,"Lake View");
	
	glColor3f(0.0,0.0,0.0);
	renderBitmapString(825,800,0,GLUT_BITMAP_9_BY_15,"KEY OPERATIONS:");
	renderBitmapString(825,700,0,GLUT_BITMAP_9_BY_15,"Press 'x' to move boat in +ve x-direction.");
	renderBitmapString(825,650,0,GLUT_BITMAP_9_BY_15,"Press 'y' to move boat in -ve x-direction.");
	renderBitmapString(825,600,0,GLUT_BITMAP_9_BY_15,"Press 's' to stop the car.");
	renderBitmapString(825,550,0,GLUT_BITMAP_9_BY_15,"Press 'r' to restart the car.");

	glColor3f(1.0,0.0,0.0);
	renderBitmapString(975,400,0,GLUT_BITMAP_9_BY_15,"Click ENTER to continue");
	glutSwapBuffers();
	glFlush();
	}
	else
	{
	if(bckg==1)
		night();
	if(bckg==0)
		day();
    redrawboat();
    redrawcar();
	glFlush();
	}
}


void mainmenu(int id)
{
	switch(id)
	{
		case 1:exit(0);
			break;
		case 2:bckg=0;
			break;
		case 3:bckg=1;
			break;

	}
	glutPostRedisplay();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(2200,1800);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Lake View");
	glutKeyboardFunc(key);
	glutDisplayFunc(display);
	glutCreateMenu(mainmenu);
	glutAddMenuEntry("EXIT",1);
	glutAddMenuEntry("DAY VIEW",2);
	glutAddMenuEntry("NIGHT VIEW",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	init();
	glutMainLoop();
	return 0;
}