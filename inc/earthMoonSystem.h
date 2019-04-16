/**
 * @file inc/vect.h
 * @brief This file is a header that contains the "earthMoonSystem" class.
 * @author BARRY Mamadou Djouldé - mamadou-djoulde.barry@etu.umontpellier.fr
 * @author DEDEBANT Louis - louis.dedebant@etu.umontpellier.fr
 * @author DIABATE Amara - amara.diabate@etu.umontpellier.fr
 * @author QUENETTE Christophe - christophe.quenette@etu.umontpellier.fr
 * @author SAÏ Ismaël - ismael.sai@etu.umontpellier.fr
 * @date   May, 2017
 *
 */

#ifndef __EARTH_MOON_SYSTEM_H
#define __EARTH_MOON_SYSTEM_H

#include "planet.h"
#include "camera.h"

/*! \class EarthMoonSystem
  * \brief class representing the whole system
  *
  *  This class makes it possible to create a system between two corpses and
  *  see what happen over the time
  */
class EarthMoonSystem
{
 private:
    Planet m_terre; /*!< the first planet of the system*/
    Planet m_lune; /*!< the second planet of the system*/
    unsigned int m_time; /*!< time spent in total*/
    unsigned int m_deltaT; /*!< time spent between two position of the second planet*/
    Camera m_cam; /*!< the camera of the system */

public:

  /*!
  *  \brief  Default constructor
  *
  *  Default constructor of the EarthMoonSystem class
  */
    EarthMoonSystem();

    /*!
    *  \brief  Reading accessor getTerre
    *
    *  get the first planet of the system
    *  \return Planet m_terre : the first planet of the system
    */
    Planet *getTerre();

    /*!
    *  \brief  Reading accessor getLune
    *
    *  get the second planet of the system
    *  \return Planet m_lune : the second planet of the system
    */
    Planet *getLune();

    /*!
    *  \brief  Reading accessor getTime
    *
    *  get the time spent in total
    *  \return unsigned int m_time : the time spent in total
    */
    unsigned int getTime() const;


    /*!
    *  \brief  Writing accessor setTime
    *
    *  set the time spent in total
    *  \param unsigned int t: the new time spent in total
    */
    void setTime(unsigned int t);

    /*!
    *  \brief  Reading accessor getDeltaT
    *
    *  get the time between two position of the second planet
    *  \return unsigned int m_deltaT : the time between two position of the second planet
    */
    unsigned int getDeltaT() const;

    /*!
    *  \brief  Writing accessor setDeltaT
    *
    *  set the time between two position of the second planet
    *  \param unsigned int dt : the new time between two position of the second planet
    */
    void setDeltaT(unsigned int dt);

    /*!
    *  \brief  Reading accessor getCam
    *
    *  get the camera of the system
    *  \return Camera m_time : the camera of the system
    */
    Camera *getCam();

    /*!
    *  \brief  Writing accessor setCam
    *
    *  set the camera of the system
    *  \param Camera c : the new camera of the system
    */
    void setCam(Camera &c);

    /*!
    *  \brief  Method updateRotationAngle
    *
    *  update the angle of rotation of a planet
    *  \param Planet p:  the planet that will get the update of the angle of rotation
    */
    void updateRotationAngle(Planet *p);

    /*!
    *  \brief  Method spendTime
    *
    *  make the time spend
    */
    void spendTime();
};

#endif // __EARTH_MOON_SYSTEM_H
