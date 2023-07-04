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

const ll INF = 1e9;

int main(){
    int n; cin >> n;
    vector<int> dp(n+1, INF), h(n+1);
    rep(i,1,n+1){ cin >> h[i];}
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = abs(h[2]-h[1]);
    rep(i,3,n+1){
        chmin(dp[i], dp[i-1]+abs(h[i]-h[i-1]));
        chmin(dp[i], dp[i-2]+abs(h[i]-h[i-2]));
    }
    cout << dp[n] << endl;
}