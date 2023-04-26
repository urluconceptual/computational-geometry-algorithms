#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

struct punct {
    long long x, y;
};

int testOrientare(punct p, punct q, punct r) {
    long long det = q.x * r.y + p.x * q.y + r.x * p.y - q.x * p.y - r.x * q.y - p.x * r.y;
    if (det < 0)
        return -1; //dreapta
    else if (det > 0)
        return 1; //stanga
    else
        return 0; //touch
}

bool peSegment(punct p, punct q, punct r) {
    if (testOrientare(p, q, r) != 0)
        return false;
    if ((p.x < r.x && r.x > q.x) || (q.x > r.x && r.x < p.x))
        return false;
    if ((p.y < r.y && r.y > q.y) || (q.y > r.y && r.y < p.y))
        return false;
    return true;
}

const string testApartenenta(punct p, vector<punct>& poli) {
    int intersectii = 0;
    for (int i = 0; i < poli.size(); i++) {
        if (peSegment(poli[i], poli[(i + 1) % poli.size()], p))
            return "BOUNDARY";
        if ((p.y < poli[i].y) != (p.y < poli[(i + 1) % poli.size()].y)) {
            double xBoundary = poli[i].x + (double)(p.y - poli[i].y) / (poli[(i + 1) % poli.size()].y - poli[i].y) * (poli[(i + 1) % poli.size()].x - poli[i].x);
            if (p.x < xBoundary) {
                intersectii++;
            }
        }
    }
    if (intersectii % 2 == 0)
        return "OUTSIDE";
    return "INSIDE";
}

int main()
{
    int n, m;
    punct curr;
    vector<punct> poligon;
    cin >> n;
    while (n--) {
        cin >> curr.x >> curr.y;
        poligon.push_back(curr);
    }
    cin >> m;
    while (m--) {
        cin >> curr.x >> curr.y;
        cout << testApartenenta(curr, poligon) << "\n";
    }
}