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
#include <ranges>
#include <numeric>
#include <atcoder/all>

#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)

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
const ll INF = 1LL << 60;
const ll mod = 998244353;
using namespace atcoder;
using mint = modint998244353;
struct Edge {ll to; ll cost;};
using Graph = vector<vector<Edge>>;
const ll dx[4] = {0, 1, 0, -1};
const ll dy[4] = {1, 0, -1, 0};


int RandInt(int L,int R){
    return rand()%(R-L+1)+L;
}
int n, m;
vector<vector<ll>>b;
vb taken;
ll score;

priority_queue<P, vector<P>, greater<P> > que;
map<int, P> mp;

void input(){
    cin>>n>>m;
    b.resize(m);
    rep(i,m) b[i].resize(n/m);
    rep(i,m){
        rep(j,n/m){
            cin>>b[i][j];
            // cerr << b[i][j] << " \n"[j==n/m-1];
        }
    }
}

void calc_move(vl &from, vl &to, ll v){
    int idx = 0;
    rep(k,0,size(from)) if(from[k] == v) idx = k;
    vl m = vl(from.begin() + idx, from.end());
    to.insert(to.end(), all(m)); 
    score += (from.size() - idx);
    from.erase(from.begin() + idx, from.end());
};

vector<P> operations;
void calc_greedy(){
    score = 0;
    taken.resize(n+1);
    ll lastRemoved = 0;
    rep(v, 1, n+1) {
        if(taken[v]) continue;
        bool found = false;
        rep(i,0,m){ //各山について調べる
            auto h = b[i].size();
            //山の一番上に箱vがある→取り出せる
            if(h>0 and b[i][h-1] == v) { 
                found = true;
                taken[v] = true;
                b[i].pop_back();
                operations.emplace_back(v, 0);
                break; //この箱については終わり
            }
        }
        if(found) continue;

        priority_queue<P, vector<P>, greater<P> > que;
        rep(i,m){ que.push(P{size(b[i]), i});}


        auto [h, toi] = que.top(); //最も低い山の高さとidx
        cerr << "h: " << h << ", to: " << toi << endl; 
        ll nowi = 0, nowh = 0;
        rep(i,0,m){
            rep(j,0,size(b[i])){
                if(v == b[i][j]) {
                    nowi=i, nowh=j;
                    break;
                }
            }
        }
        // cerr << v << ": " << nowi << ", " << nowh << endl;
        int u = b[nowi][nowh+1];
        ll pileNum = size(b[nowi]) - nowh + 1;
        // score += pileNum;
        ll nowTop = size(b[nowi]);
        // cerr << nowh+1  << ", " << nowTop << endl;
        calc_move(b[nowi], b[toi], u);
        operations.emplace_back(u, toi+1); // u以上の箱を全てiの上にうつす
        operations.emplace_back(v, 0);
        // b[nowi].pop_back();
        taken[v] = true;
    }
}

vector<int> solve(){
    // int TIMELIMIT=1.9*CLOCKS_PER_SEC;
    // int ti=clock();
    // vector<P>out(D);
    // rep(i,D)out[i]=RandInt(0,25);
   
    // return out;
}
void output(vector<P>out){
    for(cauto [v,i] : out) cout << v << " " << i << endl;
}

int main() {
    input();
    calc_greedy();
    // vi res = solve();
    output(operations);
    // cerr << "score: " << calc_score(res) << endl;

}
