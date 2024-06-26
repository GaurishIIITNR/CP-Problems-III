#include <bits/stdc++.h>
using namespace std;
#define ll long long 

struct node {
    ll par, sz, rank;
    node() {
        par = -1;
        sz = 1;
        rank = 0;
    }
};


struct dsu {
    ll n;
    vector<node> tr;

    DSU(ll n) {
        this->n = n;
        tr.assign(n, new node());
    }

    ll findPar(ll u) {
        if (tr[u].par == -1) return u;

        // used path compression
        return tr[u].par = findPar(tr[u].par);
    }

    void UnionByRank(ll u, ll v) {
        ll pu = findPar(u);
        ll pv = findPar(v);
        if (pu == pv) return;

        if (tr[pu].rank == tr[pv].rank) {
            tr[pu].rank++; tr[pv].par = pu;
        }
        else if (rank[pu] > rank[pv]) tr[pv].par = pu;
        else tr[pu].par = pv;    return;
    }

    void UnionBySz(ll u, ll v) {
        ll pu = findPar(u);
        ll pv = findPar(v);
        if (pu == pv) return;

        if (tr[pu].sz >= tr[pv].sz)tr[pu].sz += tr[pv].sz, tr[pv].par = pu;
        else tr[pv].sz += tr[pu].sz, tr[pu].par = pv;
        return;
    }

    // bool get(ll u, ll v) {
    //     return findPar(u) == findPar(v);
    // }

    // ll gett(ll u) {
    //     if (u == -1) return 0;
    //     ll ans = tr[u].sz;
    //     ans += get(tr[u].par);
    //     return ans;
    // }
};

int main() {

}
