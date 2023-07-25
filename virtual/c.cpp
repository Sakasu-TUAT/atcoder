#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits>
#include <cmath>
#include <iomanip>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cinttypes>

#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)
#define rrep(i,a,b) for (ll i = (a); i >= ll(b); i--)
#define cauto const auto&
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int gcd(int a,int b){return b?gcd(b,a%b):a;}
template <class T, class U>
bool chmin(T& a, const U& b) {return (b < a) ? (a = b, true) : false;}
template <class T, class U>
bool chmax(T& a, const U& b) {return (b > a) ? (a = b, true) : false;}
void in() {}
void printMatrix(const auto &vec){for(const auto &v : vec){ for(const auto &e : v){cerr << e << " ";}cerr << endl;}}
template<class T> void printTable(const vector<vector<T>> &tb){ for(const auto &i : tb){ for(const auto &j : i){cerr << j << " ";}cerr << endl;}}
template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
    cin >> head;
    in(std::forward<Tail>(tail)...);
}
const ll INF = 1LL << 60;
const ll mod = 1000000007;

int main(){
    int n;
    cin >> n;
    unordered_map<string, vector<string>> G(n);
    vector<string> s;
    rep(i,0,n){
        string a, b; cin >> a >> b;
        G[a].emplace_back(b);
        s.emplace_back(a);
    }
    int cnt = 0;
    unordered_map<string, bool> memo;
    rep(i,0,n){
        string start = s[i];
        if(memo[start]) continue;
        memo[start] = true;
        queue<string> que;
        que.push(start);
        unordered_map<string, bool> visited;
        visited[start] = true;
        while(!que.empty()){
            string now = que.front(); que.pop();
            for(const auto next : G[now]){
                if(visited[next]) {
                    cout << "No" << endl;
                    return 0;
                }
                memo[next] = true;
                visited[next] = true;
                que.push(next);
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
}