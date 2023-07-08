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

#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)
#define rrep(i,a,b) for (ll i = (a); i >= ll(b); i--)
#define cauto const auto&
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int gcd(int a,int b){return b?gcd(b,a%b):a;}
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
  int n; in(n);
  vector<int> sum(n+1);
  rep(i,0,n){
    int a; cin >> a;
    sum[i+1] = a + sum[i];
  }
  int q; in(q);
  rep(i,0,q){
    int l, r; in(l,r);
    int atariNum = sum[r] - sum[l-1];
    int hazureNum = r-l + 1 - atariNum;
    cerr << "atariNum: " << atariNum << endl;
    if(atariNum > hazureNum) cout << "win" << endl;
    else if (atariNum == hazureNum) cout << "draw" << endl;
    else cout << "lose" << endl;
  }
  


  return 0;
}