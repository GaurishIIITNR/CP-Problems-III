#ifndef DEBUG_H_
#define DEBUG_H_
#include <bits/stdc++.h>
using namespace std;

namespace debug {
#define deb(x) cerr << #x << " = "; _print(x); cerr << endl;

    template<typename T>
    void _print(T arg) {
        cerr << arg;
    }

    template<typename T, typename U>
    void _print(pair<T, U> p) {
        cerr << "(";
        _print(p.first);
        cerr << ", ";
        _print(p.second);
        cerr << ")";
    }

    template<typename T>
    void _print(vector<T> vec) {
        cerr << "[";

        for (T x : vec) {
            _print(x); cerr << " ";
        }
        cerr << "]";
    }


    template<typename T, typename U>
    void _print(map<T, U> mp) {
        cerr << "{";
        for (auto entry : mp) {
            _print(entry.first);
            cerr << ": ";
            _print(entry.second);
            cerr << ", ";
        }
        cerr << "}";
    }

    template<typename T, typename U>
    void _print(multimap<T, U> mp) {
        cerr << "{";
        for (auto entry : mp) {
            _print(entry.first);
            cerr << ": ";
            _print(entry.second);
            cerr << ", ";
        }
        cerr << "}";
    }

    template<typename T, typename U>
    void _print(unordered_map<T, U> mp) {
        cerr << "{";
        for (auto entry : mp) {
            _print(entry.first);
            cerr << ": ";
            _print(entry.second);
            cerr << ", ";
        }
        cerr << "}";
    }


    template<typename T>
    void _print(set<T> vec) {
        cerr << "{";

        for (T x : vec) {
            _print(x); cerr << " ";
        }
        cerr << "}";
    }

    template<typename T>
    void _print(unordered_set<T> vec) {
        cerr << "{";

        for (T x : vec) {
            _print(x); cerr << " ";
        }
        cerr << "}";
    }

    template<typename T>
    void _print(multiset<T> vec) {
        cerr << "{";

        for (T x : vec) {
            _print(x); cerr << " ";
        }
        cerr << "}";
    }

    template<typename T>
    void _print(stack<T> vec) {
        cerr << "{";

        while (!vec.empty()) {
            _print(vec.top()); cerr << " ";
            vec.pop();
        }
        cerr << "}";
    }

    template<typename T>
    void _print(queue<T> vec) {
        cerr << "{";

        while (!vec.empty()) {
            _print(vec.front()); cerr << " ";
            vec.pop();
        }
        cerr << "}";
    }

    template<typename T>
    void _print(priority_queue<T> vec) {
        cerr << "{";

        while (!vec.empty()) {
            _print(vec.top()); cerr << " ";
            vec.pop();
        }
        cerr << "}";
    }

    template<typename T>
    void _print(deque<T> vec) {
        cerr << "{";

        for (T x : vec) {
            _print(x); cerr << " ";
        }
        cerr << "}";
    }

};

#endif 