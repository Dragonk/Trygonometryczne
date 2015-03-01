#ifndef WYNIKI_H
#define WYNIKI_H

#include "QString"
#include "math.h"

class wyniki
{
public:
    wyniki(double A, double B, int C);
    QString generateHTML();
    double najwiekszaWartosc(int a);
    double najmniejszaWartosc(int a);
    double *macierz_wyniki[5];
private:
    double przedzial;
    double katA;
    double katB;
    double dzielnik = 180/M_PI; //dzielnik potrzebny do konwersji stopni na radiany
    int ilosc_elementow;
    void przedzialy();
    void sinus();
    void cosinus();
    void tanges();
    void cotanges();
};
#endif // OBLICZENIA_H
