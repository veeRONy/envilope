#pragma once
#include<math.h>
#include"function.h"

double calculate(double P, double am_g, double am_o, double Cp_o, double Cp_g, double H_target)
{
    double x = rand()%100, x_last = rand()%100, x_grandlast = 0, dx, E = 0.000000000001;
    do
    {
        x_grandlast = x_last;
        x_last = x;
        x -= ((x_last - x_grandlast) / (F(P, am_g, am_o, Cp_o, Cp_g, H_target, x_last) - F(P, am_g, am_o, Cp_o, Cp_g, H_target, x_grandlast))) * F(P, am_g, am_o, Cp_o, Cp_g, H_target, x_last);
        dx = x - x_last;
    } while (fabs(dx) >= E);

    return x;
}