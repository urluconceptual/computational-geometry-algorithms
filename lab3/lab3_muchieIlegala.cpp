#include <iostream>
#include <string>

using namespace std;

struct punct {
    long long x, y;
};

long long determinant(long long p1, long long p2, long long p3, long long q1, long long q2, long long q3, long long r1, long long r2, long long r3)
{
    return p1 * q2 * r3 + p2 * q3 * r1 + q1 * r2 * p3 - (r1 * q2 * p3 + r2 * q3 * p1 + p2 * q1 * r3);
}

const string muchieIlegala(punct p, punct q, punct r, punct t) {
    long long det = -determinant(q.x - p.x, r.x - p.x, t.x - p.x, q.y - p.y, r.y - p.y, t.y - p.y, (q.x * q.x + q.y * q.y) - (p.x * p.x + p.y * p.y), (r.x * r.x + r.y * r.y) - (p.x * p.x + p.y * p.y), (t.x * t.x + t.y * t.y) - (p.x * p.x + p.y * p.y));
    if (det > 0)
        return "ILLEGAL";
    return "LEGAL";
}

int main()
{
    punct p, q, r, t;
    cin >> p.x >> p.y >> q.x >> q.y >> r.x >> r.y >> t.x >> t.y;
    cout << "AC: "<< muchieIlegala(p, q, r, t) << '\n';
    cout << "BD: " << muchieIlegala(q, r, t, p) << '\n';
    return 0;
}