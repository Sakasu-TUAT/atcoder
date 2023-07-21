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
    ll n, q; cin >> n >> q;
    vector<int> vec(n+1);
    map<int, int> mp;
    rep(i,1,n+1){
        vec[i] = i;
        mp[i] = i;
    }
    while(q--){
        ll x; cin >> x;
        int pos1 = mp[x];
        int pos2 = pos1;
        if(pos1==n) pos2--;
        else pos2++;
        int v1 = vec[pos1];
        int v2 = vec[pos2];
        swap(vec[pos1], vec[pos2]);
        swap(mp[v1], mp[v2]);
    }
    for(const auto v : vec){
        cerr << v << " ";
    }cerr << endl;
    rep(i,1,n+1){
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}