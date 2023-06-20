#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_set>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
#endif
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define _rep(i, n) _rep2(i, 0, n)
#define _rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(...) GET_MACRO(__VA_ARGS__, _rep2, _rep)(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define UNIQUE(x)                      \
    std::sort((x).begin(), (x).end()); \
    (x).erase(std::unique((x).begin(), (x).end()), (x).end())
using i64 = long long;
template <class T, class U>
bool chmin(T& a, const U& b) {
    return (b < a) ? (a = b, true) : false;
}
template <class T, class U>
bool chmax(T& a, const U& b) {
    return (b > a) ? (a = b, true) : false;
}
inline void YesNo(bool f = 0, string yes = "Yes", string no = "No") {
    std::cout << (f ? yes : no) << "\n";
}
namespace io {
template <typename T>
istream& operator>>(istream& i, vector<T>& v) {
    rep(j, v.size()) i >> v[j];
    return i;
}
template <typename T>
string join(vector<T>& v) {
    stringstream s;
    rep(i, v.size()) s << ' ' << v[i];
    return s.str().substr(1);
}
template <typename T>
ostream& operator<<(ostream& o, vector<T>& v) {
    if (v.size()) o << join(v);
    return o;
}
template <typename T>
string join(vector<vector<T>>& vv) {
    string s = "\n";
    rep(i, vv.size()) s += join(vv[i]) + "\n";
    return s;
}
template <typename T>
ostream& operator<<(ostream& o, vector<vector<T>>& vv) {
    if (vv.size()) o << join(vv);
    return o;
}

template <class T, class U>
istream& operator>>(istream& i, pair<T, U>& p) {
    i >> p.first >> p.second;
    return i;
}

template <class T, class U>
ostream& operator<<(ostream& o, pair<T, U>& p) {
    o << p.first << " " << p.second;
    return o;
}

void print() { cout << "\n"; }

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail)) cout << ' ';
    print(std::forward<Tail>(tail)...);
}

void in() {}

template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
    cin >> head;
    in(std::forward<Tail>(tail)...);
}

}  // namespace io
using namespace io;

namespace useful {
long long modpow(long long a, long long b, long long mod) {
    long long res = 1;
    while (b) {
        if (b & 1) res *= a, res %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return res;
}

bool is_pow2(long long x) { return x > 0 && (x & (x - 1)) == 0; }

template <class T>
void rearrange(vector<T>& a, vector<int>& p) {
    vector<T> b = a;
    for (int i = 0; i < int(a.size()); i++) {
        a[i] = b[p[i]];
    }
    return;
}

template <class T>
vector<pair<int, int>> rle_sequence(T& a) {
    vector<pair<int, int>> res;
    int n = a.size();
    if (n == 1) return vector<pair<int, int>>{{a[0], 1}};
    int l = 1;
    rep(i, n - 1) {
        if (a[i] == a[i + 1])
            l++;
        else {
            res.emplace_back(a[i], l);
            l = 1;
        }
    }
    res.emplace_back(a.back(), l);
    return res;
}

vector<pair<char, int>> rle_string(string a) {
    vector<pair<char, int>> res;
    int n = a.size();
    if (n == 1) return vector<pair<char, int>>{{a[0], 1}};
    int l = 1;
    rep(i, n - 1) {
        if (a[i] == a[i + 1])
            l++;
        else {
            res.emplace_back(a[i], l);
            l = 1;
        }
    }
    res.emplace_back(a.back(), l);
    return res;
}

vector<int> linear_sieve(int n) {
    vector<int> primes;
    vector<int> res(n + 1);
    iota(all(res), 0);
    for (int i = 2; i <= n; i++) {
        if (res[i] == i) primes.emplace_back(i);
        for (auto j : primes) {
            if (j * i > n) break;
            res[j * i] = j;
        }
    }
    return res;
    // return primes;
}

template <class T>
vector<long long> dijkstra(vector<vector<pair<int, T>>>& graph, int start) {
    int n = graph.size();
    vector<long long> res(n, 2e18);
    res[start] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        que;
    que.push({0, start});
    while (!que.empty()) {
        auto [c, v] = que.top();
        que.pop();
        if (res[v] < c) continue;
        for (auto [nxt, cost] : graph[v]) {
            auto x = c + cost;
            if (x < res[nxt]) {
                res[nxt] = x;
                que.push({x, nxt});
            }
        }
    }
    return res;
}

}  // namespace useful
using namespace useful;

