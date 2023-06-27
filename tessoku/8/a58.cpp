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

template<typename T>
class SegmentTree {
private:
  T n;
  vector<T> node;
public: 
  SegmentTree(const vector<ll> &v) : n(1) {
    T size = v.size();
    while(n<size) n *= 2;
    node.resize(2*n-1, -1);
    rep(i,0,size) node[i+n-1] = v[i]; //葉を構築
    rrep(i,n-2,0){
      node[i] = max(node[2*i+1], node[2*i+2]);
    }
  }

  void update(T pos, T x){
    pos += n-1;
    node[pos] = x;
    while(pos>0){
      pos = (pos-1)/2;
      node[pos] = max(node[2*pos+1], node[2*pos+2]);
    }
  }

  T getmax(T l, T r, T k=0, T a=0, T b=-1){
    if(b<0) b=n;
    if(r <= a or b <= l) return  -1; //完全に範囲外
    if(l <= a and b <= r) return node[k]; //完全に範囲内
    T mid = (a+b)/2;
    int vl = getmax(l, r, 2*k+1, a, mid);
    int vr = getmax(l, r, 2*k+2, mid, b);
    return max(vl, vr);
  }
};

int main(){
  int n, q; cin >> n >> q;
  vector<ll> vec(n, 0);
  SegmentTree<ll> st(vec);
  rep(i,0,q){
    int t; cin >> t;
    if(t==1) {
      int pos, x; cin >> pos >> x;
      pos--;
      st.update(pos, x);
    } else {
      int l, r; cin >> l >> r; l--; r--;
      cout << st.getmax(l, r) << endl;
    }
  }


  return 0;
}