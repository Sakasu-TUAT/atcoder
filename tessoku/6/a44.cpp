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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,0,n){a[i] = i+1;}
    bool isReversed = false;
    while(q--){
        ll b; cin >> b;
        if(b==1){
            ll x, y; cin >> x >> y;
            if(isReversed){
                a[n-x] = y;
            } else {
                a[x-1] = y;
            }
        } else if(b==2){
            isReversed = !isReversed; 
        } else {
            ll x; cin >> x;
            if(isReversed) cout << a[n-x] << endl;
            else cout << a[x-1] << endl;
        }
    }
    return 0;
}

