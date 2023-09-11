#include<stdio.h>
#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<GLUT/glut.h>
using namespace std;

// #ifdef _APPLE_
// #include<openGL/openGL.h>
// #include<GLUT/glut.h>
// #else
// //#include<GL/glut.h>
// #endif

//using namespace std;

float sliderX = 0.5f;
float sliderY = -0.5f;
float sliderZ = -1.0f;
int gamestop=0;
/*
float ballX2 = 0.3f;
float ballY2 = 0.0f;
float ballZ2 = -1.0f;
*/
class Brick{
protected:
    
public:
    float x0;
    float y0;
    float x1;
    float y1;
    float r;
    float g;
    float b;
    float points;
    

    Brick(float ix0=0,float iy0=0,float ix1=0,float iy1=0,float ir=0,float ig=0,float ib=0)
    {
        x0=ix0;
        y0=iy0;
        x1=ix1;
        y1=iy1;
        r=ir;
        g=ig;
        b=ib;
        points = find_points(r,g,b);

    }
    ~Brick()
    {
        return;
    }

    int find_points(float rcol,float gcol,float bcol)
    {
        int pts=0;
        if((rcol==1)&&(bcol==0)&&(gcol==0))
        {
            pts = 1;
        }

        else if((rcol==0)&&(bcol==1)&&(gcol==0))
        {
            pts = 2;
        }
        else if((rcol==0)&&(bcol==0)&&(gcol==1))
        {
            pts = 3;
        }
        else if((rcol==1)&&(bcol==0)&&(gcol==1))
        {
            pts = 4;
        }
        return pts;

    }

    void Draw()
    {
        float hor_dist=x1-x0;
        float ver_dist=y1-y0;
        float ldx=x0;
        float ldy=y0;
        float rdx=x0+hor_dist;
        float rdy=y0;
        float lux=x0;
        float luy=y0+ver_dist;
        float rux=x0+hor_dist;
        float ruy=y0+ver_dist;
        glColor3f(r, g, b); //set brick colour
        //glTranslatef(sliderX,sliderY,sliderZ);//moving it toward the screen a bit on creation
        //glutSolidSphere (0.1, 20,50);//eate ball.
        glPointSize(10);
        glBegin(GL_POLYGON);
            glVertex2f(ldx,ldy);
            glVertex2f(rdx,rdy);
            glVertex2f(rux,ruy); 
            glVertex2f(lux,luy); 
            glEnd();
        glFlush();
    }
    
};

class Ball{

    protected:

    public:
        float radius;
        float no_slices;
        float no_stacks;
        float x;
        float y;
        float r;
        float g;
        float b;
        float vx;
        float vy;

        Ball(float irad=0,float ix=0,float iy=0,float ir=0,float ig=0,float ib=0,float ivx=0,float ivy=0)
        {
            radius=irad;
            x=ix;
            y=iy;
            r=ir;
            g=ig;
            b=ib;
            vx=ivx;
            vy=ivy;

        }
        ~Ball()
        {
            return;
        }

        void Draw()
        {
            // glTranslatef(sliderX,sliderY,sliderZ);
            glColor3f(r, g, b);
            glPointSize(10);
            // glPointSize(10);
            // glutSolidSphere (radius, no_slices,no_stacks);
            // cout<<"DRAWN\n";
            // glFlush();
            float angle_theta;
            glBegin(GL_POLYGON);
     
            // Iterate through all the
            // 360 degrees
            for (int i = 0; i < 360; i++) {
     
                // Find the angle
                //cout<<i<<"\n";
                angle_theta = i * float(3.142 / 180);
                glVertex2f(x + radius * cos(angle_theta),
                           y + radius * sin(angle_theta));
                //cout<<"in loop\n";
            }
            
            // Sets vertex
            glEnd();
            glFlush();
            //cout<<"Drawn!";
        }


        void update_ball_state(float new_pos_x,float new_pos_y,float new_vx, float new_vy)
        {
            x=new_pos_x;
            y=new_pos_y;
            vx=new_vx;
            vy=new_vy;
        }

};


int totalPoints =0;
list<Brick> brick_List;
Ball theball(0.03,0,0,0,0,0);
//The slider or paddle is just a brick with white color
Brick thepaddle(-0.1,-0.9,0.1,-0.8,1.0,1.0,1.0);

void lay_row(float bly,float brick_width, float brick_height)
{
    float low_x_left=-1;
    while(low_x_left<1)
    {
        int r=0;
        int g=0;
        int b=0;
        int max=4;
        int min=1;
        int range = max - min + 1;
        int num = rand() % range + min;
        if(num==1)
        {
            r=1;
            g=0;
            b=0;
        }
        if(num==2)
        {
            r=0;
            g=1;
            b=0;
        }
        if(num==3)
        {
            r=0;
            g=0;
            b=1;
        }
        if(num==4)
        {
            r=1;
            g=1;
            b=0;
        }
        Brick B(low_x_left,bly,low_x_left+brick_width,bly+brick_height,r,g,b);
        brick_List.push_back(B);
        low_x_left=low_x_left+brick_width;
    }

}

void make_init_brick_list(int nrows,int no_brik_per_row,float proportion)
{
    float brick_width=2.0/no_brik_per_row;
    float brick_height=proportion/nrows;
    float x0_init= -1;
    float y0_init=1 - proportion;
    float x1_init = x0_init+brick_width;
    float y1_init = y0_init+brick_height;
    float bly=y0_init;
    while(bly<1)
    {
        lay_row(bly,brick_width,brick_height);
        bly+=brick_height;
    }
    
}



void Draw_Bricks()
{
    for(auto it = brick_List.begin();it!=brick_List.end();it++)
    {
        it->Draw();
    }
}



bool check_collision_left_wall()
{
    if( (theball.x <= -1) && (theball.vx <0.0))
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool check_collision_right_wall()
{
    if( (theball.x >= 1.0) && (theball.vx >0.0))
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool check_collision_bottom_wall()
{
    if( (theball.y <= -1.0) && (theball.vy <0.0))
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool check_collision_top_wall()
{
    if( (theball.y >= 1.0) && (theball.vy >0.0))
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool check_collison_anti_diag_corner()
{
    if  ( (check_collision_bottom_wall() && check_collision_left_wall()) ||
         
          (check_collision_top_wall() && check_collision_right_wall()) 
          
          )
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool check_collison_diag_corner()
{
    if  ( 
          (check_collision_bottom_wall() && check_collision_right_wall()) ||
          (check_collision_top_wall() && check_collision_left_wall()) 
          
          )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check_collision_paddle()
{
    // if the lowest part of ball is on the top line of the paddle
    if ( ((theball.y - theball.radius) < thepaddle.y1) &&
         (theball.x >= thepaddle.x0) && (theball.x <= thepaddle.x1)
         )
    {
        return true;
    }

    return false;
}

bool check_collision_brick()
{
    //we will change state also in this function if a collision is detected
    for(auto it = brick_List.begin();it!=brick_List.end();it++)
    {
        // if the top part of the ball touches  lower line of this brick we have a collision
         if ( ((theball.y + theball.radius) >= it->y0) &&
               (theball.x >= it->x0) && (theball.x <= it->x1)
         )
        {
            //Change the state remove brick, update points, update ball position and velocity
            totalPoints += it->points;
            cout <<"Points Earned = " <<totalPoints <<"\n"; 
            brick_List.erase(it);
            //this is like reflection from top
            theball.vx= theball.vx;
            theball.vy = -theball.vy;
            return true;
        }

    }

    return false;
}

void donothing(int key, int x, int y)
{
    return;
}

void stopgame()
{
    gamestop=1;
    cout<<"GAME LOST.\n"<<"YOUR TOTAL SCORE IS: "<<totalPoints<<flush;
    glutSpecialFunc(donothing);
    return;
}


void compute_new_pos_and_vel(int time_elapsed)
{
    //cout<<"old "<<theball.x<<" "<<theball.y<<"\n";
    if(gamestop==1)
    {
        return;
    }
    float oldx = theball.x;
    float oldy = theball.y;

    float nx = theball.x + theball.vx * time_elapsed;
    float ny = theball.y + theball.vy * time_elapsed;
    theball.x=nx;
    theball.y=ny;
    //cout<<"new "<<theball.x<<" "<<theball.y<<"\n";
    
    if (check_collison_diag_corner())
    {
        float tvx = theball.vx;
        float tvy = theball.vy ;
        theball.vx= tvy;
        theball.vy = tvx;
        cout<< "diag corner velocity(" << theball.vx <<","<< theball.vy <<" )\n";
        cout<< "diag corner position (" << theball.x <<","<< theball.y <<" )\n";
        cout << "old pos = ( " << oldx  << "," << oldy <<" )\n";
        cout << "next pos = ( " << theball.x + theball.vx * time_elapsed << "," << theball.y + theball.vy * time_elapsed <<" )\n";

    }
    else if (check_collison_anti_diag_corner())
    {

        float tvx = theball.vx;
        float tvy = theball.vy ;
        theball.vx= -tvy;
        theball.vy = -tvx;
        cout<< "anti daig corner velocity (" << theball.vx <<","<< theball.vy <<" )\n";
        cout<< "diag corner position (" << theball.x <<","<< theball.y <<" )\n";
        cout << "old pos = ( " << oldx  << "," << oldy <<" )\n";
        cout << "next pos = ( " << theball.x + theball.vx * time_elapsed << "," << theball.y + theball.vy * time_elapsed <<" )\n";
    }
    else if (check_collision_left_wall())
    {
        //leftwall
        //compute the normal to the position,
        //reflect vx and vy along normal
        theball.vx= -theball.vx;
        theball.vy = theball.vy;
        //return;
    } 
    else if(check_collision_right_wall())
    {
        //rightwall
        theball.vx= -theball.vx;
        theball.vy = theball.vy;
        //return;
    } 
    else if(check_collision_top_wall())
    {
        //topwall
        theball.vx= theball.vx;
        theball.vy = -theball.vy;
        //return;
    }
    else if(check_collision_bottom_wall())
    {
        //bottomwall
        // theball.vx= theball.vx;
        // theball.vy = -theball.vy;
        stopgame();
        return ;

    } 
    else if(check_collision_paddle())
    {
        //paddle
        theball.vx= theball.vx;
        theball.vy = -theball.vy;
        //return;
    }
    else 
    {
        check_collision_brick();
        //
    }

    glutPostRedisplay(); 
    glutTimerFunc(25, compute_new_pos_and_vel, 25);
    return;

}


void keyPress(int key, int x, int y)
{
    if ( (key==GLUT_KEY_RIGHT) && ( thepaddle.x1 < 1.0))
    {
        thepaddle.x0 += 0.1f;
        thepaddle.x1 += 0.1f;
        if (thepaddle.x1 > 1.0)
        {
            float excess = thepaddle.x1 - 1.0;
            thepaddle.x0 -= excess;
            thepaddle.x1 -=excess;
        }
    }
    if((key==GLUT_KEY_LEFT)&&( thepaddle.x0 > -1.0))
    {
        thepaddle.x0 -= 0.1f;
        thepaddle.x1 -= 0.1f;
        if (thepaddle.x0 < -1.0)
        {
            float excess = -1.0 - thepaddle.x0;
            thepaddle.x0 += excess;
            thepaddle.x1 +=excess;
        }
       
    }
    glutPostRedisplay();
}

void initRendering()
{
    //glEnable(GL_DEPTH_TEST);

    glClearColor(1.0, 0.0, 1.0, 1.0);

    // making picture color green (in RGB mode), as middle argument is 1.0
    glColor3f(0.0, 1.0, 0.0);

    // breadth of picture boundary is 1 pixel
    glPointSize(10);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // setting window dimension in X- and Y- direction
    //gluOrtho2D(-780, 780, -420, 420);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}


//Called when the window is resized
void handleResize(int w, int h) {
    //Tell OpenGL how to convert from coordinates to pixel values
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective

    //Set the camera perspective
    glLoadIdentity(); //Reset the camera
    gluPerspective(45.0,                  //The camera angle
                   (double)w / (double)h, //The width-to-height ratio
                   1.0,                   //The near z clipping coordinate
                   200.0);                //The far z clipping coordinate
}


void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    Draw_Bricks();
   

    theball.Draw();
    thepaddle.Draw();
    if(gamestop==1)
    {
        return;
    }
    glutPostRedisplay();
    glutTimerFunc(25, compute_new_pos_and_vel, 25);

    glutSwapBuffers();
}


int main(int argc,char** argv)
{
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

    glutInitWindowSize(400,400);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("ARKANOID GAME");

    initRendering();

    srand(std::time(0));
    make_init_brick_list(4,8,0.25);

    //Set the ball's initial position and velocity
    theball.x = 0.5;
    theball.y=0;
    theball.vx =sqrt(2.0)/2.0*1e-3;
    theball.vy = -1e-3;

    glutSpecialFunc(keyPress);

    glutDisplayFunc(drawScene);
    cout<<"WELCOME TO ARKANOID!\n";
    
    //glutReshapeFunc(handleResize);
    //autorot();

    //glutTimerFunc(25, update, 0);

    glutMainLoop();

    return(0);
}