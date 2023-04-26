#include <iostream>
#include <string>

using namespace std;

struct punct {
    long long x, y;
};

const string testOrientare(punct p, punct q, punct r) {
    long long det = q.x * r.y + p.x * q.y + r.x * p.y - q.x * p.y - r.x * q.y - p.x * r.y;
    if (det < 0)
        return "RIGHT";
    if (det > 0)
        return "LEFT";
    return "TOUCH";
}

int main()
{
    int t;
    punct p, q, r;
    cin >> t;
    while (t--) {
        cin >> p.x >> p.y >> q.x >> q.y >> r.x >> r.y;
        cout << testOrientare(p, q, r) << "\n";
    }

    return 0;
}