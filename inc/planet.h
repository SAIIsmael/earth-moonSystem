/**
 * @file inc/planet.h
 * @brief This file is a header that contains the "Planet" class.
 * @author BARRY Mamadou Djouldé - mamadou-djoulde.barry@etu.umontpellier.fr
 * @author DEDEBANT Louis - louis.dedebant@etu.umontpellier.fr
 * @author DIABATE Amara - amara.diabate@etu.umontpellier.fr
 * @author QUENETTE Christophe - christophe.quenette@etu.umontpellier.fr
 * @author SAÏ Ismaël - ismael.sai@etu.umontpellier.fr
 * @date   May, 2017
 *
 */

#ifndef __PLANET_H
#define __PLANET_H

#include <GL/glut.h>
#include <string>

#include "../inc/color.h"
#include "../inc/vect.h"

/*! \class Planet
  * \brief class representing a planet
  *
  *  This class makes it possible to create a planet, calculate the gravitational force of attraction
  *  between two planets and the resulting movement
  */
class Planet
{


private:
    std::string name; /*!< Name of the planet*/
    Color col; /*!< Color of the planet*/
    double mass; /*!< Mass of the planet*/
    double rad; /*!< Radius of the planet*/
    Vect pos; /*!< Position of the planet*/
    Vect vel; /*!< velocity of the planet*/
    float rotationSpeed; /*!< Rotation speed of the planet on itself*/
    float rotationAngle; /*!< Angle of rotation of the planet on itslef ( radians ) */
    GLuint texture; /*!< texture wich will be mapped on the Planet*/


public:
    /*!
    *  \brief  Default constructor
    *
    *  Default constructor of the planet class
    */
      Planet();

      /*!
      *  \brief  Parameterized constructor
      *
      *  Parameterized constructor of the planet class
      *
      *  \param name : name of the planet
      *  \param col : color of the planet
      *  \param mass : mass of the planet
      *  \param rad : radius of the planet
      *  \param vel : velocity of the planet
      *  \param pos : position of the planet
      *  \param rotSpeed : rotation speed of the planet on itslef
      *  \param rotAngle : angle of rotation of the planet on itslef ( radians)
      *  \param texture : texture wich will be mapped on the planet
      */
    Planet(std::string name, Color col, double mass , double rad , Vect vel , Vect pos,
          float rotSpeed, float rotAngle, GLuint texture);

          /*!
          *  \brief  Reading accessor getName
          *
          *  get the name of the planet
          *  \return std::string Name : the name of the planet
          */
    std::string getName() const;

    /*!
    *  \brief  Reading accessor getCol
    *
    *  get the color of the planet
    *  \return Color col : the color of the planet
    */
    Color getCol() const;

    /*!
    *  \brief  Writing accessor setCol
    *
    *  set the color of the planet
    *  \param Color col_ : the color that we want to apply to the planet
    */
    void setCol(Color col_);

    /*!
    *  \brief  Reading accessor getMass
    *
    *  get the mass of the planet
    *  \return double mass : the mass of the planet
    */
    double getMass() const;

    /*!
    *  \brief  Writing accessor setMass
    *
    *  set the mass of the planet
    *  \param double mass_ : the new mass of the planet
    */
    void setMass(double mass_);

    /*!
    *  \brief  Reading accessor getRad
    *
    *  get the radius of the planet
    *  \return double rad : the radius of the planet
    */
    double getRad() const;

    /*!
    *  \brief  Reading accessor getPos
    *
    *  get the position of the planet
    *  \return Vect pos : the vector that contains the coordinates x,y and z of the planet
    */
    Vect getPos() const;

    /*!
    *  \brief  Writing accessor setPos
    *
    *  set the position of the planet
    *  \param Vect pos_ : the new position of the planet
    */
    void setPos(Vect pos_);

    /*!
    *  \brief  Reading accessor getVel
    *
    *  get the velocity of the planet
    *  \return Vect vel : the vector that contains the coordinates x,y and z of the planet
    */
    Vect* getVel();

    /*!
    *  \brief  Writing accessor setVel
    *
    *  set the velocity of the planet
    *  \param Vect vel_ : the new velocity of the planet
    */
    void setVel(Vect vel_);

    /*!
    *  \brief  Reading accessor getRotationSpeed
    *
    *  get the rotation speed of the planet on itslef
    *  \return float rotationSpeed : the rotation speed of the planet on itslef
    */
    float getRotationSpeed() const;

    /*!
    *  \brief  Writing accessor setRotationSpeed
    *
    *  set the rotation speed of the planet on itslef
    *  \param float rotationSpeed_ : the new rotation speed of the planet on itslef
    */
    void setRotationSpeed(float rotationSpeed_);

    /*!
    *  \brief  Reading accessor getRotationAngle
    *
    *  get the rotation angle of the planet on itslef
    *  \return float rotationAngle : the rotation angle of the planet on itslef
    */
    float getRotationAngle() const;

    /*!
    *  \brief  Writing accessor setRotationAngle
    *
    *  set the rotation angle of the planet on itslef
    *  \param float rotationAngle_ : the new rotation angle of the planet on itslef
    */
    void setRotationAngle(float rotationAngle_);

    /*!
    *  \brief  Reading accessor getTexture
    *
    *  get the texture of the planet
    *  \return GLUint texture : the texture of the planet
    */
    GLuint getTexture() const;

    /*!
    *  \brief  Method mulVel
    *
    *  Allow to multiply the speed of a planet by any integer
    *  \param double d : the multiplication coefficient
    */
    void mulVel(double d);

    /*!
    *  \brief  Method gForce
    *
    *  calculate and return the gravitational force of attraction between two planets
    *  \param Planet p :  the referencial planet
    *  \return : Vect f : the gravitational force between the two planets
    */
    Vect gForce(Planet &p);

    /*!
     *  \brief Method movement
     *
     *  calculate the movement between the two planets
     *  \param Planet p : the referencial planet
     *  \param foat h : The time between two positions of the planet (the calling instance)
     *  \param Vect f : The gravitationnal force between the two planets
     */
    void movement(Planet p, float h, Vect f);

    /*!
     *   \brief Method drawOrbit
     *
     *   Draw the orbit of a planet
     */
    void drawOrbit();

    /*!
     *   \brief Method drawPlanet
     *
     *   Draw a planet using the texture
     */
    void drawPlanet();

    /*!
     *   \brief Method drawPlanetColor
     *
     *   Draw a planet using the color
     */
    void drawPlanetColor();
};

#endif //__PLANET_H
