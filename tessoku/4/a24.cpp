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


template<class T>
T BinarySearch(const vector<T> &a, T target){
    T ok = a.size()+1;
    T ng = -1;
    T mid;
    while(abs(ok-ng)>1){
        mid = (ok + ng)/2;
        if(a[mid] >= target) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,0,n){
        cin >> a[i];
    }   
    vector<int> dp(n+1), l(n+1);
    int len = 0;
    rep(i,0,n){
        int pos = lower_bound(l.begin()+1, l.begin()+1+len, a[i]) - l.begin();
        l[pos] = a[i];
        dp[i] = pos;
        if(pos>len)  len++;
    }
    cout << len << endl;


    return 0;
}

