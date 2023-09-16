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
	glColor3f(1.0, 1.0, 1.0);

	// breadth of picture boundary is 1 pixel
	glPointSize(5);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// setting window dimension in X- and Y- direction
	gluOrtho2D(-780, 780, -420, 420);
//	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}
void display1()
{
	glClear(GL_COLOR_BUFFER_BIT);
    
	int p = 200;
	int q = 200;
	int r = 100;
	int x =0;
	int y=r;
	int d = 3-(2*r);

	glBegin(GL_POLYGON);
	while(x<y)
	{
		glColor3f(0, 1, 1);
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
	glutCreateWindow("CIRCLE");
	myInit();

	glutDisplayFunc(display1);
	glutMainLoop();
}