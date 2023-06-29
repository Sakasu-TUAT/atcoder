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
  int n, w, l, r; 
  cin >> n >> w >> l >> r;
  int lpos, rpos;
  vector<int> x(n+2);
  x[0] = 0;
  x[n+1] = w;
  rep(i,0,n) cin >> x[i+1];
  vector<int> dp(n+2), s(n+2);
  dp[0] = 1;
  s[0] = 1;
  rep(i,1,n+2){
      lpos = lower_bound(x.begin(), x.end(), x[i]-r)-x.begin();
      rpos = lower_bound(x.begin(), x.end(), x[i]-l+1)-x.begin();
      rpos--;
      if(rpos==-1) dp[i]=0;
      else dp[i] = s[rpos];
      if(lpos >= 1)dp[i] -= s[lpos-1];
      dp[i] = (dp[i]+mod)%mod;
      s[i] = s[i-1]+dp[i];
      s[i] %= mod;
  }
  cout << dp[n+1] << endl;

  return 0;
}