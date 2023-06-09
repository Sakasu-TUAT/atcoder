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
  int h,w,K; cin>>h>>w>>K;
  vector<string> tb(h*w+1);
  int originSum = 0;
  rep(i,0,h){
    cin >> tb[i];
    rep(j,0,w){
      if(tb[i][j] == '#') originSum++;
    }
  }
  int ans = 0;
  //行の選択をビット全探索
  rep(i,0,1<<h){
    set<int> st;
    int rowSum = 0;
    rep(j,0,h){
      if(i & (1<<j)) {
        st.insert(j); //塗った行を取得
        rep(k,0,w){
          if(tb[j][k] == '.') rowSum++;
        }
      }
    }
    if(st.size() > K) continue;
    vector<int> col(w);
    rep(j,0,w){
      rep(k,0,h){
        if(st.count(k)) continue; //既に塗られている場合は無視
        if(tb[k][j] == '.') col[j]++;
      }
    }
    sort(col.rbegin(), col.rend());
    int colSum = 0;
    rep(j,0,K-st.size()){
      colSum += col[j];
    } 
    cerr << rowSum << " + " << colSum << endl;
    chmax(ans, rowSum+colSum);
  }
  cout << originSum + ans << endl;
  return 0;
}