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

using namespace std;
using ll = long long;
#define rep(i,a,b) for (int i = (a); i < int(b); i++)

int binary_search(int key, vector<int> a){
    int ng = -1;
    int ok = a.size();
    while(abs(ok-ng)>1){
        int mid = (ok + ng)/2;
        if(a[mid] > key) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    int n, x; cin >> n >> x;
    vector<int> a(n);
    rep(i,0,n){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cout << binary_search(x, a) << endl;

    return 0;
}