#include <iostream>
#include <limits>
#include <cfloat>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct semiplan {
    long long a, b, c;
};

struct punct {
    double x, y;
};

bool verifMargini(double minX, double maxX, double minY, double maxY) {
    if (minX == -DBL_MAX || maxX == DBL_MAX || minY == -DBL_MAX || maxY == DBL_MAX)
        return false;
    return true;
}

bool verifPunct(double minX, double maxX, double minY, double maxY, punct q) {
    if ((q.x == minX || q.x == maxX) && (q.y == minY || q.y == maxY))
        return true;
    if ((minX < q.x && q.x < maxX) && (minY < q.y && q.y < maxY))
        return true;
    return false;
}

void testOrientare(vector<semiplan>& semiplane, punct q) {
    double minX = -DBL_MAX, maxX = DBL_MAX, minY = -DBL_MAX, maxY = DBL_MAX;
    for (auto s : semiplane) {
        double min = -DBL_MAX, max = DBL_MAX;
        if (s.a == 0) { //semiplan orizonal
            if (s.c + s.b * q.y > 0) //punctul nu respecta inecuatia semiplanului
                continue;
            if (s.b < 0) //semiplan in dreapta dreptei
                min = -1 * (double)s.c / s.b; //rezolv ecuatia dreptei pentru y cel mai din stanga
            else //semiplan in stanga dreptei
                max = -1 * (double)s.c / s.b; //rezolv ecuatia dreptei pentru y cel mai din dreapta
            minY = minY > min ? minY : min;
            maxY = maxY < max ? maxY : max;
        }
        else { //semiplan vertical
            if (s.c + s.a * q.x > 0) //punctul nu respecta inecuatia semiplanului
                continue;
            if (s.a < 0) //semiplan deasupra dreptei
                min = -1 * (double)s.c / s.a; //rezolv ecuatia dreptei pentru x cel mai de jos
            else //semiplan sub dreapta
                max = -1 * (double)s.c / s.a; //rezolv ecuatia dreptei pentru x cel mai de sus
            minX = minX > min ? minX : min;
            maxX = maxX < max ? maxX : max;
        }
    }
    if (verifMargini(minX, maxX, minY, maxY) && verifPunct(minX, maxX, minY, maxY, q))
        cout << "YES\n" << setprecision(6) << (maxX - minX) * (maxY - minY) << '\n';
    else
        cout << "NO\n";
}

int main()
{
    long long n, m;
    punct q;
    semiplan aux;
    vector<semiplan> semiplane;
    cin >> n;
    while (n--) {
        cin >> aux.a >> aux.b >> aux.c;
        semiplane.push_back(aux);
    }
    cin >> m;
    cout<<std::fixed;
    while (m--) {
        cin >> q.x >> q.y;
        testOrientare(semiplane, q);
    }
}