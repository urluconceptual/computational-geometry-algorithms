#include <iostream>
#include <limits>
#include <cfloat>

using namespace std;

double minX = -DBL_MAX, maxX = DBL_MAX, minY = -DBL_MAX, maxY = DBL_MAX;

struct semiplan {
    long long a, b, c;
};

void intersectieSemiplane(semiplan s) {
    double min = -DBL_MAX, max = DBL_MAX;
    if (s.a == 0) { //semiplan vertical
        if (s.b < 0) //semiplan in dreapta dreptei
            min = -1 * (double)s.c / s.b; //rezolv ecuatia dreptei pentru y cel mai din stanga
        else //semiplan in stanga dreptei
            max = -1 * (double)s.c / s.b; //rezolv ecuatia dreptei pentru y cel mai din dreapta
        minY = minY > min ? minY : min;
        maxY = maxY < max ? maxY : max;
    }
    else { //semiplan orizontal
        if (s.a < 0) //semiplan deasupra dreptei
            min = -1 * (double)s.c / s.a; //rezolv ecuatia dreptei pentru x cel mai de jos
        else //semiplan sub dreapta
            max = -1 * s.c / s.a; //rezolv ecuatia dreptei pentru x cel mai de sus
        minX = minX > min ? minX : min;
        maxX = maxX < max ? maxX : max;
    }
}

int main()
{
    long long n;
    semiplan aux;
    cin >> n;
    while (n--) {
        cin >> aux.a >> aux.b >> aux.c;
        intersectieSemiplane(aux);
    }
    if (minY > maxY || minX > maxX) //daca nu am gasit valori compatibile, nu exista intersectie
        cout << "VOID";
    else
        if ((minX != -DBL_MAX && maxX != DBL_MAX) && (minY != -DBL_MAX && maxY != DBL_MAX)) //daca am gasit valori compatibile si diferite de infinit pentru toate colturile, intersectia e marginita
            cout << "BOUNDED";
        else
            cout << "UNBOUNDED"; //daca am gasit valori compatibile, dar una din ele e infinita, intersectia e nemarginita
    return 0;
}