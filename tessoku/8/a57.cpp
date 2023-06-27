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

int main(){
  int n, q; cin >> n >> q;
  vector<vector<int>> dp(30+1, vector<int>(n+1));
  // dp[j][i] := 穴iにいて2^j日後の穴の位置
  rep(i,1,n+1) { 
    int a; cin >> a;
    dp[0][i] =  a; 
  }
  rep(d,1,30){
    rep(j,1,n+1){
        dp[d][j] = dp[d-1][dp[d-1][j]];
    }
  }

  rep(i,0,q){
    int x, y; 
    cin >> x >> y;
    int pos = x;
    rrep(d, 30, 0){
      if(y & (1<<d))  {
        pos = dp[d][pos];
      }
    }
    cout << pos << endl;
  }




  return 0;
}