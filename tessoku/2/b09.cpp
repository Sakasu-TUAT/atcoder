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
void printMatrix(const auto &vec){for(const auto &v : vec){ for(const auto &e : v){cerr << e << " ";}cerr << endl;}}
template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
    cin >> head;
    in(std::forward<Tail>(tail)...);
}
const ll INF = 1e9;
const ll mod = 1000000007;


int main(){
  int n; cin >> n;
  int xMax = 1509, yMax = 1509;
  vector<vector<int>> sum((yMax+1), vector<int>((xMax+1)));

  rep(i,0,n){
    int a,b,c,d; 
    cin>>a>>b>>c>>d;
    sum[b][a]++;
    sum[d][a]--;
    sum[b][c]--;
    sum[d][c]++;
  }
  rep(i,0,yMax){ rep(j,0,xMax){
      sum[i][j+1] += sum[i][j];
  }}
  rep(j,0,xMax){ rep(i,0,yMax){ 
      sum[i+1][j] += sum[i][j];
  }}
  // printMatrix(sum);

  int ans = 0;
  rep(i,1,yMax+1){ rep(j,1,xMax+1){
      if(sum[i][j] > 0) ans++;
  }}
  cout << ans << endl;


  return 0;
}