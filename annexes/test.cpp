#include <GL/glut.h>
#include <iostream>
#include <libio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void draw()
{
    float d2r;
    // Angle de révolution autour de la Terre
    static float theta = 0.0, thetar;
    d2r = 3.1415926535 / 180.0;

    thetar = theta * d2r;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glTranslatef(0.0, 0.0, -100.0);
    glColor3ub(10, 20, 230);                      // Terre
    glutSolidSphere(6.3f, 35, 35);

    glColor3ub(200, 200, 200);               // Lune
    glTranslatef(30.0 * sin(thetar * 0.5), 0.0, 30.0 * cos(thetar * 0.5));
    glutSolidSphere(1.7f, 35, 35);

    theta += 1.0;
    glutSwapBuffers(); //motion = swap + redraw
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode ( GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, (float) w / h, 1.0, 1000.0);
	glMatrixMode ( GL_MODELVIEW);
	glLoadIdentity();
}

void TimerFunc(int value)
{
    glutPostRedisplay();
    glutTimerFunc(50, TimerFunc, 1);
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
    glMatrixMode( GL_PROJECTION );
	glutCreateWindow("Test");

    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);

    glEnable(GL_DEPTH_TEST);

    glutTimerFunc(50, TimerFunc, 1);
    glutMainLoop();
    return 0;
}
