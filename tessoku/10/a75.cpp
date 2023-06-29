#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits>
#include <cmath>
#include <iomanip>
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
using P = pair<ll, ll>;
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

template<typename T>
void printBit(T a){
  string s;
  while(a!=0){
    s += (a & 1) ? '1' : '0';
    a >>= 1;
  }
  reverse(s.begin(), s.end());
  cerr << a << " is " << s << endl;
}

int main(){
  int n; cin >> n;
  vector<P> v;
  rep(i,0,n){
    int t, d; cin >> t >> d;
    v.emplace_back(d, t);
  }
  sort(v.begin(), v.end());
  vector<vector<int>> dp(n+1, vector<int>(1440+9));
  dp[0][0] = 0;
  rep(i,0,n){
    auto [d, t] = v[i];
    for(int j=0; j<=1440; j++){
      chmax(dp[i+1][j], dp[i][j]);
      if(j+t <= d) chmax(dp[i+1][j+t], dp[i][j] + 1);
    }
  }
  ll ans = 0;
  rep(i,0,1441){
    chmax(ans, dp[n][i]);
  }

  cout << ans <<  endl;
}