#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits>
#include <cmath>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <deque>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <functional>

#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)
#define rrep(i,a,b) for (ll i = (a); i >= ll(b); i--)
#define cauto const auto&
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = 1LL << 60;
const ll mod = 1000000007;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template <class T, class U> bool chmin(T& a, const U& b) {return (b < a) ? (a = b, true) : false;}
template <class T, class U> bool chmax(T& a, const U& b) {return (b > a) ? (a = b, true) : false;}
void in() {}
template <class Head, class... Tail> void in(Head&& head, Tail&&... tail) {cin >> head;in(std::forward<Tail>(tail)...);}
void printMatrix(const auto &vec){for(const auto &v : vec){ for(const auto &e : v){cerr << e << " ";}cerr << endl;}}
template<class T> void printTable(const vector<vector<T>> &tb){ for(const auto &i : tb){ for(const auto &j : i){cerr << j << " ";}cerr << endl;}}
vector<bool> Eratostenes(int n){ vector<bool> isprime(n+1, true);isprime[1] = false; rep(p,2,n+1){ if(!isprime[p]) continue; for(int q = p*2; q <= n; q+=p){ isprime[q] = false; }} return isprime;}
ll power(ll a, ll b) { ll ans = 1;for(ll i=0; i<60; i++){if(b & (1LL<<i)) {ans *= a;ans %= mod;}a *= a;a %= mod;}return ans;}
ll combination(ll n, ll k){ assert(!(n < k)); assert(!(n < 0 || k < 0)); ll s = 1, t = 1; rep(i,1,k+1){ s = s*(n-i+1) % mod; t = t*i % mod; } return s * power(t, mod-2) % mod;}

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {-1, 0, 1, 0};
using Graph = vector<vector<ll>>;

int main(){
    int n, m;
    cin >> n >> m;
    Graph G(n);
    rep(i,0,m){
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    map<ll, ll> mp;
    queue<int> que;
    que.push(0);
    vector<bool> seen(n);
    vector<ll> dist(n, INF);
    vector<ll> cnt(n, 0);
    dist[0] = 0;
    while(!que.empty()){
        int now = que.front();
        que.pop();
        for(const auto nv : G[now]){
            if(nv==n-1){
                mp[dist[now]+1]++;
                dist[nv] = dist[now]+1;
                cerr << now+1 << " -> " << nv+1 << endl;
                continue;
            } else {
                if(seen[nv]) continue;
                if(cnt[])
                seen[nv] = true;
                que.push(nv);
                chmin(dist[nv], dist[now]+1);
            }
        }
        seen[now] = true;
    }
    // sort(all(mp));
    if(dist[n-1]==0){
        cout << 0 << endl;
        return 0;
    }
    for(const auto [k, v] : mp){
        cout << v%mod << endl;
        cerr << k << endl;
        // return 0;
    }


}