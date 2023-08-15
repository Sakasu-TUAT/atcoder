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
ll dx[4] = {1, 0, 0, -1};
ll dy[4] = {0, 1, -1, 0};

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
    ll h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i,0,h){
        cin >> s[i];
        // cerr << s[i] << endl;
    }

    auto ok = [&](P nx) -> bool {
        auto &[y, x] = nx;
        if(x>=0 and x<w and y>=0 and y<h){
            // cerr << nx.first << ": " << nx.second << endl;
            // cerr << s[y][x] << endl;
            if(s[y][x]=='.') return true;
            else return false;
        } else {
            return false;
        }
    };

    queue<P> que;
    que.push({0, 0});
    map<P, ll> dist;
    map<P, bool> visited;
    // dist[P{0, 0}];
    ll ans = 0;
    while(!que.empty()){
        P now = que.front();
        // cerr << now.first << ", " << now.second << endl;
        que.pop();
        visited[now] = true;
        rep(i,0,2){
            P nx = {now.first + dy[i], now.second + dx[i]};
                // cerr << nx.first << ": " << nx.second << endl;
            if(ok(nx) and !visited[nx]){
                chmax(dist[nx], dist[now]+1);
                que.push(nx);
                visited[nx] = true;
            }
        }
    } 
    for(const auto &[k, v] : dist){
        // cerr << v << " ";
        chmax(ans, v);
    }
    cout << ans+1 << endl;

   
    return 0;
}