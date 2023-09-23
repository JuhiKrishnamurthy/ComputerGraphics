#include<stdio.h>
#include <GLUT/glut.h>
#include<math.h>
#define pi 3.142857

void myInit (void)
{
    // making background color black as first
    // 3 arguments all are 0.0
    glClearColor(1.0, 1.0, 1.0, 1.0);

    // making picture color green (in RGB mode), as middle argument is 1.0
    glColor3f(0.0, 0.0, 0.0);

    // breadth of picture boundary is 1 pixel
    glPointSize(5);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // setting window dimension in X- and Y- direction
    gluOrtho2D(-780, 780, -420, 420);
//  gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}
void display1()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glLineWidth(5);

    glBegin(GL_POLYGON);

     // glVertex2i(0, 0);
     glColor3f(0, 0.1, 0.6);
     glVertex2f(100.0, 200.0);
     glVertex2f(100.0, 250.0);
     glVertex2f(400.0, 250.0);
     glVertex2f(500.0, 150.0);
     glVertex2f(400.0, 50.0);
     glVertex2f(250.0, 50.0);
     glEnd();

    glBegin(GL_POLYGON);

     // glVertex2i(0, 0);
     glColor3f(0, 0.1, 0.6);
     glVertex2f(180.0, 250.0);
     glVertex2f(150.0, 320.0);
     glVertex2f(200.0, 320.0);
     glVertex2f(300.0, 250.0);
     glEnd();

     glBegin(GL_POLYGON);

     // glVertex2i(0, 0);
     glColor3f(1, 1, 1);
     glVertex2f(420.0, 220.0);
     glVertex2f(450.0, 200.0);
     glVertex2f(380.0, 200.0);
     glVertex2f(380.0, 220.0);
     glEnd();

     glBegin(GL_POLYGON);

     // glVertex2i(0, 0);
     glColor3f(1, 1, 1);
     glVertex2f(250.0, 200.0);
     glVertex2f(380.0, 100.0);
     glVertex2f(300.0, 100.0);
     glVertex2f(200.0, 200.0);
     glEnd();
     
        glEnd();

	int p = 370;
	int q = 25;
	int r = 25;
	int x =0;
	int y=r;
	int d = 3-(2*r);

	glBegin(GL_POLYGON);
	while(x<y)
	{
		glColor3f(0, 0, 0);
		glVertex2d(x+p, y+q);
		glVertex2d(y+p, x+q); 
		glVertex2d(-y+p, x+q); 
		glVertex2d(-x+p, y+q);
		glVertex2d(-x+p, -y+q); 
		glVertex2d(-y+p, -x+q); 
		glVertex2d(y+p, -x+q); 
		glVertex2d(x+p, -y+q);
			
		if (d < 0)
		{
			d = d + 4*x + 6;
			x = x + 1;
		}
		if(d>=0)
		{
			d = d + 4*(x - y) + 10;
			x = x + 1;
			y = y - 1;
		}
	}
	glEnd();


	 p = 320;
	 q = 25;
	 r = 25;
	 x =0;
	 y=r;
	 d = 3-(2*r);

	glBegin(GL_POLYGON);
	while(x<y)
	{
		glColor3f(0, 0, 0);
		glVertex2d(x+p, y+q);
		glVertex2d(y+p, x+q); 
		glVertex2d(-y+p, x+q); 
		glVertex2d(-x+p, y+q);
		glVertex2d(-x+p, -y+q); 
		glVertex2d(-y+p, -x+q); 
		glVertex2d(y+p, -x+q); 
		glVertex2d(x+p, -y+q);
			
		if (d < 0)
		{
			d = d + 4*x + 6;
			x = x + 1;
		}
		if(d>=0)
		{
			d = d + 4*(x - y) + 10;
			x = x + 1;
			y = y - 1;
		}
	}

	glEnd();
    glFlush();
}
int main (int argc, char** argv)
{
	glutInit(&argc, argv); // start

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// giving window size in X- and Y- direction
	//glutInitWindowSize(1000, 768);
	glutInitWindowSize(900, 300);
	glutInitWindowPosition(200, 100);

	// Giving name to window
	glutCreateWindow("Plane");
	myInit();

	glutDisplayFunc(display1);
	glutMainLoop();
}