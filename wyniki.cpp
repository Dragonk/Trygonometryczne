#include "wyniki.h"

wyniki::wyniki(double A, double B, int C)
{
    wyniki::katA = A;
    wyniki::katB = B;
    wyniki::przedzial = B-A;
    if(C!=1)
        wyniki::przedzial = wyniki::przedzial/(C-1);
    else
        wyniki::przedzial = wyniki::przedzial/(C);
    wyniki::ilosc_elementow = C;
    for(int i=0;i<=4;i++)
        wyniki::macierz_wyniki[i] = new double[wyniki::ilosc_elementow];
    wyniki::przedzialy();
    wyniki::sinus();
    wyniki::cosinus();
    wyniki::tanges();
    wyniki::cotanges();
}

void wyniki::przedzialy()
{
    for(int i=0;i<wyniki::ilosc_elementow;i++)
    {
        wyniki::macierz_wyniki[0][i] = wyniki::przedzial*i+wyniki::katA; //wpisywanie w 0 kolumne macierzy wartosci katow w stopniach
    }
}

void wyniki::sinus(){
    for(int i=0;i<wyniki::ilosc_elementow;i++)
    {
        wyniki::macierz_wyniki[1][i] = sin(wyniki::macierz_wyniki[0][i]/wyniki::dzielnik); //funkcja sin z biblioteki math.h i wpisywanie wartosci w 1 kolumne macierzy
    }
}

void wyniki::cosinus()
{
    for(int i=0;i<wyniki::ilosc_elementow;i++)
    {
        wyniki::macierz_wyniki[2][i] = cos(wyniki::macierz_wyniki[0][i]/wyniki::dzielnik); //funkcja cos z biblioteki math.h i wpisywanie wartosci w 2 kolumne macierzy
    }
}

void wyniki::tanges()
{
    for(int i=0;i<wyniki::ilosc_elementow;i++)
    {
        if(wyniki::macierz_wyniki[2][i] != 0) //Sprawdzenie czy istnieje tanges dla wybranej wartosci
            wyniki::macierz_wyniki[3][i] = wyniki::macierz_wyniki[1][i] / wyniki::macierz_wyniki[2][i]; //obliczanie tangesa, tg=sin/cos, i wpisywanie wartosci w 3 kolumne macierzy
        else
            wyniki::macierz_wyniki[3][i] = 0;
    }
}

void wyniki::cotanges()
{
    for(int i=0;i<wyniki::ilosc_elementow;i++)
    {
        if(wyniki::macierz_wyniki[1][i] != 0) //Sprawdzenie czy istnieje cotanges dla wybranej wartosci
            wyniki::macierz_wyniki[4][i] = wyniki::macierz_wyniki[2][i] / wyniki::macierz_wyniki[1][i]; //obliczanie cotangesa, ctg=cos/sin, i wpisywanie wartosci w 4 kolumne macierzy
        else
            wyniki::macierz_wyniki[4][i] = 0;
    }
}

QString wyniki::generateHTML()
{
    QString text;
    text = "<body><table border='1' width='100%'><tr bgcolor='#ff6A36'><td>Kąt</td><td>Sinus</td><td>Cosinus</td><td>Tanges</td><td>Cotanges</td></tr>";
    for(int i=0;i<wyniki::ilosc_elementow;i++)
    {
        text += "<tr>";
        for(int j=0;j<=4;j++)
        {
            text += "<td>";
            if((wyniki::macierz_wyniki[2][i]==0)&&(j==3))
                text += "Brak";
            else
            {
                if((wyniki::macierz_wyniki[1][i]==0)&&(j==4))
                    text += "Brak";
                else
                    text += QString::number(wyniki::macierz_wyniki[j][i]);
            }
            text += "</td>";
        }
        text += "</tr>";
    }
    text += "</table></body>";
    return text;
}

double wyniki::najwiekszaWartosc(int a){
    double tmp = -100;
    for(int i=0;i<wyniki::ilosc_elementow;i++)
    {
        if(!((wyniki::macierz_wyniki[2][i]==0)&&(a==3)))
                if(!((wyniki::macierz_wyniki[1][i]==0)&&(a==4)))
                    if(wyniki::macierz_wyniki[a][i]>tmp) //Szukanie najwiekszej wartosci (do osi y w wykresie)
                        tmp=wyniki::macierz_wyniki[a][i];
    }
    return tmp;
}

double wyniki::najmniejszaWartosc(int a){
    double tmp = 100;
    for(int i=0;i<wyniki::ilosc_elementow;i++)
    {
        if(!((wyniki::macierz_wyniki[2][i]==0)&&(a==3)))
                if(!((wyniki::macierz_wyniki[1][i]==0)&&(a==4)))
                    if(wyniki::macierz_wyniki[a][i]<tmp) //Szukanie najmniejszej wartosci (do osi y w wykresie)
                        tmp=wyniki::macierz_wyniki[a][i];
    }
    return tmp;
}
