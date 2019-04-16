#include <cmath>
#include <cstdio>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <iostream>
#include <string>

#include "../inc/camera.h"
#include "../inc/earthMoonSystem.h"
#include "../inc/guide.h"
#include "../inc/planet.h"
#include "../inc/RGBpixmap.h"
#include "../inc/vect.h"

EarthMoonSystem s;

GLuint background = 0;

bool SCHEMATIC_MODE = false;

void makeImage(const char bitmapFilename[], GLuint textureName, bool hasAlpha)
{
	RGBpixmap pix;
	pix.readBMPFile(bitmapFilename, hasAlpha);
	pix.setTexture(textureName);
	return;
}

void make_image_moon_earth()
{
    makeImage("../bitmaps/earth.bmp", s.getTerre() -> getTexture(), false);
    makeImage("../bitmaps/moon.bmp", s.getLune() -> getTexture(), false);
	makeImage("../bitmaps/background.bmp", background, false);
}

void draw_background()
{
	GLUquadricObj* quadro = gluNewQuadric();
	gluQuadricNormals(quadro, GLU_SMOOTH);
	gluQuadricTexture(quadro, GL_TRUE);
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, background);
			gluSphere(quadro, 20, 50, 50);
		glPopMatrix();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	gluDeleteQuadric(quadro);
}

void normal_mode()
{
	// glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	draw_background();

	glPushMatrix();
		glRotatef(90, -1.0, 0.0, 0.0);
		glPushMatrix();
			glRotatef(s.getTerre() -> getRotationAngle() * 57.296, 0.0, 0.0, 1.0);
			s.getTerre() -> drawPlanet();
		glPopMatrix();
		glRotatef(90, 1.0, 0.0, 0.0);
	glPopMatrix();

	glPushMatrix();
		glRotatef(s.getLune() -> getRotationAngle() * 57.296, 0.0, 0.0, 1.0);
		s.getLune() -> drawPlanet();
	glPopMatrix();

	int LightPos[4] = {-10, 0, 0, 1};
	int MatSpec [4] = {1, 1, 1, 1};

	glMaterialiv(GL_FRONT_AND_BACK, GL_EMISSION, MatSpec);
	glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, 100);
	glLightiv(GL_LIGHT0, GL_POSITION, LightPos);
	glutSolidSphere(1, 50, 50);

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
}

void set_schematic_mode()
{
	glRotatef(90, -1.0, 0.0, 0.0);

	s.getLune() -> drawPlanetColor();
	s.getTerre() -> drawPlanetColor();


	std::string timeString = std::to_string(s.getTime() / 86400);
	std::string timeSection = "Temps : " + timeString + " jours";

	const unsigned char *time = (const unsigned char*) (timeSection.c_str());
	glRasterPos3f(5.5, 0, -5.5);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, time);
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Set the camera
	gluLookAt(s.getCam()->getcX(), s.getCam()->getcY(), s.getCam()->getcZ(),
		s.getCam()->getlX(), 1.0f,  s.getCam()->getlZ(),
		0.0f, 1.0f,  0.0f);

	if (SCHEMATIC_MODE) {
		set_schematic_mode();
	} else {
		normal_mode();
	}

    glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y)
{
	switch (key) {
		case 27 :
			exit(0);
		break;

		/* Activer/Desactiver le mode schema */
		case 's' :
			s.getCam() -> setcX(0.0f);
			s.getCam() -> setcY(1.0f);
			s.getCam() -> setcZ(17.0f);
			s.getCam() -> setlX(0.0f);
			s.getCam() -> setlZ(-1.0f);

			SCHEMATIC_MODE = !SCHEMATIC_MODE;
		break;

		/* Diminuer la vitesse du système */
		case '-' :
			s.setDeltaT(s.getDeltaT() * 0.9);
			if (s.getDeltaT() < 500){
				s.setDeltaT(500);
			}
		break;

		/* Augementer la vitesse du système */
		case '+' :
			s.setDeltaT(s.getDeltaT() * 1.1);
			if (s.getDeltaT() > 15000){
				s.setDeltaT(15000);
			}
		break;

		/* Démarrer une nouvelle simulation */
		case 'n' :
			EarthMoonSystem s2;
			s = s2;
			s2.getCam() -> setcZ(17.0f);
		break;
	}
}
int temp=0;
int temp2=0;
void processSpecialKeys(int key, int xx, int yy)
{
    float fraction = 0.1f;

    switch (key) {
		case GLUT_KEY_LEFT :
			s.getCam()->setAngle(-0.1f );
			temp = s.getCam()->getcX();
			s.getCam()->setcX(s.getCam()->getcX()*cos(s.getCam()->getAngle())+
						s.getCam()->getcZ()*sin(s.getCam()->getAngle()));
			s.getCam()->setcZ(-1*temp*sin(s.getCam()->getAngle() )+
						s.getCam()->getcZ()*cos(s.getCam()->getAngle()));
	        break;

			case GLUT_KEY_RIGHT :
			s.getCam()->setAngle(0.1f );
			temp=s.getCam()->getcX();
			s.getCam()->setcX(s.getCam()->getcX()*cos(s.getCam()->getAngle())+
												s.getCam()->getcZ()*sin(s.getCam()->getAngle()));
			s.getCam()->setcZ(-1*temp*sin(s.getCam()->getAngle() )+
												s.getCam()->getcZ()*cos(s.getCam()->getAngle()));

	        break;

			case GLUT_KEY_UP :
			s.getCam()->setAngle(-0.1f);
			temp2=s.getCam()->getcY();
			s.getCam()->setcY( s.getCam()->getcY()*cos( s.getCam()->getAngle() ) -
												s.getCam()->getcZ()*sin( s.getCam()->getAngle() ) );
			s.getCam()->setcZ( temp2*sin(s.getCam()->getAngle() ) +
		 										s.getCam()->getcZ()* cos( s.getCam()->getAngle() ));


	        break;

			case GLUT_KEY_DOWN :
			s.getCam()->setAngle(0.1f);
			temp2=s.getCam()->getcY();
			s.getCam()->setcY( s.getCam()->getcY()*cos( s.getCam()->getAngle() ) -
												s.getCam()->getcZ()*sin( s.getCam()->getAngle() ) );
			s.getCam()->setcZ( temp2*sin(s.getCam()->getAngle() ) +
												s.getCam()->getcZ()* cos( s.getCam()->getAngle() ));
	        break;


		/* Diminuer la vitesse de la Lune */
		case GLUT_KEY_F1 :
			s.getLune() -> mulVel(0.9);
		break;

		/* Augementer la vitesse de la Lune */
		case GLUT_KEY_F2 :
			s.getLune() -> mulVel(1.1);
		break;

		/*Diminuer la masse de la Terre*/
		case GLUT_KEY_F3 :
			s.getTerre() -> setMass(s.getTerre() -> getMass() * 0.5);
		break;

		/*Augmenter la masse de la Terre*/
		case GLUT_KEY_F4 :
			s.getTerre() -> setMass(s.getTerre() -> getMass() * 2);
		break;

		/*Diminuer la masse de la Lune*/
		case GLUT_KEY_F5 :
			s.getLune() -> setMass(s.getLune() -> getMass() * 0.5);
		break;

		/*Augmenter la masse de la Lune*/
		case GLUT_KEY_F6 :
			s.getLune() -> setMass(s.getLune() -> getMass() * 2);
		break;
    }
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, (float) w / h, 1.0, 1000.0);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

void TimerFunc(int value)
{
	s.updateRotationAngle(s.getTerre());

    s.spendTime();
    glutPostRedisplay();
    glutTimerFunc(50, TimerFunc, 1);
}

int main(int argc, char **argv)
{
//	display_guide_shell();
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Modélisation de la rotation de la Lune autour de la Terre");
    //glutFullScreen();

    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutIdleFunc(draw);
    glutSpecialFunc(processSpecialKeys);
	glutKeyboardFunc(processNormalKeys);


    glutTimerFunc(50, TimerFunc, 1);
    make_image_moon_earth();
    glutMainLoop();

    return 0;
}
