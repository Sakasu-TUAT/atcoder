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

using nCk = tuple<vector<ll>, vector<ll>>;
nCk init_nCk(ll n){
    vector<ll> fact(n+1), fact_inv(n+1), inv(n+1);
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for(ll i = 2; i < n+1; i++){
        fact[i] = fact[i-1] * i % mod;
        inv[i] = mod - (mod/i)%mod * inv[mod%i] % mod;
        fact_inv[i] = fact_inv[i-1] * inv[i] % mod;
    }
    return {fact, fact_inv};
}

ll combination(ll n, ll k){
    assert(!(n < k));
    assert(!(n < 0 || k < 0));
    const auto &[f, f_inv] = init_nCk(n);
    return f[n]*(f_inv[n-k]*f_inv[k] % mod) % mod;
}



int main(){
    ll n, r; cin >> n >> r;
    cout << combination(n, r) << endl;
    return 0;
}

