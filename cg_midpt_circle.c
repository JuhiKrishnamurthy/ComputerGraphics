#include <stdio.h>
#include <GLUT/glut.h>

int pntX1=200;
int pntY1=200;
int r = 100;

void myInit (void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(5);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-780, 780, -420, 420);
}


void midPointCircleAlgo()
{
	int x = 0;
	int y = r;
	float decision = 5/4 - r;
	glBegin(GL_POLYGON);
	while (y > x)
	{
		if (decision < 0)
		{
			x++; 
			decision += (2*x)+1;
		}
		else
		{
			y--;
			x++;
			decision += 2*(x-y)+1;
		}
		glColor3f(0, 1, 1);
		glVertex2d(x+pntX1, y+pntY1);
		glVertex2d(x+pntX1, -y+pntY1);
		glVertex2d(-x+pntX1, y+pntY1);
		glVertex2d(-x+pntX1, -y+pntY1);
		glVertex2d(y+pntX1, x+pntY1);
		glVertex2d(-y+pntX1, x+pntY1);
		glVertex2d(y+pntX1, -x+pntY1);
		glVertex2d(-y+pntX1, -x+pntY1);
	}
	glEnd();
    glFlush();

}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);

	midPointCircleAlgo();

	glFlush ();
}

void main(int argc, char** argv)
{	

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (900, 300);
	glutInitWindowPosition (200, 100);
	glutCreateWindow ("mid point circle");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();

}