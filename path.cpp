#include <bits/stdc++.h>
using namespace std;
#define ll long long 

void dfs(vector<ll>& par, ll src, ll dest) {

}

vector<int>par; // lets this is already filled

void route(int src, int dest) {
    //Lets assume path exist between src and dest
    vector<int> path1, path2;
    int node = dest;
    while (node != -1) {
        path1.push_back(node);
        node = par[node];
    }
    node = src;
    while (node != -1) {
        path2.push_back(node);
        node = par[node];
    }
    reverse(path2.begin(), path2.end());
}

int main() {
    ll n; cin >> n;
    vector<ll>par(n); for (auto& x : par) cin >> x;
}
