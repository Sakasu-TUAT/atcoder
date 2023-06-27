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
// const ll mod = 1000000007;

long long mod = 2147483647;
long long T[200010], H[200010];
long long Power100[200010];

long long Hash_value(int l, int r) {
  long long val = H[r] - (H[l-1] * Power100[r-l+1] % mod);
  if(val < 0) val += mod;
  return val;
}

int main() {
  long long N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  long long a[Q+1], b[Q+1], c[Q+1], d[Q+1];
  for(int i = 1; i <= Q; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  for(int i = 1; i <= N; i++) T[i] = (S[i-1] - '0') + 1;

  Power100[0] = 1;
  for(int i = 1; i <= N; i++) Power100[i] = 100LL * Power100[i-1] % mod;

  H[0] = 0;
  for(int i = 1; i <= N; i++) H[i] = (100LL * H[i-1]  + T[i]) % mod;

  for(int i = 1; i <= Q; i++) {
    long long hash1 = Hash_value(a[i], b[i]);
    long long hash2 = Hash_value(c[i], d[i]);
    if(hash1 == hash2) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

    return 0;
}

