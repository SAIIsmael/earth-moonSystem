/**
 * @file inc/camera.h
 * @brief This file is a header that contains the "camera" class.
 * @author BARRY Mamadou Djouldé - mamadou-djoulde.barry@etu.umontpellier.fr
 * @author DEDEBANT Louis - louis.dedebant@etu.umontpellier.fr
 * @author DIABATE Amara - amara.diabate@etu.umontpellier.fr
 * @author QUENETTE Christophe - christophe.quenette@etu.umontpellier.fr
 * @author SAÏ Ismaël - ismael.sai@etu.umontpellier.fr
 * @date   May, 2017
 *
 */

#ifndef __CAMERA_H
#define __CAMERA_H

/*! \class Camera
  * \brief class representing a camera
  *
  *  This class makes it possible to create a camera and edit the position of the camera
  */
class Camera{
private:
  float c_x; /*!< Camera position on x axis*/
  float c_y; /*!< Camera position on y axis*/
  float c_z; /*!< Camera position on z axis*/

  float l_x; /*!< Camera look at on x axis*/
  float l_y=1.0f; /*!< Camera look at on y axis*/
  float l_z; /*!< Camera look at on z axis*/

  float u_x= 0.0f; /*!< camera height on x axis*/
  float u_y=1.0f; /*!< camera height on y axis*/
  float u_z=0.0f; /*!< camera height on z axis*/

  float angle; /*!< angle of rotation of the camera*/
public:

  /*!
  *  \brief  Default constructor
  *
  *  Default constructor of the camera class
  */
  Camera();

  /*!
  *  \brief  Parameterized constructor
  *
  *  Parameterized constructor of the camera class
  *
  *  \param c_x : camera position on x axis
  *  \param c_y : camera position on y axis
  *  \param c_z : camera position on z axis
  *  \param l_x : camera look at  on x axis
  *  \param l_z : camera look at on z axis
  *  \param a : camera rotation angle
  */
  Camera(float c_x, float c_y, float c_z, float l_x, float l_z, float a);

  /*!
  *  \brief  Reading accessor getcX
  *
  *  get the camera position on x axis
  *  \return float c_x : the camera position on x axis
  */
  float getcX();

  /*!
  *  \brief  Reading accessor getcY
  *
  *  get the camera position on y axis
  *  \return float c_y : the camera position on y axis
  */
  float getcY();
  /*!
  *  \brief  Reading accessor getcZ
  *
  *  get the camera position on z axis
  *  \return float c_z : the camera position on z axis
  */
  float getcZ();

  /*!
  *  \brief  Writing accessor setcX
  *
  *  set the camera position on x axis
  *  \param float x_ : the new position of the camera on x axis
  */
  void setcX(float x_);

  /*!
  *  \brief  Writing accessor setcY
  *
  *  set the camera position on y axis
  *  \param float y_ : the new position of the camera on y axis
  */
  void setcY(float y_);

  /*!
  *  \brief  Writing accessor setxcZ
  *
  *  set the camera position on z axis
  *  \param float z_ : the new camera position of the camera on z axis
  */
  void setcZ(float z_);

  /*!
  *  \brief  Reading accessor getlX
  *
  *  get the look at position on x axis
  *  \return float l_x : the look at position on x axis
  */
  float getlX();

  /*!
  *  \brief  Reading accessor getlY
  *
  *  get the look at position on y axis
  *  \return float l_y : the look at position on y axis
  */
  float getlZ();

  /*!
  *  \brief  Writing accessor setlX
  *
  *  set the look at position on x axis
  *  \param float lx_ : the new look at position on x axis
  */
  void setlX(float lx_);

  /*!
  *  \brief  Writing accessor setlY
  *
  *  set the look at position on y axis
  *  \param float ly_ : the new look at position on y axis
  */
  void setlZ(float lz_);

  /*!
  *  \brief  Writing accessor setlZ
  *
  *  set the look at position on y axis
  *  \param float lz_ : the new look at position on z axis
  */
  float getAngle();

  /*!
  *  \brief  Writing accessor setAngle
  *
  *  set the angle of rotation of the camera
  *  \param float a : the new angle of rotation of the camera
  */
  void setAngle(float a);

};

#endif // __CAMERA_H
