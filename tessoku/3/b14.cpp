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
  int n, k; cin >> n >> k;
  vector<int> a(n);
  rep(i,0,n) cin >> a[i];
  int mid = n/2;
  vector<int> leftSum, rightSum;
  for(int i=0; i< (1<<mid); i++){
    int sum = 0; 
    rep(j,0,mid){
        if(i & (1<<j)){
            sum += a[j];
        }
    }
    leftSum.emplace_back(sum);
  }
for(int i=0; i< (1<<(n-mid)); i++){
    int sum = 0; 
    rep(j,0,n-mid){
        if(i & (1<<j)){
            sum += a[j+mid];
        }
    }
    rightSum.emplace_back(sum);
  }
  sort(all(rightSum));
  for(const auto &v : leftSum){
    auto itr = lower_bound(all(rightSum), k-v);
    if(itr!=rightSum.end() and *itr == k-v){
        cout << "Yes" << endl; return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}