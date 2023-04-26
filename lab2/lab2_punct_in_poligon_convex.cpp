#include <iostream>
#include <vector>
#include <string>

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
    if ((p.x < r.x && r.x > q.x) || (q.x < r.x && r.x > p.x))
        return false;
    if ((p.y < r.y && r.y > q.y) || (q.y < r.y && r.y > p.y))
        return false;
    return true;
}

const string testApartenenta(punct p, punct poli[], int n) {
    int min = 1, max = n - 1, mid = (min + max) / 2, pivot = 0, pos, ok = 0;
    if (testOrientare(poli[pivot], poli[max], p) == 1 || testOrientare(poli[pivot], poli[min], p) == -1)
        return "OUTSIDE";
    if (testOrientare(poli[pivot], poli[max], p) == 0 || testOrientare(poli[pivot], poli[min], p) == 0)
        ok = 1;
    while (true) {
        if (max - min == 1) {
            pos = testOrientare(poli[min], poli[max], p);
            if ((pos == 0 && peSegment(poli[min], poli[max], p)) || (pos == 1 && ok == 1)) {
                return "BOUNDARY";
            }
            if (pos == 1)
                return "INSIDE";
            return "OUTSIDE";
        }
        mid = (min + max) / 2;
        pos = testOrientare(poli[pivot], poli[mid], p);
        if (pos == -1)
            max = mid;
        else
            min = mid;
    }
}

int main()
{
    int n, m;
    punct curr;
    cin >> n;
    punct* poligon = new punct[n];
    cin >> poligon[0].x >> poligon[0].y;
    for (int i = 1; i < n; i++) {
        cin >> curr.x >> curr.y;
        if (i != 1 && ((poligon[i - 1].x == curr.x && poligon[i - 2].x == curr.x) || (poligon[i - 1].y == curr.y && poligon[i - 2].y == curr.y))) {
            i--;
            n--;
        }
        poligon[i] = curr;
    }
    cin >> m;
    while (m--) {
        cin >> curr.x >> curr.y;
        cout << testApartenenta(curr, poligon, n) << "\n";
    }
    delete[] poligon;
}