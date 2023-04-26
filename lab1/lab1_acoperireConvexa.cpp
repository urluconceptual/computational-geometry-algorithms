#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct punct {
    long long x, y;
};

long long testOrientare(punct p, punct q, punct r) {
    long long det = q.x * r.y + p.x * q.y + r.x * p.y - q.x * p.y - r.x * q.y - p.x * r.y;
    return det;
}

bool comparaPuncte(punct p1, punct p2)
{
    if (p1.x == p2.x)
        return p1.y < p2.y;
    else
        return p1.x < p2.x;
}

vector<punct> limita(vector<punct>& P, int n) {
    vector<punct> L;
    L.push_back(P[0]);
    L.push_back(P[1]);

    for (int i = 2; i < n; i++) {
        L.push_back(P[i]);
        int s = L.size();
        while (s > 2 && testOrientare(L[s - 3], L[s - 2], L[s - 1]) <= 0) {
            L.erase(L.begin() + s - 2);
            s--;
        }
    }
    return L;
}

int main()
{
    int n;
    punct curr;
    vector<punct> P, Li, Ls;
    cin >> n;

    while (n--) {
        cin >> curr.x >> curr.y;
        P.push_back(curr);
    }

    sort(P.begin(), P.end(), comparaPuncte);
    Li = limita(P, P.size());

    reverse(P.begin(), P.end());
    Ls = limita(P, P.size());

    cout << Li.size() + Ls.size() - 2 << "\n";

    for (int i = 1; i < Li.size(); i++) {
        cout << Li[i].x << " " << Li[i].y << "\n";
    }

    for (int i = 1; i < Ls.size(); i++) {
        cout << Ls[i].x << " " << Ls[i].y << "\n";
    }

    return 0;
}