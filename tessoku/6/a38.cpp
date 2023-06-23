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
    ll d, n; cin >> d >> n;
    vector<int> l(n), r(n), h(n);
    vector<int> day(d, 24);
    rep(i,0,n){
        cin >> l[i] >> r[i] >> h[i];
        rep(j, l[i]-1, r[i]){
            chmin(day[j], h[i]);
        }
    }
    ll ans = 0;
    rep(i,0,d){
        ans += day[i];
        cerr << day[i]  << " ";
    }cerr << endl;

    cout << ans << endl;

    return 0;
}

