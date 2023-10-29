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
#include <numeric>

#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)
#define rrep(i,a,b) for (ll i = (a); i >= ll(b); i--)
#define cauto const auto&
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<ll, ll>;
using vl = vector<ll>;
using vi = vector<int>;
using vd = vector<double>;
using vld = vector<long double>;
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
const ll INF = 1LL << 60;
const ll mod = 1000000007;
// const ll mod = 998244353;

// using Graph = vector<vector<ll>>;
// struct Edge {ll to; ll cost;};
using Graph = vector<vector<ll>>;

const ll dx[4] = {0, 1, 0, -1};
const ll dy[4] = {1, 0, -1, 0};
// int dx[8]={-1,-1,-1, 0, 0, 1, 1, 1};
// int dy[8]={-1, 0, 1,-1, 1,-1, 0, 1};

int main() {
    ll n, m; cin >> n >> m;
    Graph G(n);
    rep(i,0,m){
        ll a, b; cin >> a >> b;
        G[--a].emplace_back(--b);
        G[b].emplace_back(a);
    }
    queue<ll> que;
    que.push(0);
    vl dist(n+1, -1);
    ll ans = 0;
    vl cnt(n+1);
    cnt[0] = 1;
    while(!que.empty()){
        auto cur = que.front();
        que.pop();
        for(cauto nv : G[cur]){
            if(dist[nv]==-1){
                dist[nv] = dist[cur] + 1;
                cnt[nv] = cnt[cur];
                que.push(nv);
            } else if(dist[nv] == dist[cur]+1){
                cnt[nv]+=cnt[cur];
                cnt[nv] %= 1000000000+7;
            }
        }
    }
    cout << cnt[n-1] << endl;

}






