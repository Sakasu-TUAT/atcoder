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

const int INF = 1e9;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(m, vector<int> (n));
    vector<vector<int>> dp(m+1, vector<int> (1<<n+1, INF));

    rep(i,0,m) rep(j,0,n) cin >> a[i][j];
    dp[0][0] = 0;

    rep(i,1,m+1){
        rep(j,1,1<<n+1){
           chmin(dp[i][j-1], dp[i-1][j-1]);
           int tmp = j-1;
           rep(k,1,n+1){
                if(a[i-1][k-1]) tmp |= (1<<(k-1));
           }
            chmin(dp[i][tmp], dp[i-1][j-1] + 1);
        }
    }

    cout << (dp[m][(1<<n)-1] != INF ? dp[m][(1<<n)-1] : -1) << endl;  

    return 0;
}

