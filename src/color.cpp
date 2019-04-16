#include "../inc/color.h"

Color::Color():
    R(0),
    G(0),
    B(0),
    A(0)
{}

Color::Color( unsigned int R_, unsigned int G_, unsigned int B_)
{
    R = R_;
    G = G_;
    B = B_;
}

Color::Color( unsigned int R_, unsigned int G_, unsigned int B_, unsigned int A_)
{
  R = R_;
  G = G_;
  B = B_;
  A = A_;
}

unsigned int Color::getR() const
{
    return R;
}

unsigned int Color::getG() const
{
    return G;
}

unsigned int Color::getB() const
{
    return B;
}

unsigned int Color::getA() const
{
    return A;
}
