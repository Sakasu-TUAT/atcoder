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


int main(){
    int a, b, c;
    // cin >> a >> b >> c;
    vector<int> vec(3);
    rep(i,0,3){
        cin >> vec[i];
    }
    int cnt;
    rep(i,0,3){
        if(vec[i]%2==0) cnt++;
    }
    int ans = 0; 
    cerr << "cnt : " << cnt << endl;
    if(cnt==2){
        rep(i,0,3){
            if(vec[i]%2==0){
                vec[i]++;
            }
        }
        ans++;
    } else if(3-cnt==2){
        rep(i,0,3){
            if(vec[i]%2==1){
                vec[i]++;
            }
        }
        ans++;
    }
    for(const auto v : vec) {
        cerr <<  v << " ";
    }cerr << endl;
    int maxV = max({vec[0], vec[1], vec[2]});
    rep(i,0,3){
        ans += (maxV-vec[i])/2;
    }
    cout << ans << endl;



    return 0;
}