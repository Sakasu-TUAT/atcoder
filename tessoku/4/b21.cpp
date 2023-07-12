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
    int n; string s; 
    cin >> n >> s;
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    rep(i,0,n){
        dp[i][i] = 1;
    }
    rep(i,0,n-1){
        if(s[i]==s[i+1]) dp[i][i+1] = 2;
        else dp[i][i+1] = 1;
    }
    rep(i,2,n){
        rep(l,0,n-i){
            int r = l+i;
            dp[l][r] = max({dp[l][r-1], dp[l+1][r], (s[l]==s[r])*(dp[l+1][r-1]+2)});
        }
    }
    cout << dp[0][n-1] << endl;

    return 0;
}