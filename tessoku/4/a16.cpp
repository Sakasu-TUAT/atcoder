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
    vector<int> dp(n+1, INF), a(n+1), b(n+1);
    rep(i,2,n+1){ cin >> a[i];}
    rep(i,3,n+1){ cin >> b[i];}
    dp[0] = 0;
    rep(i,1,n+1){
        if(i==1) {
            dp[i] = a[i];
            continue;
        }
        if(i==2) {
            chmin(dp[i], dp[i-1]+a[i]);
            continue;
        }
        chmin(dp[i], dp[i-1]+a[i]);
        chmin(dp[i], dp[i-2]+b[i]);
    }
    cout << dp[n] << endl;

}