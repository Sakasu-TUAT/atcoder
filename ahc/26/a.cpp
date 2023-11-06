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

void input(){
    cin>>n>>m;
    b.resize(m);
    rep(i,m) b[i].resize(n/m);
    rep(i,m)rep(j,n/m)cin>>b[i][j];
}

//{箱のid, 高さ}
P findMountIdx(ll v){
    rep(i,m)rep(j,n/m){
        if(b[i][j]==v) return {i, j};
    }
}
ll calc_score(vector<P>out){
    ll score=0;
    for(auto [v, i] : out){
        if(i==0) continue;
        auto [idx, h] = findMountIdx(v);
        vl m = vl(b[idx].begin()+h, b[idx].end());
        b[i].insert(b[i].end(), all(m)); 
        score += (b[i].size() - h + 1);
        b[idx].erase(b[idx].begin() + h, b[idx].end());
    }
    return score;
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
            if(h>0 and b[i][h-1] == v and v==lastRemoved+1) { 
            // if(h>0 and b[i][h-1] == v ) { 
                found = true;
                taken[v] = true;
                lastRemoved = v;
                b[i].pop_back();
                operations.emplace_back(v, 0);
                break; //この箱については終わり
            }
        }
        if(found) continue;
        //一番上にない場合->移動させる箱を貪欲に決める
        int best_v = -1; //移動させる箱
        int best_i = -1; //移動させる箱の山のid
        int best_k = n+1;//移動させる箱以上の数
        rep(i,0,m){
            ll h = size(b[i]); //移動前の山の高さ
            rep(j,0,h){
                int u = b[i][j];
                if(taken[u]) continue;
                int k = h - j; //移動前の箱以上に積まれている数    
                if(u<best_v){
                    best_v = u; // より優先して動かすべき小さい箱
                    best_i = i; // 移動させる箱の属する山の番号を更新します。
                    best_k = k; // 移動させる箱の上に積まれている箱の数を更新します。
                }
            }
        }
        if(best_v!=-1){ //移動させる箱が見つかっている場合
            int best_j = -1; //移動先の山のid
            int best_w = n+1; //移動先の山の一番上の箱の番号
        
            rep(j,0,m){ //全ての山を順に調べる
                if(j==best_i) continue;
                ll toH = size(b[j]); //移動先の山の高さ
                if(toH == 0 or b[j][toH-1] > best_v) {//移動先の山が空 or 
                    if(b[j][toH-1] < best_w){
                        best_j = j;
                        best_w = (toH == 0 ? n+1 : b[j][toH-1]);
                    }
                }
            }
           
            if(best_j != -1) {
                calc_move(b[best_i], b[best_j], best_v);
                operations.emplace_back(best_v, best_j+1);
                continue;                    
            }
        }

        //操作1で動かせるものが無かった場合->ランダムで一つだけ箱を動かす
        int i = 0;
        int j = 0;
        while(i!=v and (i==j or size(b[i]) == 0)){
            i = RandInt(0, m-1);
            j = RandInt(0, m-1);
        }
        int u = b[i][size(b[i])-1];
        // if(u!=lastRemoved+1) continue;
        calc_move(b[i], b[j], u);        
        operations.emplace_back(u, j+1);
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
