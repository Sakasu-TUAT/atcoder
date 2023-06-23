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
    int n, x, y; cin>>n>>x>>y;
    vector<int> A(n);
    rep(i,0,n){
        cin >> A[i];
    }
    vector<int> grundy(1e5+9);
    rep(i,0,1e5+1){
        int a = 1e9, b = 1e9;
        if(i>=x) a = grundy[i-x];
        if(i>=y) b = grundy[i-y];

        if(a >= 1 and b >= 1) grundy[i] = 0;
        else if (a + b == 1) grundy[i] = 2;
        else grundy[i] = 1;        
    }
    int nimSum = 0;
    rep(i,0,n){ nimSum ^= grundy[A[i]];}

    cout << (nimSum == 0 ? "Second" : "First") << endl;


    return 0;
}

