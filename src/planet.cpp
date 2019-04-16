#include <cmath>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <iostream>
#include <string>

#include "../inc/planet.h"

#define SCALE_SIZE_PLANET 2e-7

#define SCALE_DISTANCE 1.5e-8

Planet::Planet() :
    name(""),
    col(Color(0, 0, 0)),
    mass(0.0),
    rad(0.0),
    pos(Vect(0, 0, 0)),
    vel(Vect(0, 0, 0)),
    rotationSpeed(0.0),
    rotationAngle(0.0),
    texture(-1)
{}

Planet::Planet(std::string name_, Color col_, double mass_, double rad_,
     Vect pos_, Vect vel_, float rotationSpeed_, float rotationAngle_, GLuint texture_)
{
    name = name_;
    col = col_;
    mass = mass_;
    rad = rad_;
    pos = pos_;
    vel = vel_;
    rotationSpeed = rotationSpeed_;
    rotationAngle = rotationAngle_;
    texture = texture_;
}

std::string Planet::getName() const
{
    return name;
}

Color Planet::getCol() const
{
    return col;
}

void Planet::setCol(Color col_)
{
    col = col_;
}

double Planet::getMass() const
{
    return mass;
}

void Planet::setMass(double mass_)
{
    mass = mass_;
}

double Planet::getRad() const
{
    return rad;
}

Vect Planet::getPos() const
{
    return pos;
}

void Planet::setPos(Vect pos_)
{
    pos = pos_;
}

Vect *Planet::getVel()
{
    return &vel;
}

void Planet::setVel(Vect vel_)
{
    vel = vel_;
}

float Planet::getRotationSpeed() const
{
    return rotationSpeed;
}

void Planet::setRotationSpeed(float rotationSpeed_)
{
    rotationSpeed = rotationSpeed_;
}

float Planet::getRotationAngle() const
{
    return rotationAngle;
}

void Planet::setRotationAngle(float rotationAngle_)
{
    rotationAngle = rotationAngle_;
}

GLuint Planet::getTexture() const
{
    return texture;
}

Vect Planet::gForce(Planet &p)
{
	const double G = 6.67408e-11; // Constante de gravitation universelle

	Vect u, f;

	u.setX(p.getPos().getX() - pos.getX());
    u.setY(p.getPos().getY() - pos.getY());
    u.setZ(p.getPos().getZ() - pos.getZ());

/*  Distance entre les deux corps  */

    double d = u.norm();

/*  Normalisation du vecteur u (pour que sa norme soit égale à 1)  */

	u.setX(u.getX() / d);
    u.setY(u.getY() / d);
    u.setZ(u.getZ() / d);

/*  Calcul de la force  */

    f.setX((G * getMass() * p.getMass()) / (d * d) * u.getX());
    f.setY((G * getMass() * p.getMass()) / (d * d) * u.getY());
    f.setZ((G * getMass() * p.getMass()) / (d * d) * u.getZ());

    return f;
}

void Planet::mulVel(double d)
{
    // std::cout << "Vitesse avant mulvel\n";
    // getVel()->print();

    getVel() -> setX(getVel() -> getX() * d);
    getVel() -> setY(getVel() -> getY() * d);
    getVel() -> setZ(getVel() -> getZ() * d);

    // std::cout << "Vitesse apres mulvel\n";
    // getVel()->print();
}


void Planet::movement(Planet p, float h, Vect f)
{

    /*  Pour calculer le mouvement on utilise l'algorithme de Verlet à 1 pas */

    Vect a0(f.getX() / getMass(), f.getY() / getMass(), f.getZ() / getMass());

    pos.setX(pos.getX() + getVel() -> getX() * h + 0.5 * (h * h) * a0.getX());
    pos.setY(pos.getY() + getVel() -> getY() * h + 0.5 * (h * h) * a0.getY());
    pos.setZ(pos.getZ() + getVel() -> getZ() * h + 0.5 * (h * h) * a0.getZ());

    f = gForce(p);

    Vect a1(f.getX() / getMass(), f.getY() / getMass(), f.getZ() / getMass());

    vel.setX(vel.getX() + 0.5 * h * (a0.getX() + a1.getX()));
    vel.setY(vel.getY() + 0.5 * h * (a0.getY() + a1.getY()));
    vel.setZ(vel.getZ() + 0.5 * h * (a0.getZ() + a1.getZ()));

}

void Planet::drawOrbit()
{
    // float DEG2RAD = 3.14159 / 180.0;
    //
    // glRotatef(90, -1.0, 0.0, 0.0);
    // glColor3ub(255, 255, 255);
    //
    // glBegin(GL_LINE_LOOP);
    // for(int i = 0; i < 360; i++)
    // {
    //     float rad = i * DEG2RAD;
    //     glVertex2f(cos(rad) * getPos().getX() * 1.5e-8, sin(rad) * getPos().getZ() * 1.5e-8);
    // }
    // glEnd();
    //
    // glRotatef(90, 1.0, 0.0, 0.0);
}

void Planet::drawPlanet()
{
    double x = pos.getX() * SCALE_DISTANCE;
    double y = pos.getY() * SCALE_DISTANCE;
    double z = pos.getZ() * SCALE_DISTANCE;

    glTranslatef(x, y, z);

    GLUquadricObj* quadro = gluNewQuadric();
	gluQuadricNormals(quadro, GLU_SMOOTH);
	gluQuadricTexture(quadro, GL_TRUE);
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glPushMatrix();
		    glBindTexture(GL_TEXTURE_2D, texture);
		    gluSphere(quadro, rad * SCALE_SIZE_PLANET, 50, 50);
        glPopMatrix();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	gluDeleteQuadric(quadro);

    glTranslatef(-x, -y, -z);
}

void Planet::drawPlanetColor()
{
    double x = pos.getX() * SCALE_DISTANCE;
    double y = pos.getY() * SCALE_DISTANCE;
    double z = pos.getZ() * SCALE_DISTANCE;

    glTranslatef(x, y, z);

    glColor3ub(col.getR(), col.getG(), col.getB());
    glutSolidSphere(rad * SCALE_SIZE_PLANET, 30, 30);

    const unsigned char *name = (const unsigned char*) (getName().c_str());

    glRasterPos3f(x + 1.5, 0, z - 1);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, name);

    std::string massString = std::to_string(getMass() / 1e22);
    std::string massSection = "Masse : " + massString + "e22 kg";
    const unsigned char *mass = (const unsigned char*) (massSection.c_str());

    glRasterPos3f(x + 1.5, 0, z - 1.5);
    glutBitmapString(GLUT_BITMAP_HELVETICA_12, mass);

    std::string velString = std::to_string(getVel()->norm());
    std::string velSection = "Vitesse : " + velString + " m/s";
    const unsigned char *vel = (const unsigned char*) (velSection.c_str());

    glRasterPos3f(x + 1.5, 0, z - 2.0);
    glutBitmapString(GLUT_BITMAP_HELVETICA_12, vel);

    glColor3ub(255, 255, 255);

    glTranslatef(-x, -y, -z);
}
