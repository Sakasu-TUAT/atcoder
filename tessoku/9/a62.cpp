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
#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

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

int n;
void dfs(const Graph &g, vector<bool> &visited, int node){
    visited[node] = true;
    for(const auto v : g[node]){
        if(!visited[v]) dfs(g, visited, v);
    }
}

int main() {
    int m; cin >> n >> m;
    Graph graph(n+1);
    vector<bool> visited(n+1);
    rep(i,0,m){
        int a, b; cin >> a >>b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    dfs(graph, visited, 1);
    bool flag = true;
    rep(i,1,n+1){
        flag &= visited[i];  
    }
    cout << (flag ? 
    "The graph is connected."
    : "The graph is not connected.") << endl;


    return 0;
}