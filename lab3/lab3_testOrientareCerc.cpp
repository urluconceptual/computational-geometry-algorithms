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

const string testOrientareCerc(punct p, punct q, punct r, punct aux) {
    long long det = - determinant(q.x - p.x, r.x - p.x, aux.x - p.x, q.y - p.y, r.y - p.y, aux.y - p.y, (q.x * q.x + q.y * q.y) - (p.x * p.x + p.y * p.y), (r.x * r.x + r.y * r.y) - (p.x * p.x + p.y * p.y), (aux.x * aux.x + aux.y * aux.y) - (p.x * p.x + p.y * p.y));
    if (det < 0)
        return "OUTSIDE";
    if (det > 0)
        return "INSIDE";
    return "BOUNDARY";
}

int main()
{
    int t;
    punct p, q, r, aux;
    cin >> p.x >> p.y >> q.x >> q.y >> r.x >> r.y;
    cin >> t;
    while (t--) {
        cin >> aux.x >> aux.y;
        cout << testOrientareCerc(p, q, r, aux) << "\n";
    }

    return 0;
}