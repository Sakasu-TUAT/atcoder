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
    int n; cin >> n;
    vector<int> p(n), a(n);
    rep(i,0,n){
        cin >> p[i] >> a[i];
    }    
    vector<vector<int>> dp(n+1, vector<int>(n+1));

    dp[0][n] = 0;

    rep(l,1,n+1){
        for(int r=n; r>l; r--){
            chmax(dp[l+1][r], (l<=p[l-1] and p[l-1]<=r ? dp[l][r] + a[l-1] : dp[l][r]) );
            chmax(dp[l][r-1], (l<=p[r-1] and p[r-1]<=r ? dp[l][r] + a[r-1] : dp[l][r]) );
        }
    }

    int ans = 0;
    rep(i,0,n+1){
        chmax(ans, dp[i][i]);
    }
    cout << ans << endl;

}

