// #include <bits/stdc++.h>
// using namespace std;
// #define ll int 
// #define dbl double



// dbl f(ll n, ll zz, ll oo, ll tt) {
    
//     dbl dp[n + 1][n + 1][n + 1];
//     for (int z = n; z >= 0; z--) {
//         for (int o = n; o >= 0; o--) {
//             for (int t = n; t >= 0; t--) {
                
//                 if (z == n) {
//                     dp[z][o][t] = 0.0; continue;
//                 }

//                 bool flag = 0;
//                 dbl ans = 1.0;

//                 if (z > 0) flag = 1;

//                 if (o > 0) {
//                     ans += ((o / (dbl)n) * dp[z + 1][o - 1][t]);
//                 }

//                 if (t > 0) {
//                     ans += (t / (dbl)n) * dp[z][o + 1][t - 1];
//                 }

//                 if (n - z - o - t > 0) {
//                     ans += ((n - z - o - t) / (dbl)n) * dp[z][o][t + 1];
//                 }

//                 if (flag) {
//                     ans *= (n / (dbl)(n - z));
//                 }

//                 dp[z][o][t] = ans;
//             }
//         }
//     }
//     return dp[zz][oo][tt];
// }


// int main() {

//     ll n; cin >> n;
//     vector<ll>v(n);
//     for (auto& i : v) cin >> i;

//     ll z = 0, o = 0, t = 0;
//     for (int i = 0; i < n; i++) {
//         if (v[i] == 0) z++;
//         else if (v[i] == 1) o++;
//         else if (v[i] == 2)t++;
//     }
//     cout << fixed << setprecision(15) << f(n, z, o, t) << endl;

//     return 0;
// }


#include <stdio.h>
#include <string.h>

int main() {
    int n, x;
    scanf("%d", &n);
    char array[n][100];

    for (int i = 0; i < n; i++) {
        scanf("%s", array[i]);
    }

    for (int i = 0; i < n; i++) {
        x = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(array[i], array[j]) == 0) {
                printf("YES\n");
                x = 1;
                break;
            }
        }
        if (x == 0) {
            printf("NO\n");
        }
    }

    return 0;
}
