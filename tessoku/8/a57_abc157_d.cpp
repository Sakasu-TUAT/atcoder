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
#include <set>
#include <deque>
#include <stack>
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

// https://atcoder.jp/contests/abc167/tasks/abc167_d7

int main(){
  ll n, k; cin >> n >> k;
  vector<vector<ll>> dp(60+1, vector<ll>(n+1));
  rep(i,1,n+1){
    ll a; 
    cin >> a;
    dp[0][i] = a;
  }
  rep(i,1,61){
    rep(j,1,n+1){
      dp[i][j] = dp[i-1][dp[i-1][j]];
    }
  }
  ll pos = 1;
  rrep(i, 60, 0){
    if(k & (1LL<<i)) {
      pos = dp[i][pos];
    }
  }
  cout << pos << endl;
  
  return 0;
}