#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
#include <set>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
using ll = long long;
#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)
//someone_s

template <class T, class U>
bool chmin(T& a, const U& b) {return (b < a) ? (a = b, true) : false;}

template <class T, class U>
bool chmax(T& a, const U& b) {return (b > a) ? (a = b, true) : false;}

void in() {}

template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
    cin >> head;
    in(std::forward<Tail>(tail)...);
}

template<class T>
void printTable(const vector<vector<T>> &tb){
    for(const auto &i : tb){ for(const auto &j : i){cerr << j << " ";}cerr << endl;}
}

const ll INF = 1LL << 60;

int main(){
    string s,t; cin >> s >> t;
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    rep(i,0,n+1) dp[i][0] = i;
    rep(i,0,m+1) dp[0][i] = i;
    rep(i,1,n+1){
        rep(j,1,m+1){
            dp[i][j] = min({dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1] + (s[i-1]!=t[j-1])});
        }
    }
    // printTable(dp);
    cout << dp[n][m] << endl;


    return 0;
}