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
#include <cinttypes>
#include <algorithm>
#include <cstdlib>
#include <atcoder/all>

#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)
#define rrep(i,a,b) for (ll i = (a); i >= ll(b); i--)
#define cauto const auto&
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<ll, ll>;
using vll = vector<ll>;
using vi = vector<int>;
using vd = vector<double>;
using vld = vector<long double>;
using vll2 = vector<vll>;
using vll3 = vector<vll2>;
using vld2 = vector<vld>;
using vld3 = vector<vld2>;
using vs = vector<string>;
using vc = vector<char>;
using vvc = vector<char>;
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
const ll INF = 1LL << 60;
const ll mod = 1000000007;
// const ll mod = 998244353;
using Graph = vector<vector<ll>>;
using namespace atcoder;
using mint = modint998244353;

/* encode: ランレングス圧縮を行う
*/
vector<pair<char, ll>> encode(const string& str) {
    ll n = (ll)str.size();
    vector<pair<char, ll>> ret;
    for (ll l = 0; l < n;) {
        ll r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {};
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}
/* decode: ランレングス圧縮の復元を行う
*/
string decode(const vector<pair<char, ll>>& code) {
    string ret = "";
    for (auto p : code) {
        for (ll i = 0; i < p.second; i++) {
            ret.push_back(p.first);
        }
    }
    return ret;
}



// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

// 1 以上 N 以下の整数が素数かどうかを返す
vector<ll> Eratosthenes(ll N) {
    vector<ll> prime;
    vector<bool> isprime(N, true);

    // ふるい
    for (ll p = 2; p <= N; ++p) {
        // すでに合成数であるものはスキップする
        if (!isprime[p]) continue;
        prime.emplace_back(p);
        // p 以外の p の倍数から素数ラベルを剥奪
        for (ll q = p * 2; q <= N; q += p) {
            isprime[q] = false;
        }
    }
    return prime;
}

// using mint = atcoder::modint998244353;

const int MAX = 510000;
mint fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    const int MOD = mint::mod();
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i;
        inv[i] = MOD - inv[MOD%i] * (MOD / i);
        finv[i] = finv[i - 1] * inv[i];
    }
}
// 二項係数計算
mint COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * finv[k] * finv[n - k];
}

ll dx[4] = {-1, 0, 0, 1};
ll dy[4] = {0, 1, -1, 0};

int main(){
    ll h, w; cin >> h >> w;
    ll q; cin >> q;
    dsu d(h*w+10);
    vector<vector<bool>> red(h, vb(w));
    rep(i,0,q){
        int x; cin >> x;
        if(x==1){
            int r, c; cin >> r >> c;
            --r, --c;
            red[r][c] = true;
            rep(j,0,4){
                int ny = r + dy[j];
                int nx = c + dx[j];
                if(ny<0 or ny>=h or nx<0 or nx>=w or !red[ny][nx]) continue;
                if(red[ny][nx]){
                    // cerr << r << ", " << c << " -> " << r*w+c << endl;
                    d.merge(r*w+c, ny*w+nx);
                }
            }
        } else {
            int ra, ca, rb, cb; 
            in(ra, ca, rb, cb);
            ra--, ca--, rb--, cb--;
            if(d.same(ra*w+ca, rb*w+cb) and red[ra][ca] and red[rb][cb]){
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    // printMatrix(red);
}

