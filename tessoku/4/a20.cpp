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
#include <bitset>
using namespace std;
using ll = long long;
#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)

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

int main(){
    string s, t; cin >> s >> t;
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    vector<char> a;
    rep(i,1,n+1){
        rep(j,1,m+1){
            chmax(dp[i][j], 
            max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+(s[i-1]==t[j-1])}));
        }
    }
    cout << dp[n][m] << endl;
    for(const auto v : a){
        cout << v;
    }cout << endl;
    
}
