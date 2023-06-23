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
#include <cassert>
using namespace std;
using ll = long long;
#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)
#define rrep(i,a,b) for (ll i = (a); i >= ll(b); i--)

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


const ll INF = 1e9;
const ll mod = 1000000007;

int main(){
    int n; cin>>n;
    vector<int> a(n);
    rep(i,0,n){
        cin >> a[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    rep(i,1,n+1){
        dp[n][i] = a[i-1];
    }

    rrep(i,n-1,1){
        rep(j,1,i+1){
            dp[i][j] = i%2==0 ? 
                min(dp[i+1][j], dp[i+1][j+1]) :
                max(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    // for(const auto v : dp){
    //     for(const auto e : v){
    //         cerr << e << " ";
    //     }cerr << endl;
    // }
    cout << dp[1][1] << endl;
    

    return 0;
}

