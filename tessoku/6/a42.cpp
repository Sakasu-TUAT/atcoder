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
#define rrep(i,a,b) for (ll i = (a); i >= ll(b); i--)

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

int main(){
    int n, k; cin >> n >> k;
    vector<ll> a(n), b(n);
    rep(i,0,n){
        cin >> a[i] >> b[i];
    }
    ll ans = 0;
    for(ll x : a){
        for(ll y : b){
            ll cnt = 0;
            rep(i,0,n){
                if(x <= a[i] and a[i] <= x+k and y<=b[i] and b[i]<= y+k) cnt++;
            }
            chmax(ans, cnt);
        }
    }
    cout << ans << endl;

    return 0;
}

