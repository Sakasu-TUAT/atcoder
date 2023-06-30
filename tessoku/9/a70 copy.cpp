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
  int n, m;
  cin >> n >> m;
  int start = 0; 
  vector<vector<int>> graph(2000);
  rep(i,0,n){
    int a; cin >> a; 
    start = 2*start + a;
  }
  //2^n通りのすべてのビット列に対してON/OFFのパターンを適用した場合を前計算
  rep(i,0,m){
    int x, y, z; cin >> x >> y >> z;
    // printBit(((1<<(n-x))) + ((1<<(n-y))) + ((1<<(n-z))));
    rep(j,0,(1<<n)){
      int to = j;
      //自身とのxorでビット反転
      to ^= ((1<<(n-x))) + ((1<<(n-y))) + ((1<<(n-z)));
      graph[j].emplace_back(to);
    }
  }

  queue<int> que;
  que.push(start);
  vector<int> dist(2000, -1);
  dist[start] = 0;
  while(!que.empty()){
    int now = que.front();
    que.pop();
    for(const auto next : graph[now]){
      if(dist[next]==-1) {
        dist[next] = dist[now] + 1;
        que.push(next);
      }
    }
  }

  cout << dist[(1<<n)-1] << endl;
  return 0;
}