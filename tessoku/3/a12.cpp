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

ll checkSum(ll mid){
    ll sum = 0;
    for(ll i=0; i<n; i++){
        sum += mid/a[i];
    }
    return sum;
}

ll binary_search(ll key){
    ll ng = -1;
    ll ok = 1e9+1;
    while(abs(ok-ng)>1){
        ll mid = (ok + ng)/2;
        if(checkSum(mid) >= key) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    cin >> n >> k;
    a.resize(n);
    rep(i,0,n){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cout << binary_search(k) << endl;

    return 0;
}