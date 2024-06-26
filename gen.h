#ifndef GEN_H_
#define GEN_H_
#include <bits/stdc++.h>

using namespace std;

namespace gen {
    template<typename T>
    T random(T rf, T rt) {
        random_device                  rand_dev;
        mt19937                        genr(rand_dev());
        uniform_int_distribution<T>    distr(rf, rt);
        return distr(genr);
    }

    template<typename T>
    T gen(T l, T r) {
        return random(l, r);
    }

    template<typename T, typename U>
    string gen_str(T n, U l, U r) {
        string str; for (T i = 0; i < n; i++) {
            str.push_back(gen(l, r));
        }
        return str;
    }

    template<typename T, typename U>
    vector<T> gen_vec(T n, U l, U r) {
        vector<T> ans;
        for (T i = 0; i < n; i++) {
            ans.push_back(gen(l, r));
        }
        return ans;
    }
};

#endif 