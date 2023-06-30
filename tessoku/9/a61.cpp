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

const ll INF = 1e9;
const ll mod = 1000000007;

int main() {
    int n,m; cin >> n >> m;
    vector<vector<int>> graph(n+1);
    rep(i,0,m){
        int a, b; 
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    for(int i=1; i<n+1; i++){
        cout << i << ": {";
        for(const auto v : graph[i]){
            cout << v << ((v==graph[i].back()) ? "" : ", "); 
        }
        cout << "}" << endl;
    }
    return 0;
}