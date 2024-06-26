#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

struct point {
    ll x, y;
};

__int128 calculateArea(const vector<point>& v) {
    __int128 n = v.size();
    __int128 area = 0;
    for (__int128 i = 0; i < n; i++) {
        __int128 j = (i + 1) % n;
        area += (__int128)v[i].x * (__int128)v[j].y;
        area -= (__int128)v[i].y * (__int128)v[j].x;
    }
    if(area < 0) area *= -1;
    return area;
}

int main() {
    long long n;
    cin >> n;

    vector<point> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
    }

    __int128 area = calculateArea(v);
    cout << (long long)area;

    return 0;
}