#include "../inc/camera.h"


Camera::Camera():
    c_x(0.0f),
    c_y(1.0f),
    c_z(17.0f),
    l_x(0.0f),
    l_z(-1.0f),
    angle(0.0f)
{}

Camera::Camera(float cx, float cy, float cz, float lx, float lz, float a){

  c_x=cx;
  c_y=cy;
  c_z=cz;
  l_x=lx;
  l_z=lz;
  angle=a;
}

float Camera::getcX(){
  return c_x;
}
float Camera::getcY(){
  return c_y;
}
float Camera::getcZ(){
  return c_z;
}

void Camera::setcX(float x){
  c_x=x;
}
void Camera::setcY(float y){
  c_y=y;
}
void Camera::setcZ(float z){

  c_z=z;
}

float Camera::getlX(){
  return l_x;
}
float Camera::getlZ(){
  return l_z;
}

void Camera::setlX(float lx){
  l_x=lx;
}
void Camera::setlZ(float lz){

  l_z=lz;
}

float Camera::getAngle(){
  return angle;
}

void Camera::setAngle(float a){

  angle=a;
}
