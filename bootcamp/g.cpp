#include <iostream>
#include <vector>
#include <set>
using namespace std;

void simple_path(int N, int M, vector<int> &U, vector<int> &V, int A, int B, int C) {
    vector<vector<int>> adj(N + 1); // 隣接リスト
    for (int i = 0; i < M; i++) { // 無向グラフなので両方向に辺を追加
        adj[U[i]].push_back(V[i]);
        adj[V[i]].push_back(U[i]);
    }
    vector<int> path; // パスを格納するベクトル
    set<int> visited; // 訪問済みの頂点を格納する集合
    bool foundA = false; // 頂点 A に到達したかどうか
    bool foundC = false; // 頂点 C に到達したかどうか

    // 頂点 B から DFS を行う関数
    bool ok = false;
    auto dfs = [&](auto dfs, int u) -> void{
        path.push_back(u); 
        visited.insert(u); 
        if (u == A) foundA = true; 
        if (u == C) foundC = true;
        if (foundA && foundC) {
            ok = true;
            return; 
        }
        for (int v : adj[u]) { 
            if (visited.count(v) == 0) {
                dfs(dfs, v); // 再帰的に探索する
            }
        }
        path.pop_back(); // パスから現在の頂点を削除
    };

    dfs(dfs, B); // 頂点 B から DFS を開始

    if (ok) { // 頂点 A と頂点 C の両方に到達できた場合
        set<int> s(path.begin(), path.end()); // パスに含まれる頂点を集合に変換
        // if (s.size() == path.size()) { // 集合のサイズとパスのサイズが等しい場合
            cout << "YES" << endl; // 単純パスが存在する
        // } else { // 集合のサイズとパスのサイズが異なる場合
            cout << "NO" << endl; // 単純パスが存在しない
        // }
    } else { // 頂点 A と頂点 C のどちらか一方でも到達できなかった場合
        cout << "NO" << endl; // 単純パスが存在しない
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> U(M), V(M);
    for (int i = 0; i < M; i++) {
        cin >> U[i] >> V[i];
    }
    int A, B, C; 
    cin >> A >> B >> C;
    simple_path(N, M, U, V, A, B, C); 
    return 0;
}
