#include <bits/stdc++.h>

#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)
#define rrep(i,a,b) for (ll i = (a); i >= ll(b); i--)
#define cauto const auto&
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vd = vector<double>;
using vld = vector<long double>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vs = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
using vb = vector<bool>;
using vvb = vector<vb>;

int gcd(int a,int b){return b?gcd(b,a%b):a;}
template <class T, class U>
bool chmin(T& a, const U& b) {return (b < a) ? (a = b, true) : false;}
template <class T, class U>
bool chmax(T& a, const U& b) {return (b > a) ? (a = b, true) : false;}
void in() {}
void printMatrix(const auto &vec){for(const auto &v : vec){ for(const auto &e : v){cerr << e << " ";}cerr << endl;}}
template<class T> void printTable(const vector<vector<T>> &tb){ for(const auto &i : tb){ for(const auto &j : i){cerr << j << " ";}cerr << endl;}}
template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
    cin >> head;
    in(std::forward<Tail>(tail)...);
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (int i = 0; i < v.size(); ++i)
        is >> v[i];
    return is;
}


const ll INF = 1LL << 60;


int main() {
  ll n; cin >> n;
  vl a(n+1), p(n+1);
  rep(i,1,n+1) cin >> a[i];
  rep(i,2,n+1) cin >> p[i];
  vvl G(n+1);
  rep(i,2,n+1) {
      G[p[i]].emplace_back(i);
  }
  ll dm = 0;
  vl s(n+1);

  auto dfs = [&](auto dfs, ll n, ll dist) -> void {
        for (ll next : G[n]) {
          dfs(dfs, next, dist + 1);
        }
        s[dist] += a[n];
        dm = max(dm, dist);
    };

  dfs(dfs, 1, 1);
  rrep(i,dm,0){
    // cerr << i << ", " << s[i] << "\n";
    if (s[i] > 0){
      cout << "+" << endl;
      return 0;
    } else if (s[i] < 0) {
      cout << "-" << endl;
      return 0;
    } 
  }
  cout << "0" << endl;
  return 0;
}
