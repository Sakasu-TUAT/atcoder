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
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main(){
    ll h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i,0,h){cin >> s[i];}

    rep(i,0,h){
        rep(j,0,w){
            if(s[i][j] != '.') continue;
            rep(k,0,5){
                if(i!=0) if(s[i-1][j] == '1'+k) continue;
                if(i!=h-1) if(s[i+1][j] == '1'+k) continue;
                if(j!=0) if(s[i][j-1] == '1'+k) continue;
                if(j!=w-1) if(s[i][j+1] == '1'+k) continue;
                s[i][j] = '1'+k;
                break;
            }
        }
    }
    rep(i,0,h){
        cout << s[i] << endl;
    }
    
    return 0;
}



