/**
 * @file inc/vect.h
 * @brief This file is a header that contains the "Vect" class.
 * @author BARRY Mamadou Djouldé - mamadou-djoulde.barry@etu.umontpellier.fr
 * @author DEDEBANT Louis - louis.dedebant@etu.umontpellier.fr
 * @author DIABATE Amara - amara.diabate@etu.umontpellier.fr
 * @author QUENETTE Christophe - christophe.quenette@etu.umontpellier.fr
 * @author SAÏ Ismaël - ismael.sai@etu.umontpellier.fr
 * @date   May, 2017
 *
 */


#ifndef __VECT_H
#define __VECT_H


/*! \class Vect
  * \brief class representing a vector of integer
  *
  *  This class makes it possible to create a vector, calculate the norm of a vector,
  *  edit vector coordinates and print it
  */
class Vect
{
private:
    double x; /*!< Coordinate on the x axis*/
    double y; /*!< Coordinate on the y axis*/
    double z; /*!< Coordinate on the z axis*/

public:

  /*!
  *  \brief  Default constructor
  *
  *  Default constructor of the Vect class
  */
    Vect();

    /*!
    *  \brief  Parameterized constructor
    *
    *  Parameterized constructor of the Vect class
    *
    *  \param x : Coordinate on the x axis
    *  \param y : Coordinate on the y axis
    *  \param z : Coordinate on the z axis
t
    */
    Vect(double x,double y, double z);

    /*!
    *  \brief  Reading accessor getX
    *
    *  get the coordinate on the x axis of the vector
    *  \return double x : the coordinate on the x axis of the vector
    */
    double getX() const;

    /*!
    *  \brief  Reading accessor getY
    *
    *  get the coordinate on the y axis of the vector
    *  \return double y : the coordinate on the y axis of the vector
    */
    double getY() const;

    /*!
    *  \brief  Reading accessor getZ
    *
    *  get the coordinate on the z axis of the vector
    *  \return double z : the coordinate on the z axis of the vector
    */
    double getZ() const;

    /*!
    *  \brief  Writing accessor setX
    *
    *  set the coordinate on the x axis of the vector
    *  \param double a : the new coordinate on the x axis of the vector
    */
    void setX(double a);

    /*!
    *  \brief  Writing accessor setY
    *
    *  set the coordinate on the y axis of the vector
    *  \param double b : the new coordinate on the y axis of the vector
    */
    void setY(double b);

    /*!
    *  \brief  Writing accessor setZ
    *
    *  set the coordinate on the z axis of the vector
    *  \param double c : the new coordinate on the z axis of the vector
    */
    void setZ(double c);

    /*!
    *  \brief  Method norm
    *
    *  calculate the norm of a vector
    *  \return double n : the norm of the vector
    */
    double norm();
};

#endif // __VECT_H
