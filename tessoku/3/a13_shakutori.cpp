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
    ll rpos = 0;
    rep(lpos,0,n-1){
        while(rpos < n and a[rpos] - a[lpos] <= k){
            rpos++;
        }
        cerr << "r, l = " << rpos << " - " << lpos << endl;
         ans += rpos-(lpos+1);
    }
    cout << ans << endl;
    return 0;
}