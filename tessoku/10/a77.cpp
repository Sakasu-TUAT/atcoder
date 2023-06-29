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
int n, l, k; 
vector<int> a;
bool check(int x){
  int cnt = 0, lastDeli = 0;
  rep(i,0,n){
    if(a[i] - lastDeli >= x and l-a[i] >= x){
      cnt++;
      lastDeli = a[i];
    }
  }
  return (cnt>=k) ? true : false;
}

int main(){
  cin >> n >> l;
  cin >> k;
  a.resize(n);
  rep(i,0,n) cin >> a[i];
  ll left = -1, right = 1000000000;
  while(abs(left-right)>1){
    ll mid = (left+right)/2;
    bool res = check(mid);
    if(res) left = mid;
    else right = mid;
  }

  cout << left << endl;

  return 0;
}