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
    int h, w, c, q;
    cin >> h >> w >> c >> q;
    vector<tuple<ll, ll, ll>> query;
    rep(i,0,q){
        int t, n, c;
        cin >> t >> n >> c;
        t--; n--; c--;
        query.emplace_back(t, n, c);
    }
    vector<ll> ans(c);
    vector<bool> row(h);
    vector<bool> col(w);
    reverse(query.begin(), query.end());

    for (const auto &q : query){
        auto [t, n, color] = q;
        if(!t){
            if(row[n]) continue;
            ans[color] += w;
            row[n] = true;
            h--;
        } else {
            if(col[n]) continue;
            ans[color] += h;
            col[n] = true;
            w--; 
        }
    }
    rep(i,0,c){
        cout << ans[i] << "\n "[i<c-1];
    }
        

 
  
    return 0;
}