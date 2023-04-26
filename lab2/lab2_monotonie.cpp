#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;


struct punct {
    long long x, y;
};

vector<punct> poligon;

const string monotonX() {
    int schimbaDirectie = 0;
    bool semafor;
    if (poligon[0].x < poligon[1].x)
        semafor = true;
    else
        semafor = false;
    for (int i = 1; i < poligon.size()-1; i++) {
        if (semafor && poligon[i].x > poligon[i + 1].x) {
            semafor = false;
            schimbaDirectie++;
        }
        else if (!semafor && poligon[i].x < poligon[i + 1].x) {
            semafor = true;
            schimbaDirectie++;
        }
    }
    if (schimbaDirectie == 2 || schimbaDirectie == 1)
        return "YES";
    else
        return "NO";
}

const string monotonY() {
    int schimbaDirectie = 0;
    bool semafor;
    if (poligon[0].y < poligon[1].y)
        semafor = true;
    else
        semafor = false;
    for (int i = 1; i < poligon.size()-1; i++) {
        if (semafor && poligon[i].y > poligon[i + 1].y) {
            semafor = false;
            schimbaDirectie++;
        }
        else if (!semafor && poligon[i].y < poligon[i + 1].y) {
            semafor = true;
            schimbaDirectie++;
        }
    }
    if (schimbaDirectie == 2 || schimbaDirectie == 1)
        return "YES";
    else
        return "NO";
}

int main()
{
    int n, m;
    punct curr;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> curr.x >> curr.y;
        poligon.push_back(curr);
    }
    cout << monotonX() << "\n";
    cout << monotonY() << "\n";
}