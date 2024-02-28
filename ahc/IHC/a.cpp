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
int D;
vl c;
vvl s;

void input(){
    cin >> D;
    c.resize(26);
    rep(i,26) cin>>c[i];
    s.resize(D);
    rep(i,D) s[i].resize(26);
    rep(i,D)rep(j,26) cin>>s[i][j];
}

ll calc_score(vi out){
    vi last(26,-1);
    ll score=0;
    rep(i,D) {
        last[out[i]]=i;
        rep(j,26) score-=c[j]*(i-last[j]);
        score+=s[i][out[i]];
        // cout << score << endl;
    }
    return score;
}

ll evaluate(vi out,int k){
    vi last(26,0);
    ll evaluated_score=0;
    rep(i,D){
        last[out[i]]=i;
        rep(j,26)evaluated_score-=c[j]*(i-last[j]);
        evaluated_score+=s[i][out[i]];
    }
    for(ll i=D;i<min((int)D+k,D);i++){
        rep(j,26)evaluated_score-=c[j]*(i-last[j]);
    }
    return evaluated_score;
}

vi solve(){
    int TIMELIMIT=1.9*CLOCKS_PER_SEC;
    int ti=clock();
    vi out(D);
    // rep(i,D) out[i]=RandInt(0,25);
    rep(i,0,D){
        cin >> out[i];
        out[i]--;
    }
    int best_score=calc_score(out);

//コンテストを最後に行った日を管理
    vector<set<int>> day(26, set<int>());
    rep(i,0,D) {
        day[out[i]].insert(i); 
    }
    rep(i,0,26){
        day[i].insert(-1); 
        day[i].insert(D);
    }
    int m; cin >> m;
    vl nd(m), nq(m);
    rep(i,0,m) {
        cin >> nd[i] >> nq[i];
        nd[i]--; nq[i]--;
    }
    rep(i,0,m){
        int ord_score = best_score;
        int pre_q = out[nd[i]];
        // cerr << nd[i] << ", " << out[nd[i]] << endl;
        out[nd[i]] = nq[i];
        // cerr << pre_q << " -> " << nq[i] << endl;

        auto o1 = day[pre_q].lower_bound(nd[i]); //過去のコンテストpre_qがnd[i]より真に前に開催される日付
        o1--;
        auto o2 = day[pre_q].upper_bound(nd[i]); //過去のコンテストpre_qがnd[i]より真に後に開催される日付
        // cerr  << "o1: "  << *o1 << ", o2: " << *o2 << endl;
        ord_score -= (*o2 - nd[i]) * (nd[i] - *o1) * c[pre_q];

        auto q1 = day[nq[i]].lower_bound(nd[i]); //過去のコンテストpre_qがnd[i]より真に前に開催される日付
        q1--;
        auto q2 = day[nq[i]].upper_bound(nd[i]); //過去のコンテストpre_qがnd[i]より真に後に開催される日付
        // cerr  << "q1: "  << *q1 << ", q2: " << *q2 << endl;
        ord_score += (*q2 - nd[i]) * (nd[i] - *q1) * c[nq[i]];
        int new_score = ord_score + s[nd[i]][nq[i]] - s[nd[i]][pre_q];
        cout << new_score << endl;
        day[pre_q].erase(nd[i]);
        day[nq[i]].insert(nd[i]);
        best_score = new_score;
    }
    // while(clock()-ti<TIMELIMIT){
    //     int type = RandInt(0, 1);
    //     int shurui=RandInt(0,1);
    //     if(shurui==0){
    //         int d=RandInt(0,D-1);
    //         int q=RandInt(0,25); 
    //         int old=out[d];//前の解
    //         out[d]=q;
    //         int tmp_score=calc_score(out);
    //         if(tmp_score>best_score){
    //             best_score=tmp_score;
    //         }else{
    //             out[d]=old;
    //         }
    //     }else{
    //         int d1=RandInt(0,D-2);
    //         int d2=RandInt(d1+1,min(d1+16,D-1));
    //         swap(out[d1],out[d2]);
    //         int tmp_score=calc_score(out);
    //         if(tmp_score>best_score){
    //             best_score=tmp_score;
    //         }else{
    //             swap(out[d1],out[d2]);
    //         }
    //     }
    // }
    return out;
}
void output(vi out){
    rep(i,D)cout<<out[i]+1<<endl;
}

int main() {
    input();
    vi res = solve();
    
    // output(res);
    // cerr << "score: " << calc_score(res) << endl;
}
