#include<stdio.h>
#include <GLUT/glut.h>
#include<math.h>
#define pi 3.142857
// to change code, change global parameters, in main func change coordinates, add the coords in gl polygon
//in mat mul code, column/row will change acc to max cols/rows. 

int r_mat_init = 3;
int f_mat[3][4];
int c_mat_init = 4;
int r_mat_transf =3;
int c_mat_transf =3;
int mat[3][4];
int tx = 200;
int ty = 200;

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

void display_translation()
{

	// translation:
    int t_mat[3][3];
    for(int i=0;i<r_mat_transf;i++)
    {
    	for(int j=0;j<c_mat_transf;j++)
    	{
    		if(i==j)
    		{
    			t_mat[i][j]=1;
    		}
    		else
    		{
    			t_mat[i][j]=0;
    		}
    	}
    }
    t_mat[0][2]=tx;
    t_mat[1][2]=ty;


    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    glLineWidth(5);

    glBegin(GL_POLYGON);

     // glVertex2i(0, 0);
     glColor3f(0, 1, 1);
     glVertex2f(mat[0][0], mat[1][0]);
     glVertex2f(mat[0][1], mat[1][1]);
     glVertex2f(mat[0][2], mat[1][2]);
     glVertex2f(mat[0][3], mat[1][3]);
     glEnd();


    for (int i = 0; i < r_mat_transf; i++)
    {
        for (int j = 0; j < c_mat_init; j++) 
        {
            f_mat[i][j] = 0;
  
            for (int k = 0; k < r_mat_init; k++)
            {
                f_mat[i][j] += t_mat[i][k] * mat[k][j];
            }
  
        }
  
    }


    glBegin(GL_POLYGON);

     // glVertex2i(0, 0);
     glColor3f(1, 0, 1);
     glVertex2f(f_mat[0][0], f_mat[1][0]);
     glVertex2f(f_mat[0][1], f_mat[1][1]);
     glVertex2f(f_mat[0][2], f_mat[1][2]);
     glVertex2f(f_mat[0][3], f_mat[1][3]);
     glEnd();
 
        glFlush();

}



int main (int argc, char** argv)
{
	mat[0][0]=0;
	mat[1][0]=0;
	mat[0][1]=0;
	mat[1][1]=100;
	mat[0][2]=100;
	mat[1][2]=100;
	mat[0][3]=100;
	mat[1][3]=0;
	mat[2][0]=1;
	mat[2][1]=1;
	mat[2][2]=1;
	mat[2][3]=1;
	glutInit(&argc, argv); // start

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// giving window size in X- and Y- direction
	//glutInitWindowSize(1000, 768);
	glutInitWindowSize(900, 300);
	glutInitWindowPosition(200, 100);

	// Giving name to window
	glutCreateWindow("translation");
	myInit();

	glutDisplayFunc(display_translation);
	glutMainLoop();
}
