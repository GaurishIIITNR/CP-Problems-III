// Warning: Coding is an addiction.

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define F first
#define S second
#define dbl double
#define pb push_back
#define ll long long int
#define uset unordered_set
#define umap unordered_map
long long int mod = 1000000007;
#define all(x) x.begin(), x.end()
#define Pi 3.1415926535897932384626

#define vin(v) for(auto &z: v)cin >> z
#define deb(v) cout << #v << " = " << v <<  endl
#define vout(v) for(auto z:v)cout << z << " " ; cout<<endl
#define deb2(v, k) cout << #v << " = " << v << " "<< #k << " = " << k << endl;
#define pout(mp) for(auto z: mp)cout << z.F << " " << z.S << endl

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;

void HHM() {
    ll  n, i, j, k;
    cin >> n >> k;

    vector<pair<ll, ll>> vp(n);

    ll ans = 0;
    for (i = 0; i < n; i++) {
        cin >> vp[i].S >> vp[i].F;
        if (vp[i].S <= k) ans = 1;
    }

    sort(all(vp), [&](pair<ll, ll>& a, pair<ll, ll>& b) {
        if (a.F == b.F) return a.S < b.S;
        return a.F < b.F;
        });

    // pout(vp);

    for (i = 0; i < n; i++) {
        priority_queue<ll> pq;
        ll cnt = 0, sm = 0;

        for (j = i; j < n; j++) {
            ll rem = k - abs(vp[j].F - vp[i].F);

            if (sm + vp[j].S <= rem) {
                sm += vp[j].S; cnt++; ans = max(ans, cnt); pq.push(vp[j].S);
                continue;
            }

            else {
                if (pq.size() && pq.top() > vp[j].S) {
                    sm -= pq.top(); pq.pop();
                    sm += vp[j].S;
                    pq.push(vp[j].S);
                }

                while (pq.size() && sm > rem) {
                    sm -= pq.top(); pq.pop(); cnt--;
                }

                if (sm <= rem) {
                    ans = max(ans, cnt);
                }
            }
        }
    }

    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
