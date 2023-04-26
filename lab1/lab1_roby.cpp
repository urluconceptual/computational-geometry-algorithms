#include <iostream>
#include <string>

using namespace std;

int right = 0, left = 0, touch = 0;

struct punct {
    long long x, y;
};

void testOrientare(punct p, punct q, punct r) {
    long long det = q.x * r.y + p.x * q.y + r.x * p.y - q.x * p.y - r.x * q.y - p.x * r.y;
    if (det < 0)
        ::right++;
    else if (det > 0)
        ::left++;
    else
        ::touch++;
}

int main()
{
    int n;
    punct start, p, q, r;
    cin >> n;
    cin >> q.x >> q.y >> r.x >> r.y;
    start = q;
    n -= 2;
    while (n--) {
        p = q;
        q = r;
        cin >> r.x >> r.y;
        testOrientare(p, q, r);
    }
    testOrientare(q, r, start);
    cout << ::left << " " << ::right << " " << ::touch;
    return 0;
}