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
    uint64_t n, x; cin >> n >> x;
    string s; cin >> s;

    vector<int> bit;
    while (x != 0) {
        bit.emplace_back(x%2);
        x /= 2;
    }
    reverse(all(bit));

    auto f = [&](vector<int> bit, string s) -> vector<int> {
        for(const auto v : s){
            if(v=='U') {
                // x/=2;
                bit.pop_back();
            }
            else if(v=='L') {
                // x*=2;
                bit.push_back(0);
            }
            else {
                bit.push_back(1);
            }
    
        }
        return bit;
    };
    bit = f(bit, s);

    reverse(all(bit));

    uint64_t ans = 0;
    ll b = 1;
    for(const auto v : bit){
        ans += b*v;
        b = (b << 1);
    }
    cout << ans << endl;

    return 0;
}