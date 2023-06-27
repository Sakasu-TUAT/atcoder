#include <bits/stdc++.h>
using namespace std;
// 型・メソッド・イテレータ系
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i <= (n); ++i)
#define drep(i, n) for(int i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (int i = s; i < (t); ++i)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define bg begin
#define ed end
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define snuke_san srand((unsigned)clock()+(unsigned)time(NULL));
#define newline puts("")
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
template<typename T> using PQ = priority_queue<T, vc<T>, greater<T>>;
using uint = unsigned; using ll = long long; using ull = unsigned long long; using ld = long double;
using P = pair<int, int>; using lp = pair<ll, ll>; using lt = tuple<ll, ll, ll>;
using vi = vc<int>; using vvi = vv<int>; using vvvi = vv<vi>;
using vl = vc<ll>; using vvl = vv<ll>; using vvvl = vv<vl>;
using vch = vc<char>; using vvch = vv<char>; using vs = vc<string>; using vvs = vc<vs>;
// 入出力系
template<typename Tx, typename Ty>istream& operator>>(istream&i, pair<Tx, Ty>&v){return i>>v.fi>>v.se;}
template<typename Tx, typename Ty>ostream& operator<<(ostream&o, const pair<Tx, Ty>&v){return o<<v.fi<<", "<<v.se;}
template<typename T>istream& operator>>(istream&i, vc<T>&v){rep(j, sz(v))i>>v[j];return i;}
template<typename T>string join(const T&v, const string& d=""){stringstream s;rep(i, sz(v))(i?s<<d:s)<<v[i];return s.str();}
template<typename T>ostream& operator<<(ostream&o, const vc<T>&v){if(sz(v))o<<join(v, " ");return o;}
#define iint(...) int __VA_ARGS__; in(__VA_ARGS__)
#define ill(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define ich(...) char __VA_ARGS__; in(__VA_ARGS__)
#define istr(...) string __VA_ARGS__; in(__VA_ARGS__)
#define ild(...) ld __VA_ARGS__; in(__VA_ARGS__)
#define ivc(type, name, size) vector<type> name(size); in(name)
#define ivc2(type, name1, name2, size) vector<type> name1(size), name2(size); for(int i = 0; i < size; i++) in(name1[i], name2[i])
#define ivc3(type, name1, name2, name3, size) vector<type> name1(size), name2(size), name3(size); for(int i = 0; i < size; i++) in(name1[i], name2[i], name3[i])
#define ivc4(type, name1, name2, name3, name4, size) vector<type> name1(size), name2(size), name3(size), name4(size); for(int i = 0; i < size; i++) in(name1[i], name2[i], name3[i], name4[i]);
#define ivv(type, name, h, w) vector<vector<type>> name(h, vector<type>(w)); in(name)
void scan(int &a) { cin >> a; } void scan(long long &a) { cin >> a; } void scan(char &a) { cin >> a; } void scan(double &a) { cin >> a; } void scan(string &a) { cin >> a; }
template <typename T> void scan(T &a) { cin >> a; }
template <typename T, typename S> void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <typename T> void scan(vector<T> &a) { for(auto &i : a) scan(i); }
void in() {} template <typename Head, typename... Tail> void in(Head &head, Tail &...tail) { scan(head); in(tail...); }
#define ortn(...) { out(__VA_ARGS__); return 0; }
#define dame { puts("-1"); return 0; }
#define yes { puts("Yes"); return 0; }
#define no { puts("No"); return 0; }
#define yn(ok) { puts(ok ? "Yes" : "No"); }
void out() { cout << '\n'; } template <typename Head, typename... Tail> void out(const Head &head, const Tail &...tail) { cout << head; if(sizeof...(tail)) cout << ' '; out(tail...); }
// 数値系
template<typename T> int lbs(vector<T> &a, const T &b) { return lower_bound(all(a), b) - a.begin(); };
template<typename T> int ubs(vector<T> &a, const T &b) { return upper_bound(all(a), b) - a.begin(); };
template<typename Tx, typename Ty> Tx ceil(Tx x, Ty y) {assert(y);return (y<0 ? ceil(-x,-y) : (x>0 ? (x+y-1)/y : x/y));}
template<typename Tx, typename Ty> Tx floor(Tx x, Ty y) {assert(y);return (y<0 ? floor(-x,-y) : (x>0 ? x/y : (x-y+1)/y));}
template<typename T> ll sumof(const vc<T>&a){ll res(0);for(auto&&x:a)res+=x;return res;}
template<typename T> ll sumof(const vv<T>&a){ll res(0);for(auto&&x:a)res+=sumof(x);return res;}
template<typename T> vc<T> csum(vc<T> &a) { vc<T> res(a.size() + 1, 0); rep(i, a.size()) res[i + 1] = res[i] + a[i]; return res; }
template<typename T> void prepend(vc<T>&a, const T&x){a.insert(a.bg(), x);}
// 操作系
template<typename Tx, typename Ty> void operator--(pair<Tx, Ty>&a, int){a.fi--;a.se--;}
template<typename Tx, typename Ty> void operator++(pair<Tx, Ty>&a, int){a.fi++;a.se++;}
template<typename T> void operator--(vc<T>&a, int){for(T&x:a)x--;}
template<typename T> void operator++(vc<T>&a, int){for(T&x:a)x++;}
template<typename T> void operator+=(vc<T>&a, T b){for(T&x:a)x+=b;}
template<typename T> void operator-=(vc<T>&a, T b){for(T&x:a)x-=b;}
template<typename T> void operator*=(vc<T>&a, T b){for(T&x:a)x*=b;}
template<typename T> void operator/=(vc<T>&a, T b){for(T&x:a)x/=b;}
template<typename T> void operator+=(vc<T>&a, const vc<T>&b){a.insert(a.ed(), all(b));}
template<typename Tx, typename Ty> bool chmin(Tx& x, const Ty&y){if(y<x){x=y;return true;}else return false;}
template<typename Tx, typename Ty> bool chmax(Tx& x, const Ty&y){if(x<y){x=y;return true;}else return false;}
template<typename T> void uni(T&a){sort(all(a));a.erase(unique(all(a)), a.ed());}
template<typename T> void cc(vc<T>&a){vc<T> b=a;uni(b);rep(i, a.size())a[i]=lbs(b, a[i]);}
template<typename T = ll> pair<unordered_map<ll, ll>, unordered_map<ll, ll>> ccmp(vector<T> &a) { vector<T> ca = a; cc(ca); unordered_map<ll, ll> res, rev; rep(i, ca.size()) { res[a[i]] = ca[i]; rev[ca[i]] = a[i]; } return make_pair(res, rev); }
template<typename T> vc<pair<T, int>> RLE(const vc<T> &v) { vc<pair<T, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }
template<typename T> void rotate(vv<T> &a) { ll n = a.size(), m = a[0].size(); vv<T> res(m, vc<T>(n, 0)); rep(i, n) rep(j, m) res[j][n - 1 - i] = a[i][j]; a = res; }
vi pm(int n, int s=0) {vi a(n); iota(all(a), s); return a;}
// よく使う値
const int INF = 1001001001;
const ll INFL = 1001002003004005006ll;
const ld EPS = 1e-10;
const int dx[8] = {0, -1, 1, 0, 1, 1, -1, -1};
const int dy[8] = {-1, 0, 0, 1, 1, -1, 1, -1};
 
int main() {
 
    iint(n, m);
    ivc(int, a, n);
    ivc3(int, x, y, z, m);
    x--, y--, z--;
 
    vi dp(1 << n, INF);
    int flg = 0;
    rep(i, n) flg |= a[i] << i;
    dp[flg] = 0;
    for (int i = 0; i < m; i++) {
        int bit = (1 << x[i]) | (1 << y[i]) | (1 << z[i]);
        for (int st = 0; st < (1 << n); st++) {
            chmin(dp[st ^ bit], dp[st] + 1);
        }
    }
    out(dp[(1 << n) - 1] < INF ? dp[(1 << n) - 1] : -1);
    return 0;
}