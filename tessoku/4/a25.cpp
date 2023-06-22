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

const ll INF = 1e9;

int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i,0,h) cin >> s[i];

    // dp[i][j]:=(i,j)に行く方法の場合の数
    vector<vector<ll>> dp(h+1, vector<ll> (w+1)); 
    dp[1][1] = 1;
    rep(i,1,h+1){
        rep(j,1,w+1){
            if(s[i-1][j-1] == '#') continue;
            if(i==1 and j==1) continue;
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    for(const auto v : dp ){
        for(const auto e : v){
            cerr << e << " ";
        } cerr << endl;
    }
    cout << dp[h][w] << endl;


    return 0;
}

