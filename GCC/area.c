#include "area.h"
#include <math.h>

double area_circulo(double raio) {
    return M_PI * raio * raio;
}

double area_triangulo(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
