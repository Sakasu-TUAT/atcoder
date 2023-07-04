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
    ll N, W; cin >> N >> W;
    vector<ll> w(N+1), v(N+1);
    ll V = 0;
    rep(i,1,N+1){
        cin >> w[i] >> v[i];
        V+= v[i];
    }
    vector<vector<ll>> dp(N+1, vector<ll>(V+1, INF));
    dp[0][0] = 0;
    rep(i,1,N+1){
        rep(j,0,V+1){
            dp[i][j] = dp[i-1][j];
            if(j-v[i] >= 0){
              chmin(dp[i][j], dp[i-1][j-v[i]]+w[i]);
            } 
        }
    }
    // printTable(dp);

    ll ans = 0;
    for(ll i=2; i<V+1; i++){
        if(dp[N][i]<=W){
            ans = i;
        }
    }
    cout << ans << endl;

    return 0;
}