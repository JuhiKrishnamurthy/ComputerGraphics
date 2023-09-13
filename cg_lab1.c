// C program to demonstrate
// drawing a circle using
// OpenGL
#include<stdio.h>
#include <GLUT/glut.h>
#include<math.h>
#define pi 3.142857

// function to initialize
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
    glColor3f(1, 0, 0);
    glLineWidth(5);

    glBegin(GL_POINTS);

     // glVertex2i(0, 0);
     glVertex2f(0.0, 0.0);
     // glVertex2i(20, 20);
     glVertex2f(200.0, 0.0);
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
	glutCreateWindow("2 points");
	myInit();

	glutDisplayFunc(display1);
	glutMainLoop();
}