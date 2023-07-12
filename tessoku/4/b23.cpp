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


int main(){
    int n;
    cin >> n;
    vector<vector<double>> dp(1<<(n+1), vector<double>(n+1));
    vector<int> x(n), y(n);
    rep(i,0,n) cin >> x[i] >> y[i];
    rep(i,0,(1<<n)){
        rep(j,0,n){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    rep(i,0,(1<<n)){
        rep(j,0,n){
            if(dp[i][j]==INF) continue;
            rep(k,0,n){
                if(i & (1<<k)) continue;
                int nv = (i | (1<<(k)));
                double dist = sqrt((x[k]-x[j])*(x[k]-x[j]) + (y[k]-y[j])*(y[k]-y[j]));
                chmin(dp[nv][k], dp[i][j] + dist);
            }
        }
    }

    cout << dp[((1<<n)-1)][0] << endl;

    return 0;
}