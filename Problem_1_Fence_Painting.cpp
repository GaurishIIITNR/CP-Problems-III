// हर हर महादेव

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

#define vin(v) for(auto &x:v)cin >> x
#define deb(v) cout << #v << " " << v << "\n"
#define vout(v) for(auto x:v)cout << x << " " ;cout<<endl
#define deb2(v, k) cout << #v << " " << v << "\n" \<< #k << " " << k << "\n"

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;




void dfs(vector<ll>* adj, ll src, ll par, vector<ll>& lev, ll cnt) {
    lev[src] = cnt; cnt++;
    for (auto x : adj[src]) {
        if (x != par) {
            dfs(adj, x, src, lev, cnt);
        }
    }
}

void HHM() {
    ll  n, i, j, k;
    cin >> n;  vector<ll>adj[n + 1];
    for (i = 2;i <= n; i++) {
        ll d; cin >> d;
        adj[d].push_back(i); adj[i].push_back(d);
    }

    vector<ll>lev(n + 1, 0);
    ll leaf = 0, mx = 0;
    dfs(adj, 1, 0, lev, 0);

    for (i = 1; i <= n; i++) {
        if (mx < lev[i]) {
            mx = lev[i]; leaf = i;
        }
    }

    lev.assign(n + 1, 0);
    dfs(adj, leaf, 0, lev, 0);

    ll leaf1 = 0, mx1 = 0;
    for (i = 1; i <= n; i++) {
        if (mx1 < lev[i]) {
            mx1 = lev[i]; leaf1 = i;
        }
    }

    vector<ll>lev2(n + 1, 0);
    dfs(adj, leaf1, 0, lev2, 0);

    multiset<ll>l1, l2;
    for (i = 1; i <= n; i++) {
        l1.insert(lev[i]);
        l2.insert(lev2[i]);
    }


    vector<pair<ll, ll>>lev_ord, lev1_ord;
    for (i = 0;i < n; i++) {
        lev_ord.push_back({ lev[i + 1], i + 1 });
        lev1_ord.push_back({ lev2[i + 1], i + 1 });
    }

    sort(all(lev_ord)); sort(all(lev1_ord));
    vector<ll>res;

    ll ans = lev_ord.back().first;
    map<ll, bool>mp;
    ll fin = ans;



    for (i = n - 1; i > 0; i--) {
        mp[i] = true;
        while (mp[lev1_ord.back().second]) {
            lev1_ord.pop_back();
        }
        while (mp[lev_ord.back().second]) {
            lev_ord.pop_back();
        }
        ll lb = fin - lev1_ord.back().first;
        ll ub = fin - lev_ord.back().first;

        res.pb(ans - lb - ub);
    }
    // res.pb(1);
    reverse(all(res));

    vout(res);

    cout << endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}






string fractionToDecimal(int numerator, int denominator) {
    string ans;
    string final_ans;
    if ((numerator < 0 && denominator>0) || (numerator > 0 && denominator < 0)){
        ans.append("-");
    }
    long int d = abs(denominator);
    long int n = abs(numerator);

    ans = ans + to_string((long int)(n / d));
    unordered_map<long, int> m;
    long int remainder = n % d;
    if (remainder != 0)
    {
        ans.append(".");
        while (ans.size() < 10001)
        {
            if (remainder == 0 || m.find(remainder) != m.end())
            {
                break;
            }
            m[remainder] = ans.size();
            long int t = (remainder * 10) / d;
            ans.append(to_string(t));
            remainder = (remainder * 10) % d;
        }
        if (m.find(remainder) != m.end())
        {
            final_ans = ans.substr(0, m[remainder])
                + "(" +
                ans.substr(m[remainder])
                + ")";
        }
        else {
            final_ans = ans;
        }
    }
    else
        final_ans = ans;
    return final_ans;
}


int findLongestConseqSubseq(int arr[], int n)
{
    unordered_set<int> S;
    int ans = 0;

    for (int i = 0; i < n; i++)
        S.insert(arr[i]);

    for (int i = 0; i < n; i++) {
        if (S.find(arr[i] - 1) != S.end()) {
            continue;
        }
        else {
            int j = arr[i];
            while (S.find(j) != S.end())
                j++;

            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
}