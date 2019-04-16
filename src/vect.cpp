#include <cmath>
#include <iostream>

#include "../inc/vect.h"

using namespace std;

Vect::Vect():
    x(0),
    y(0),
    z(0)
{}

Vect::Vect(double a, double b, double c)
{
    x = a;
    y = b;
    z = c;
}

double Vect::getX() const
{
    return x;
}

double Vect::getY() const
{
    return y;
}

double Vect::getZ() const
{
    return z;
}

void Vect::setX(double a)
{
    x = a;
}

void Vect::setY(double b)
{
    y = b;
}

void Vect::setZ(double c)
{
    z = c;
}

double Vect::norm()
{
	return sqrt(x * x + y * y + z * z);
}
