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
using ull = unsigned long long;
using ll = long long;
using P = pair<ll, ll>;
using vll = vector<ll>;
using vi = vector<int>;

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
// const ll mod = 1000000007;
const ll mod = 998244353;
using Graph = vector<vector<ll>>;


/* encode: ランレングス圧縮を行う
*/
vector<pair<char, int>> encode(const string& str) {
    int n = (int)str.size();
    vector<pair<char, int>> ret;
    for (int l = 0; l < n;) {
        int r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {};
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}
/* decode: ランレングス圧縮の復元を行う
*/
string decode(const vector<pair<char, int>>& code) {
    string ret = "";
    for (auto p : code) {
        for (int i = 0; i < p.second; i++) {
            ret.push_back(p.first);
        }
    }
    return ret;
}

int main() {
    ll n, k; cin >> n >> k;
    vll vec(n);
    ll now = 0, sortedCnt = 1, sortedMaxCnt = 0;
    ll lastSortedPos = 0;
    rep(i,0,n){
        ll p; cin >> p;
        vec[i] = p;
        if(i==0) {now = p; continue;}
        if(now<=p) {
            sortedCnt++;
            if(i <= n-k+1){
                lastSortedPos = i-sortedCnt;
            }
        }
        else sortedCnt = 0;
        if(sortedMaxCnt < sortedCnt){
            // lastSortedPos = i;
            chmax(sortedMaxCnt, sortedCnt);
        }
        now = p;
    }
    // cerr << "lastSortedPos: " << lastSortedPos << endl;
    vll tmp(k);
    rep(i,0,k){
        tmp[i] = vec[lastSortedPos + i];
        // cerr << "veci : " << tmp[i]  << ", ";
    }
    sort(all(tmp));
    // for(cauto v : tmp){
    //     cerr << v << " , ";
    // }cerr << endl;
    vll sorted = vec;
    sort(all(sorted));
    if(sorted == vec){
        
    }

    if(sortedMaxCnt >= k){
        for(cauto v : vec){
            cout << v << " ";
        }
        cout << endl;
    } else {
        // cout << "Not Impled Yet" << endl;
        rep(i,0,lastSortedPos){
            cout << vec[i] << " ";
        }
        rep(i,0,k){
            cout << tmp[i] << " ";
        }
        rep(i,lastSortedPos+k,n){
            cout << vec[i] << " ";
        }
        cout << endl;
    }
}


