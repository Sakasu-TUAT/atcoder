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
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
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
const ll mod = 1000000007;

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

int main(){
    ll n, h, w; cin >> n >> h >> w;
    vector<int> a(2*n);
    for(int i=0; i<2*n; i=i+2){ cin >> a[i] >> a[i+1];}
    rep(i,0,n+1){
        rep(j,0,k){
            if(i-a[j]>=0 and !dp[i-a[j]]) dp[i] = true;
        }
    }
    cout << (dp[n] ? "First" : "Second") << endl;

    return 0;
}