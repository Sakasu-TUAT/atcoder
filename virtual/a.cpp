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
template<class T> void printTable(const vector<vector<T>> &tb){ for(const auto &i : tb){ for(const auto &j : i){cerr << j << " ";}cerr << endl;}}
template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
    cin >> head;
    in(std::forward<Tail>(tail)...);
}
const ll INF = 1LL << 60;
const ll mod = 1000000007;
ll dx[4] = {1, 0, 1, 1};
ll dy[4] = {0, 1, 1, -1};

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}


int main(){
    ll n, s, t; cin >> n >> s >> t;
    s--; t--;
    vector<vector<ll>> G(n+1);
    rep(i,0,n-1){
        ll u, v; cin >> u >> v; 
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    bool reached = false;

    auto bfs = [&](int start, int target) -> auto {
        vector<bool> visited(n+1, false);
        queue<int> que;
        que.push(start);
        vector<int> prev(n, -1); 
        while(!que.empty()){
            int now = que.front();
            que.pop();
            visited[now] = true;
            if(now == target){ break; }
            for(const auto v : G[now]){
                if(visited[v]) continue;
                que.push(v);
                prev[v] = now;
            }
        }
        set<ll> st; 
        int now = target;
        while(now != -1) {
            st.insert(now);
            now = prev[now];
        }
        return st;
    };

    rep(j,0,n){
       auto st1 = bfs(s, j);
       auto st2 = bfs(t, j);
       int cnt = 0;
       for(const auto v : st1){
            if(st2.count(v)) cnt++;
       }
       cout << cnt << endl;
    }
  
   
    return 0;
}