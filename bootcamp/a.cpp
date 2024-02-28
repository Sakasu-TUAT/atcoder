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
#include <unordered_set>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cinttypes>
#include <algorithm>
#include <cstdlib>
#include <ranges>
#include <numeric>
#include <atcoder/all>

#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)
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
template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (int i = 0; i < v.size(); ++i)
        is >> v[i];
    return is;
}

const ll INF = 1LL << 60;
// const ll mod = 1000000007;
const ll mod = 998244353;
using namespace atcoder;
// using mint = modint1000000007;
// using mint = modint998244353;
using Graph = vector<vector<ll>>;
// struct Edge {ll to;};
// struct Edge {ll to; ll cost;};
// using Graph = vector<vector<Edge>>;

vl dijkstra(cauto G, ll start){
    vl cost(G.size(), INF);
    priority_queue<P, vector<P>, greater<P>> pq; //cost, nvがcostで昇順
    pq.emplace(cost[start] = 0, start);
    while(!pq.empty()){
        auto [curCost, cv]  = pq.top(); pq.pop();
        if(curCost > cost[cv]) continue;
        for(cauto [nv, nxCost] : G[cv]){
            if(chmin(cost[nv], cost[cv]+nxCost)){
                pq.emplace(cost[nv], nv);
            }
        }
    }
    return cost;
}

const ll dx[4] = {0, 1, 0, -1};
const ll dy[4] = {1, 0, -1, 0};
// 1 以上 N 以下の整数が素数かどうかを返す
vector<bool> Eratosthenes(ll N) {
    // テーブル
    vector<bool> isprime(N+1, true);

    // 0, 1 は予めふるい落としておく
    isprime[0] = isprime[1] = false;

    // ふるい
    for (ll p = 2; p <= N; ++p) {
        // すでに合成数であるものはスキップする
        if (!isprime[p]) continue;

        // p 以外の p の倍数から素数ラベルを剥奪
        for (ll q = p * 2; q <= N; q += p) {
            isprime[q] = false;
        }
    }

    // 1 以上 N 以下の整数が素数かどうか
    return isprime;
}

int main() {
   ll h, w; cin >> h >> w;
   vvc a(h, vc(w)), b(h, vc(w));
   rep(i,0,h) rep(j,0,w){ cin >> a[i][j];}
   rep(i,0,h) rep(j,0,w){ cin >> b[i][j];}
   auto tate = [&](vvc a) -> vvc {
        vvc t(h, vc(w));
        rep(i,0,h){
            rep(j,0,w) t[i][j] = a[(i+1)%h][j];
        }
        return t;
   };
    
   auto yoko = [&](vvc a) -> vvc {
        vvc ta(w, vc(h));
        vvc t(w, vc(h));
        rep(i,0,h)rep(j,0,w){
            ta[j][i] = a[i][j];
        }
        rep(i,0,w){
            t[i] = ta[(i+1)%w];
        }
        vvc res(h, vc(w));
        rep(i,0,h)rep(j,0,w){
            res[i][j] = t[j][i];
        }
        // cerr << a[i] << endl;
        return res;
   };

   rep(i,0,h+1){
    rep(j,0,w){
        if(a==b){
            cout << "Yes" << endl;
            return 0;
        }
        a = yoko(a);
    }
    if(a==b){
        cout << "Yes" << endl;
        return 0;
    }
    a = tate(a);
    if(a==b){
        cout << "Yes" << endl;
        return 0;
    }
   }
   cout << "No" << endl;
  
    return 0;
}
