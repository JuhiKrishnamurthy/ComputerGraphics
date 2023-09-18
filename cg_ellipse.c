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
    glColor3f(0.0, 1.0, 1.0);

    // breadth of picture boundary is 1 pixel
    glPointSize(5);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // setting window dimension in X- and Y- direction
    gluOrtho2D(-780, 780, -420, 420);
//  gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

void drawEllipse()
{
    glClear(GL_COLOR_BUFFER_BIT);
    int x = 0, y = b;
    float p = (b * b) - (a * a * b) + (0.25 * a * a);
    glVertex2d(x + xc, y + yc);  // plot the first point

    while ((2 * b * b * x) <= (2 * a * a * y)) 
    {
        glBegin(GL_POLYGON);  // begin drawing points
        glColor3f(1.0f, 0.0f, 0.0f);  // set color to red
        x++;
        if (p < 0)
        {
            p += (2 * b * b * x) + (b * b);
        } else 
        {
            y--;
            p += (2 * b * b * x) - (2 * a * a * y) + (b * b);
        }
        glVertex2d(x + xc, y + yc);
        glVertex2d(-x + xc, y + yc);
        glVertex2d(x + xc, -y + yc);
        glVertex2d(-x + xc, -y + yc);
    }

    p = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;

    while (y > 0)
     {
        glBegin(GL_POLYGON);  // begin drawing points
        glColor3f(1.0f, 0.0f, 0.0f);
        y--;
        if (p > 0)
        {
            p += -2 * a * a * y + a * a;
        } 
        else 
        {
            x++;
            p += 2 * b * b * x - 2 * a * a * y + a * a;
        }
        glVertex2d(x + xc, y + yc);
        glVertex2d(-x + xc, y + yc);
        glVertex2d(x + xc, -y + yc);
        glVertex2d(-x + xc, -y + yc);
    }

    glEnd();  // end drawing points

}
void drawEllipse2(float xc=0, float yc=0, float a=100, float b=200){
    glColor3f(1.0f, 0.0f, 0.0f);  // set color to red
    glBegin(GL_POINTS);  // begin drawing points

    int x = 0, y = b;
    float p = b * b - a * a * b + 0.25 * a * a;

    glVertex2d(x + xc, y + yc);  // plot the first point

    while ((2 * b * b * x) <= (2 * a * a * y)) {
        x++;
        if (p < 0) {
            p += 2 * b * b * x + b * b;
        } else {
            y--;
            p += 2 * b * b * x - 2 * a * a * y + b * b;
        }
        glVertex2d(x + xc, y + yc);
        glVertex2d(-x + xc, y + yc);
        glVertex2d(x + xc, -y + yc);
        glVertex2d(-x + xc, -y + yc);
    }

    p = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;

    while (y > 0) {
        y--;
        if (p > 0) {
            p += -2 * a * a * y + a * a;
        } else {
            x++;
            p += 2 * b * b * x - 2 * a * a * y + a * a;
        }
        glVertex2d(x + xc, y + yc);
        glVertex2d(-x + xc, y + yc);
        glVertex2d(x + xc, -y + yc);
        glVertex2d(-x + xc, -y + yc);
    }

    glEnd();  // end drawing points

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
    glutCreateWindow("ellipse");
    myInit();
    glutDisplayFunc(drawEllipse2());
    glutMainLoop();
}