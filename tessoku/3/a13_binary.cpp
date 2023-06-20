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

ll n, k; 
vector<ll> a;

ll binary_search(ll s, ll e){
    ll ok = s;
    ll ng = e;
    ll mid;
    while(abs(ok-ng)>1){
        mid = (ok+ng)/2;
        if(a[mid]-a[s] <= k) ok = mid;
        else ng = mid;
    }
    cerr << "[" << a[s] << ", "<<a[ok]<<"]"<< endl;
    return ok;
}

int main(){
    cin >> n >> k;
    a.resize(n);
    rep(i,0,n){
        cin >> a[i];
    }
    ll ans = 0;
    rep(i,0,n-1){
        ans += (binary_search(i,n)); // iの総和の項を引けば通る
        // ans += (binary_search(i,n) - i); @TLE!
    }
    ans -= (1+n-2)*(n-2)/2;
    cout << ans << endl;
    return 0;
}