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
  int n; cin >> n;
  string s, t; cin >> s >> t;
  if(s==t){
    cout << 0 << endl;
    return 0;
  }
  if(s == string(n, 'A') and t == string(n, 'B')){
    cout << -1 << endl;
    return 0;
  } else if(s == string(n, 'B') and t == string(n, 'A')){
    cout << -1 << endl;
    return 0;
  }
  vl aa(n+1), ab(n+1), ba(n+1), bb(n+1);
  rep(i,0,n){
      aa[i+1] += aa[i] + (s[i]=='A' and t[i]=='A');
      bb[i+1] += bb[i] + (s[i]=='B' and t[i]=='B');
      ab[i+1] += ab[i] + (s[i]=='A' and t[i]=='B');
      ba[i+1] += ba[i] + (s[i]=='B' and t[i]=='A');
  }
  // rep(i,0,n+1){
  //   cerr << aa[i] << " \n"[i==n];
  // }

  ll ans = 0;
  rep(i,0,n){
    if(s[i]=='A' and t[i]=='B'){
      if(aa[i]-aa[0] > 0) ans++;
      else if(ba[i]-ba[0] > 0) ans++;
      else {
        cout << -1 << endl;
        return 0;
      }
    } else if(s[i]=='B' and t[i]=='A'){
      if(bb[n]-bb[i] > 0) ans++;
      else if(ab[n]-ab[i] > 0) ans++;
      else {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  cout << ans/2 << endl;
  // ll aa=0, ab=0, ba=0, bb=0;
  // ll ans = 0;
  // rep(i,0,n){
  //     aa += aa + (s[i]=='A' and t[i]=='A');
  //     bb += bb + (s[i]=='B' and t[i]=='B');
  //     ab += ab + (s[i]=='A' and t[i]=='B');
  //     ba += ba + (s[i]=='B' and t[i]=='A');
  //     if(s[i]=='A' and t[i]=='B'){
  //       if(aa==0){
  //         cout << ""
  //       }
  //     }
  // }
  
 
  // cout << m << endl;


}
