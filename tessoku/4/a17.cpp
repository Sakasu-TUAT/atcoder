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

int main(){
    int n;
    cin >> n;
    vector<ll> a(n-1), b(n-2);
    rep(i,0,n-1) cin >> a[i];
    rep(i,0,n-2) cin >> b[i];

    vector<ll> dp(n, 1e7);
    dp[0] = 0;
    vector<int> from(n);
    from[0]=-1;
    rep(i,1,n){
        if(chmin(dp[i], dp[i-1]+a[i-1])) from[i] = i-1;
        if(i-2>=0) {
            if(chmin(dp[i], dp[i-2]+b[i-2])){
                from[i] = i-2;
            }
        }
    }
    for(auto v : from) {
        cerr << v << " ";
    }cerr << endl;
    //ゴールから戻る
    int now = n-1;
    vector<int> ans;
    while(now>=0){
        ans.emplace_back(now+1);
        now = from[now];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto v : ans){
        cout << v << " ";
    }cout << endl;




}