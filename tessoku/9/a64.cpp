#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include <queue>
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
using P = pair<ll, ll>;
using Graph = vector<vector<P>>;
using PQ = priority_queue<P, vector<P>, greater<P>>;

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
    int n, m; cin >> n >> m;
    Graph graph(n+1);
    vector<bool> visited(n+1);
    rep(i,0,m){
        int a, b, c; cin >> a >>b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    PQ pq;
    vector<int> dist(n+1, INF);
    dist[1] = 0;
    pq.push({dist[1],1});
    while(!pq.empty()){
        auto now = pq.top().second;
        pq.pop();
        if(visited[now]) continue;
        visited[now] = true;
        for(const auto [next, cost]: graph[now]){
            if(dist[next] > dist[now] + cost){
                dist[next] = dist[now] + cost;
                pq.push({dist[next], next});
            }
        }
    }
    for(int i=1; i<n+1; i++){
        cout << (dist[i] == INF ? -1 : dist[i]) << endl; 
    }

    return 0;
}