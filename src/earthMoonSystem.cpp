#include "../inc/earthMoonSystem.h"

EarthMoonSystem::EarthMoonSystem() :
    m_terre(Planet("Terre", Color(0, 0, 255), 5.972e24,
    6.371e6, Vect(0.0, 0.0, 0.0), Vect(0.0, 0.0, 0.0),
    7.29211e-5, 0.0, 1)),

    m_lune(Planet("Lune", Color(200, 200, 200), 7.345e22,
    1.738e6, Vect(3.633e8, 0.0, 0.0), Vect(0.0, 0.0, -1076),
    2.693180e-6, 0.0, 2)),
    /* La position initiale choisie ci-dessus est la position (moyenne) de la Lune
    au périgée */

    m_cam(Camera()),

    m_time(0),
    m_deltaT(3600) //initialisation à 1 heure
{}

Planet *EarthMoonSystem::getTerre()
{
    return &m_terre;
}

Planet *EarthMoonSystem::getLune()
{
    return &m_lune;
}

unsigned int EarthMoonSystem::getTime() const
{
    return m_time;
}

void EarthMoonSystem::setTime(unsigned int t)
{
    m_time = t;
}

unsigned int EarthMoonSystem::getDeltaT() const
{
    return m_deltaT;
}

void EarthMoonSystem::setDeltaT(unsigned int dt)
{
    m_deltaT = dt;
}

Camera *EarthMoonSystem::getCam()
{
    return &m_cam;
}

void EarthMoonSystem::setCam(Camera &c)
{
    m_cam = c;
}

void EarthMoonSystem::updateRotationAngle(Planet *p)
{
    if (p -> getRotationAngle() > 6.28) {
        p -> setRotationAngle(0.0);
    } else {
        p -> setRotationAngle(p -> getRotationAngle() + p -> getRotationSpeed() * m_deltaT);
    }
}

void EarthMoonSystem::spendTime()
{
    m_lune.movement(m_terre, m_deltaT, m_lune.gForce(m_terre));
    m_time += m_deltaT;
}
