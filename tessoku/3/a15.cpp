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
ll n;
vector<ll> a, b;
set<ll> st;
int main(){
    int n; cin >> n;
    a.resize(n);
    rep(i,0,n){
        cin >> a[i];
        st.insert(a[i]);
    }
    for(const auto v : st){
        b.emplace_back(v);
        cerr << v << ", ";
    }
    cerr << endl;

    
    for(const auto v : a){
        cout << lower_bound(b.begin(), b.end(), v) - b.begin() + 1 << " ";
    }
    cout<< endl;

    return 0;
}