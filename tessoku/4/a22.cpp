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

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i,0,n-1) cin >> a[i];  
    rep(i,0,n-1) cin >> b[i];  
    vector<int> dp(n+1, -1e6); //-で初期化することに注意
    dp[1] = 0;
    rep(i,0,n){
        chmax(dp[a[i]], dp[i+1] + 100);
        chmax(dp[b[i]], dp[i+1] + 150);
    }
    cout << dp[n] << endl;  

    return 0;
}

