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
  int n, m; cin >> n >> m;
  vector<vector<P>> graph(n);
  priority_queue<P, vector<P>, greater<P>> pq;
  rep(i,0,m){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--; b--;
    if(d==1){
      graph[a].emplace_back(b, 10000*c - 1);
      graph[b].emplace_back(a, 10000*c - 1);
    } else {
      graph[a].emplace_back(b, c*10000);
      graph[b].emplace_back(a, c*10000);
    }
  }
  vector<ll> dist(n, INF);
  dist[0] = 0;
  pq.push({0LL,0});
  vector<bool> used(n);
  while(!pq.empty()){
    auto [nowDist, nowPos] = pq.top();  pq.pop();
    if(used[nowPos]) continue;
    used[nowPos] = true;
    for(const auto &[nextPos, nextDist] : graph[nowPos]){
     if(dist[nextPos] > dist[nowPos] + nextDist){
      dist[nextPos] = dist[nowPos]+nextDist;
      pq.push({dist[nextPos], nextPos});
     }
    }
  }
  ll disance = (dist[n-1] + 9999) / 10000;
  ll numTree = disance * 10000 - dist[n-1];
  cout << disance << " " << numTree << endl;

}