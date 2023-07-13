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
#include <unordered_set>

#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)
#define rrep(i,a,b) for (ll i = (a); i >= ll(b); i--)
#define cauto const auto&
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = uint64_t;
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
    int n; cin >> n; 
    vector<tuple<ll, ll, ll>> p(n);
    ll sum = 0;
    rep(i,0,n) {
        ll a, b; cin >> a >> b;
        p[i] = {2*a+b, a+b, a};
        sum += a;
    }
    sort(rall(p));
    ll takahashi_sum = 0;
    rep(i,0,n){
        auto [x, t_sum, a] = p[i];
        // cerr << t_sum << ", " << a << ", " << b << endl;
        takahashi_sum += t_sum;
        sum -= a;
        if(takahashi_sum > sum){
            cout << i+1 << endl;
            return 0;
        }
    }
    return 0;
}



