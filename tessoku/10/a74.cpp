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
  vector<int> x(n), y(n);

  rep(i,0,n){
    rep(j,0,n){
      int a; cin >> a;
      if(a!=0) {
        x[i] = a;
        y[j] = a;
      }
    }
  }
  auto tentou = [&](vector<int> v1, vector<int> v2){
    int cnt=0;
    rep(i,0,n-1){
      rep(j,i,n){
        if(v1[i] > v1[j]) cnt++;
        if(v2[i] > v2[j]) cnt++;
       }
    }
    return cnt;
  };
  cout << tentou(x, y) << endl;
  
 

}