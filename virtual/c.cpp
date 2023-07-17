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
    vector<string> s(9); 
    rep(i,0,9){
        cin >> s[i];
    }
    auto calc = [](P p1, P p2){
        return  abs(p1.first-p2.first)*abs(p1.first-p2.first) + abs(p1.second-p2.second)*abs(p1.second-p2.second);
    };
    int ans = 0;
    auto check = [&](P p) -> bool{
        int y = p.first, x = p.second; 
        return (0<=y and y<=8 and 0<=x and x<= 8 and s[y][x] == '#');
    };
    rep(i,0,9){
        rep(j,0,9){
            rep(k,1,9){
                rep(l,0,9){
                    P p1{i, j}, p2{i+k, j+l}, p3{i+k+l, j+l-k}, p4{i+l, j-k};
                    if(check(p1) and check(p2) and check(p3) and check(p4)){
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;


    return 0;
}