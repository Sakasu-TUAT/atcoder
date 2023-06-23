#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
#include <set>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <bitset>
#include <cassert>
using namespace std;
using ll = long long;
#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)

template <class T, class U>
bool chmin(T& a, const U& b) {return (b < a) ? (a = b, true) : false;}
template <class T, class U>
bool chmax(T& a, const U& b) {return (b > a) ? (a = b, true) : false;}
void in() {}

template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
    cin >> head;
    in(std::forward<Tail>(tail)...);
}


const ll INF = 1e9;
const ll mod = 1000000007;

ll power(ll x, ll n){
    ll ret = 1;
    // 指数を1ビットずつ右にシフト
    for(auto i = n; i > 0; i >>= 1){
        if((i & 1)) { //LSBに1が立っていれば x^(2^i)　をかける
            ret = ret*x%mod;
        }
        x = (x*x)%mod;
    }
    return ret;
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
    ll n, r; cin >> n >> r;
    cout << combination(n, r) << endl;
    return 0;
}

