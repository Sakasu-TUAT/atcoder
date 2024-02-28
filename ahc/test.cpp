 
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits>
#include <cmath>
#include <iomanip>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cinttypes>
#include <algorithm>
#include <cstdlib>
#include <ranges>
#include <numeric>
#include <atcoder/all>

#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)

#define rrep(i,a,b) for (ll i = (a); i >= ll(b); i--)
#define cauto const auto&
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vd = vector<double>;
using vld = vector<long double>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vs = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
using vb = vector<bool>;
using vvb = vector<vb>;

int gcd(int a,int b){return b?gcd(b,a%b):a;}
template <class T, class U>
bool chmin(T& a, const U& b) {return (b < a) ? (a = b, true) : false;}
template <class T, class U>
bool chmax(T& a, const U& b) {return (b > a) ? (a = b, true) : false;}
void in() {}
void printMatrix(const auto &vec){for(const auto &v : vec){ for(const auto &e : v){cerr << e << " ";}cerr << endl;}}
template<class T> void printTable(const vector<vector<T>> &tb){ for(const auto &i : tb){ for(const auto &j : i){cerr << j << " ";}cerr << endl;}}
template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
    cin >> head;
    in(std::forward<Tail>(tail)...);
}
const ll INF = 1LL << 60;
const ll mod = 998244353;
using namespace atcoder;
using mint = modint998244353;
struct Edge {ll to; ll cost;};
using Graph = vector<vector<Edge>>;
const ll dx[4] = {0, 1, 0, -1};
const ll dy[4] = {1, 0, -1, 0};


int main(){
    ll score = 0;
    auto calc_move = [&](vl &from, vl &to, ll v){
        int idx = 0;
        rep(k,0,size(from)) if(from[k] == v) idx = k;
        vl m = vl(from.begin() + idx, from.end());
        to.insert(to.end(), all(m)); 
        score += (from.size() - idx);
        from.erase(from.begin() + idx, from.end());
    };
    vl a = {1, 2, 3, 4};
    vl b = {5, 6, 7, 8, 9};
    calc_move(a, b, 1);
    for(cauto v : a){
        cerr << v << " ";
    }cerr << endl;
    for(cauto v : b){
        cerr << v << " ";
    }cerr << endl;
    cout << "score :" << score << endl;
}