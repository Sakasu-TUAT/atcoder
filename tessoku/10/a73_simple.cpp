#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;
 
struct Edge {
    int to;
    ll w;
    int wood;
    Edge(int to, ll w, int wood): to(to), w(w), wood(wood) {}
};
 
using Graph = vector<vector<Edge>>;
using P = pair<int,pair<int,int>>;
 
int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n);
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--;
        G[a].push_back(Edge(b, c, d));
        G[b].push_back(Edge(a, c, d));
    }
    vector<pair<int,int>> dist(n, make_pair(inf, 0));
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(make_pair(0, make_pair(0, 0)));
    dist[0].first = 0;
    dist[0].second = 0;
 
    while(!que.empty()) {
        int v = que.top().second.first;
        int wood = que.top().second.second;
        int w = que.top().first;
        que.pop();
 
        if (w > dist[v].first) continue;
        for (auto e : G[v]) {
            if (dist[e.to].first > dist[v].first+e.w) {
                dist[e.to].first = dist[v].first + e.w;
                dist[e.to].second = dist[v].second + e.wood;
                que.push(make_pair(dist[e.to].first, make_pair(e.to, dist[e.to].second)));
            } else if (dist[e.to].first == (dist[v].first + e.w)) {
                if (dist[e.to].second < dist[v].second + e.wood) {
                    dist[e.to].second = dist[v].second + e.wood;
                    que.push(make_pair(dist[e.to].first, make_pair(e.to, dist[e.to].second)));
                }
            }
        }
    }
    cout << dist[n-1].first << " " << dist[n-1].second << endl;
    return 0;
}