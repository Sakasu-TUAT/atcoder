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

int main(){
    cin >> n >> k;
    a.resize(n);
    rep(i,0,n){
        cin >> a[i];
    }
    ll ans = 0;
    rep(i,0,n){
        ans += ((upper_bound(a.begin(), a.end(), a[i]+k) - lower_bound(a.begin(), a.end(), a[i]-k)));
    }
    rep(i,0,n) ans--;
    cout << ans/2 << endl;
    return 0;
}