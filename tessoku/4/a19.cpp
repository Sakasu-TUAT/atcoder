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
    ll N, W;
    cin >> N >> W;
    vector<ll> w(N), v(N);
    rep(i,0,N){
        cin >> w[i] >> v[i];
    }
    //dp[i][j]:=i番目までの品物から重さの総和がj以下となるように選択したときの価値の総和の最大値
    vector<vector<ll>> dp(N+1, vector<ll>(W+1));

    rep(i,1,N+1){
        rep(j,0,W+1){
            if(j>=w[i-1]){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]] + v[i-1]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    while(!dp[N][W]){
        W--;
    }
    cout << dp[N][W] << endl;
    // for(const auto v : dp){
    //     for(const auto e : v){
    //         cerr << e << " ";
    //     }cerr << endl;
    // }

}


// int main() {
//     cin.tie(nullptr);
//     ios::sync_with_stdio(false);
//     int n, w;
//     in(n, w);
//     vector<i64> dp(w + 1, -1e18);
//     dp[0] = 0;
//     rep(i, n) {
//         int a, b;
//         in(a, b);
//         for (int j = w; j >= 0; j--) {
//             if (j - a >= 0) chmax(dp[j], dp[j - a] + b);
//         }
//     }
//     print(*max_element(all(dp)));
// }