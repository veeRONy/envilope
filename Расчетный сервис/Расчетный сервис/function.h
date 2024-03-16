#pragma once
#include<math.h>
double F(double P, double am_g, double am_o, double Cp_o, double Cp_g, double H_target, double T)
{
    double cpx = Cp_g / 4183;
    double cpx_o = Cp_o / 4183;
    double px = 1.45037737796e-4 * P;
    double Tx = 1.8 * T + 32;
    double H_g = (cpx * Tx + px * ((1.619e-10 * px + 1.412e-6) * px - 0.02734)) * 2325.9612;
    double H_o = (cpx_o * Tx + px * 3.36449e-3) * 2325.9612;
    double H = H_g * am_g + H_o * am_o;
    return H - H_target;
}
