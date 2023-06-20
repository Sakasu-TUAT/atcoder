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
    int n, s;
    cin >> n >> s; 
    vector<ll> a(n);
    rep(i,0,n) cin >> a[i];
    // i番目にまでの整数の合計がj
    vector<vector<bool>> dp(n+1, vector<bool>(s+1, 0));
    dp[0][0] = true;
    rep(i,1,n+1){
        rep(j,0,s+1){
            if(j<a[i-1]){ //状態を継続
                dp[i][j] = dp[i-1][j];
            } else { //状態を継続or追加を考慮
                dp[i][j] = dp[i-1][j] | dp[i-1][j-a[i-1]];
            }
        }
    }
    cout << (dp[n][s] ? "Yes" : "No") << endl;
    for(const auto v : dp){
        for(const auto e:  v){
            cerr << e << " ";
        } cerr << endl;
    }
}

