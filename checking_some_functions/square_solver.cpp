#include <iostream>
#include "math.h"


double square_solver(double a,double b, double c)
{
    double descriminant=pow(b,2)-4*a*c;
    if (descriminant>0)
    {
        double x1=(-b+sqrt(descriminant))/(2*a);
        double x2=(-b-sqrt(descriminant))/(2*a);
        std::cout<< "x1="<<x1<<",  x2="<<x2<<std::endl;
    }
}
