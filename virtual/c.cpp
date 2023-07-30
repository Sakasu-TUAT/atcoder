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
const ll mod = 1000000000+7;


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

long long pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % mod;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x = x * x % mod;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main(){
   int n, m; cin >> n >> m;
   using Graph = vector<vector<int>> ;
   Graph G(n, vector<int>());
   rep(i,0,m){
    int a,b; cin >> a >> b;
    G[--a].emplace_back(--b);
    // G[b].emplace_back(a);
   }
   ll ans = 0;

   rep(i,0,n){ 
        map<int, bool> visited;
        queue<int> que;
        que.push(i);
        visited[i] = true;
        while(!que.empty()){
            int now = que.front();
            que.pop();
            for(const auto next : G[now]){
                if(visited[next]) continue;
                visited[next] = true;
                que.push(next);
            }
        }
        rep(i,0,n){
            ans+= visited[i];
        }
   }

   cout << ans << endl;

    return 0;
}