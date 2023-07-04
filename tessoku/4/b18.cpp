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
    int n, s; cin >> n >> s;
    vector<vector<bool>> dp(n+1, vector<bool>(s+1));
    // dp[i][j] := i番目のカードを選択したときに合計がjになるかどうか
    dp[0][0] = true;
    vector<int> a(n+1);
    rep(i,1,n+1) cin >> a[i];
    rep(i,1,n+1){
        rep(j,0,s+1){
            if(a[i] <= j and dp[i-1][j-a[i]]){
                dp[i][j] = true;
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    // for(const auto v : dp){
    //     for(const auto e : v){
    //         cerr << e << " ";
    //     }cerr << endl;
    // }

    vector<int> ans;
    if(!dp[n][s]){
        cout << -1 << endl;
        return 0;
    } else {
        int card = n,sum=s;
        //合計値が変化した時のカードが使用したカード
        while(card){
            if(!dp[card-1][sum]){
                ans.emplace_back(card);
                sum-=a[card];
            }
            card--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(const auto v : ans){
        cout << v << " ";
    }cout << endl;    
}