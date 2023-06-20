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
vector<ll> a, b, c, d;

int main(){
    cin >> n >> k;
    a.resize(n), b.resize(n), c.resize(n), d.resize(n);

    rep(i, 0, n)cin >> a[i];
    rep(i, 0, n)cin >> b[i];
    rep(i, 0, n)cin >> c[i];
    rep(i, 0, n)cin >> d[i];

    vector<ll> p(n*n), q(n*n);
    rep(i,0,n){rep(j,0,n){
        p.emplace_back(a[i]+b[j]);
        q.emplace_back(c[i]+d[j]);
    }}

    sort(q.begin(), q.end());
    // auto binary_search = [&](ll target, vector<ll> q){
    //     ll ng = -1;
    //     ll ok = q.size();
    //     ll mid = 0;
    //     while(abs(ok-ng)>1){
    //         mid = (ok+ng)/2;
    //         if(q[mid] >= target) ok = mid;
    //         else ng = mid;
    //         cerr << "mid : q[mid] = " << mid << " : " << q[mid] << endl;
    //     }
    //     cerr << "ans: " << q[ok]  << " = "<< target << endl;
    //     return (q[ok] == target) ? true : false;
    // };

    // rep(i,0,n*n){
    //     ll target = k-p[i];
    //     cerr << "target : " << target << endl;
    //     if(target < q[0] or target > q[q.size()-1]) continue;
    //     auto result = binary_search(target, q);
    //     if(result) {
    //         cout << "Yes" << endl;
    //         return 0;
    //     }
    // }
    for(const auto v : p){
        const auto res = lower_bound(q.begin(), q.end(), k-v) - q.begin();
        if (res==q.size()) continue;
        if(q[res]==k-v){
            cout << "Yes" << endl;
            return 0;
        }

    }
    cout << "No" << endl;


    return 0;
}