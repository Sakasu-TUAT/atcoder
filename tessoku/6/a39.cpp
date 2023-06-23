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

    int n;  cin >> n;
    vector<pair<int, int>> interval(n);

    for(auto &[l, r] : interval){
        cin >> l >> r;
    }

    // rep(i,0,n){
    //     int l, r; cin >> l >> r;
    //     interval.emplace_back(l, r);
    // }

    sort(interval.begin(), interval.end(), [](const auto &a, const auto &b){
        return a.second < b.second;
    });

    int currentTime = 0, ans = 0;
    for(const auto &[l, r] : interval){
        if(currentTime <= l){
            currentTime = r;
            ans++;
        }
    }

    cout << ans << endl;



    return 0;
}

