#include <bits/stdc++.h>
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


vector<bool> Eratosthenes(const int &n) {
    vector<bool> ret(n + 1, true);
    if (n >= 0) ret[0] = false;
    if (n >= 1) ret[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (!ret[i]) continue;
        for (int j = i + i; j <= n; j += i) ret[j] = false;
    }
    return ret;
}
vector<pair<int, ll>> tmp;

ll rec(ll a, ll b, ll c, int t) {
    if (t == tmp.size()) return a + b + c;
    auto [n, p] = tmp[t];
    vector<ll> pw(n + 1, 1);
    rep(i,0,n+1) pw[i + 1] = pw[i] * p;
    ll ret = INF;
    rep(i, 0, n+1) {
        rep(j, 0, n - i+1) {
            int k = n - i - j;
            if (t == 0 && (i > j || j > k)) continue;
            chmin(ret, rec(a * pw[i], b * pw[j], c * pw[k], t + 1));
        }
    }
    return ret;
}

int main(){
    while(true){

        int m = 32000000;
        vector<bool> p = Eratosthenes(m);
        vector<ll> ps;
        for(int i=1; i<=m+1; i++){
            if(p[i]) ps.emplace_back(i);
        }
  
        while(true){
            ll n; cin >> n;
            if(n==0) break;
            tmp.clear();
            for(const auto v : ps){
                int c = 0;
                while(n%v==0) { 
                    n/=v;
                    c++;
                }
                if(c>0) tmp.emplace_back(c,v);
            }
            if(n>1) tmp.emplace_back(1, n);
            sort(tmp.rbegin(), tmp.rend());
            cout << rec(1,1,1,0) << endl;
        }
    
        
    }
}