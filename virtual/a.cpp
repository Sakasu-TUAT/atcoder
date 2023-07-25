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
    int n; cin >> n;
    vector<string> s(n);
    rep(i,0,n){
        cin >> s[i];
    }
    rep(i,0,n){
        rep(j,0,n){
            if(i==0){
                if(j==0){
                    cout << s[i+1][0];
                } else {
                    cout << s[i][j-1];
                }
                if(j==n-1) cout << endl;
            } else if(i==n-1){
                if(j==n-1){
                    cout << s[n-2][n-1] << endl;
                } else {
                    cout << s[n-1][j+1];
                }
            } else{
                if(j==0){
                    cout << s[i+1][0]; 
                } else if(j==n-1){
                    cout << s[i-1][n-1];
                } else {
                    cout << s[i][j];
                }
                if(j==n-1) cout << endl;
            }
   
        }  
    }
    return 0;
}



