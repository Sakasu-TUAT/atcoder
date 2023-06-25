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
#include <set>
#include <deque>
#include <stack>
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
    int n, q; cin >> n >> q;
    string s; cin >> s;

    // while(q--){
    //     int x; cin >> x;
    //     if(x==1){
    //         int a; cin >> a;
    //         st.insert(a);
    //     } else if(x==2){
    //         int a; cin >> a;
    //         st.erase(a);
    //     } else {
    //         int a; cin >> a;
    //         auto itr = st.lower_bound(a); 
    //         cout << (itr == st.end() ? -1 : *itr) << endl;
    //     }
    // }
   

    return 0;
}

