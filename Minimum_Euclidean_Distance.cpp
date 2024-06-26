#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

#define mod 1000000007
struct Point {
    ll x;
    ll y;
};

// error always comparetor func should be type bool 
bool cmpX(Point p1, Point p2) {
    return (p1.x < p2.x);
}

bool cmpY(Point p1, Point p2) {
    return (p1.y < p2.y);
}

ll distance(Point p1, Point p2) {
    return ((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y));
}

ll bruteForce(vector<Point>& p, ll size) {
    ll d = LLONG_MAX;
    for (ll i = 0;i < size;++i) {
        for (ll j = i + 1;j < size;++j) {
            (d = min(d, distance(p[i], p[j])));
        }
    }
    return d;
}

ll case3Fun(vector<Point>& Ysorted, ll size, ll n) {
    ll mindistance = n;
    
    //Added sort by compY
    sort(Ysorted.begin(), Ysorted.end(), cmpY);
    
    for (ll i = 0;i < size;i++) {
        for (ll j = i + 1;j < min(size, i + 1 + 7);++j) {
            (mindistance = min(mindistance, distance(Ysorted[i], Ysorted[j])));
        }
    }
    return mindistance;
}

ll recursiveClosest(vector<Point>& Xsorted, ll n) {
    // fine
    if (n <= 3) {
        return bruteForce(Xsorted, n);
    }

    // fine 
    ll mid = n / 2;
    Point midpoint = Xsorted[mid];
    vector<Point>left;
    vector<Point>right;

    // fine
    for (ll i = 0;i < mid;++i) {
        left.push_back(Xsorted[i]);
    }
    for (ll i = mid;i < n;++i) {
        right.push_back(Xsorted[i]);
    }

    // fine
    ll d1 = recursiveClosest(left, mid);
    ll d2 = recursiveClosest(right, n - mid);
    ll d = min(d1, d2);

    // Resolved
    vector<Point>case3;
    for (ll i = 0;i < n;i++) {
        // error compare with d(which is squared dist not simple dist) with square of diff 
        // error use Xsorted instead of Ysorted
        // resolved
        if (abs(midpoint.x - Xsorted[i].x) * abs(midpoint.x - Xsorted[i].x) < d) {
            case3.push_back(Xsorted[i]);
        }
    }
    // error pass case3 as argument not Ysorted
    // and 2nd argument should not be n because if u send size to n
    // then it could take n^2 complexity which can give TLE
    //Resolved
    return min(d, case3Fun(case3, case3.size(), d));
}

void solve() {
    ll n;
    cin >> n;
    vector<Point>point;
    for (ll i = 0;i < n;i++) {
        ll x, y;
        cin >> x >> y;

        point.push_back({ x,y });
    }
    vector<Point>Xsorted = point;
    // vector<Point>Ysorted = point;
    sort(Xsorted.begin(), Xsorted.end(), cmpX);
    // sort(Ysorted.begin(), Ysorted.end(), cmpY);


    // No need to sort Ysorted, as it is already sorted in Xsorted
    cout << recursiveClosest(Xsorted, n);
    return;
}
int main() {
    solve();
    return 0;
}