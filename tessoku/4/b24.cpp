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

int calcLIS (const vector<int> &a){
    int len = 0;
    int n = a.size();
    vector<int> l(n+1);
    rep(i,0,n){
        int pos = lower_bound(l.begin()+1, l.begin()+len+1, a[i]) - l.begin();
        l[pos] = a[i];
        if(pos>len) len++;
    }
    return len;
}

int main(){
    int n;
    cin >> n;
    vector<P> p(n);
    for(auto &[x, y] : p){
        cin >> x >> y;
        y*=(-1);
    }
    sort(all(p));
    vector<int> b;
    rep(i,0,n){
        b.emplace_back(-p[i].second);
    }

    cout << calcLIS(b) << endl;

    return 0;
}