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
using namespace std;
using ll = long long;
#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)
//someone_s

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

int main(){
    int n;
    cin >> n;
    vector<ll> a(n-1), b(n-2);
    rep(i,0,n-1) cin >> a[i];
    rep(i,0,n-2) cin >> b[i];

    vector<ll> dp(n, 1e7);
    dp[0] = 0;
    rep(i,1,n){
        chmin(dp[i], dp[i-1]+a[i-1]);
        if(i-2>=0) chmin(dp[i], dp[i-2]+b[i-2]);
    }
    cout << dp[n-1] << endl;

}