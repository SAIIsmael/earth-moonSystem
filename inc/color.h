/**
 * @file inc/vect.h
 * @brief This file is a header that contains the "Color" class.
 * @author BARRY Mamadou Djouldé - mamadou-djoulde.barry@etu.umontpellier.fr
 * @author DEDEBANT Louis - louis.dedebant@etu.umontpellier.fr
 * @author DIABATE Amara - amara.diabate@etu.umontpellier.fr
 * @author QUENETTE Christophe - christophe.quenette@etu.umontpellier.fr
 * @author SAÏ Ismaël - ismael.sai@etu.umontpellier.fr
 * @date   May, 2017
 *
 */


#ifndef __COLOR_H
#define __COLOR_H

/*! \class Color
  * \brief class representing RGB color for planets
  *
  *  This class makes it possible to create a RGB color, edit all the components
  *  and edit the transparence
  */
class Color
{

private:
    unsigned int R; /*!< the R component of the color*/
    unsigned int G; /*!< the G component of the color*/
    unsigned int B; /*!< the B component of the color*/
    unsigned int A; /*!< the transparence of the color*/


public:

  /*!
  *  \brief  Default constructor
  *
  *  Default constructor of the Color class
  */
    Color();

    /*!
    *  \brief  Parameterized constructor
    *
    *  Parameterized constructor of the Color class
    *
    *  \param R : the R component of the color
    *  \param G : the G component of the color
    *  \param B : the B component of the color

    */
    Color(unsigned int R, unsigned int G, unsigned int B);

    /*!
    *  \brief  Parameterized constructor
    *
    *  Parameterized constructor of the Color class
    *
    *  \param R : the R component of the color
    *  \param G : the G component of the color
    *  \param B : the B component of the color
    *  \param A : the transparence of the color

    */
    Color(unsigned int R, unsigned int G , unsigned int B , unsigned int A);

    /*!
    *  \brief  Reading accessor getR
    *
    *  get the R component of the color
    *  \return unsigned int R : the R component of the color
    */
    unsigned int getR() const;

    /*!
    *  \brief  Reading accessor getG
    *
    *  get the G component of the color
    *  \return unsigned int G : the G component of the color
    */
    unsigned int getG() const;

    /*!
    *  \brief  Reading accessor getB
    *
    *  get the B component of the color
    *  \return unsigned int B : the B component of the color
    */
    unsigned int getB() const;

    /*!
    *  \brief  Reading accessor getA
    *
    *  get the A component of the color
    *  \return unsigned int A : the transparence of the color
    */
    unsigned int getA() const;
};

#endif // __COLOR_H
