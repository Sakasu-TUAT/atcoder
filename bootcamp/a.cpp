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
#include <functional>

#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)
#define rrep(i,a,b) for (ll i = (a); i >= ll(b); i--)
#define cauto const auto&
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

vector<bool> Eratostenes(int n){
    vector<bool> isprime(n+1, true);isprime[1] = false;
    rep(p,2,n+1){ if(!isprime[p]) continue; for(int q = p*2; q <= n; q+=p){ isprime[q] = false; }}
    return isprime;
}
ll gcd(ll a,ll b){if(a<b) swap(a, b); return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a*b/(gcd(a, b));}
template <class T, class U>
bool chmin(T& a, const U& b) {return (b < a) ? (a = b, true) : false;}
template <class T, class U>
bool chmax(T& a, const U& b) {return (b > a) ? (a = b, true) : false;}
void in() {}
void printVec(const auto &vec){for(const auto &v : vec){ cerr << v << " ";}cerr << endl;}
template<class T> void printTable(const vector<vector<T>> &tb){ for(const auto &i : tb){ for(const auto &j : i){cerr << j << " ";}cerr << endl;}}
template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
    cin >> head;
    in(std::forward<Tail>(tail)...);
}
const ll INF = 1LL << 60;
const ll mod = 1000000007;
// int dx[4] = {1, 0, 0, -1}; 
// int dy[4] = {0, 1, -1, 0}; 

ll power(ll a, ll b) {
    ll ans = 1;
    for(ll i=0; i<60; i++){
        if(b & (1LL<<i)) {
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
    }
    return ans;
}

ll combination(ll n, ll k){
    assert(!(n < k));
    assert(!(n < 0 || k < 0));
    ll s = 1, t = 1;
    rep(i,1,k+1){
        s = s*(n-i+1) % mod;
        t = t*i % mod; 
    }
    // フェルマーの小定理 a^(p-1) ≡ 1 (mod.p) (∵ gcd(a, p) = 1)
    // より、tの逆元は t^(p-2) ≡ t^(-1) (mod. p)
    return s * power(t, mod-2) % mod;
}

int dx[6] = {-1, -1, 0, 0, 1, 1};
int dy[6] = {-1, 0, -1, 1, 0, 1};

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

using Graph = vector<vector<ll>>;
int main(){
    string s, t; cin >> s >> t;
    int n = size(s);
    map<char, int> mp;
    rep(i,0,n){
        mp[s[i]]++;
    }
    rep(i,0,n){
        if(mp[t[i]]-1 < 0){
            mp['@']--;
        } else {
            mp[t[i]]--;
        }
    }
    
    
   

    return 0;
}