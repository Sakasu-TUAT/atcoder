#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
#include <set>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <bitset>
#include <cassert>
using namespace std;
using ll = long long;
#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)
#define rrep(i,a,b) for (ll i = (a); i >= ll(b); i--)

template <class T, class U>
bool chmin(T& a, const U& b) {return (b < a) ? (a = b, true) : false;}
template <class T, class U>
bool chmax(T& a, const U& b) {return (b > a) ? (a = b, true) : false;}
void in() {}

template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
    cin >> head;
    in(std::forward<Tail>(tail)...);
}

const ll INF = 1e9;
const ll mod = 1000000007;

int main(){
    int n; char c; cin >> n >> c;
    int ans = 0;
    rep(i,0,n){
        char s; cin >> s;
        if(s=='W') ans+=0;
        if(s=='B') ans+=1;
        if(s=='R') ans+=2;
    }
    int moduler = ans%3;
    if(
        (c=='W' and moduler == 0) or
        (c=='B' and moduler == 1) or
        (c=='R' and moduler == 2) 
    ) cout << "Yes" << endl;
    else {
        cout << "No" << endl;
    }

    return 0;
}

