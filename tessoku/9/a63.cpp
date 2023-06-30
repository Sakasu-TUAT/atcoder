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

int main() {
    int n, m; cin >> n >> m;
    Graph graph(n+1);
    vector<bool> visited(n+1);
    rep(i,0,m){
        int a, b; cin >> a >>b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    queue<int> que;
    vector<int> dist(n+1, -1);
    dist[1] = 0;
    que.push(1);
    while(!que.empty()){
        int now = que.front();
        que.pop();
        for(const auto next: graph[now]){
            if(dist[next] == -1) dist[next] = dist[now] + 1;
            else continue;
            que.push(next);
        }
    }
    for(int i=1; i<n+1; i++){
        cout << dist[i] << endl; 
    }

    return 0;
}