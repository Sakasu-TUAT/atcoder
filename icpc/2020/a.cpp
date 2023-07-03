#include <bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        int n; cin >> n;
        if(n==0) return 0;
    
        int ans = 0;
        vector<int> d(n);
        for(int i=0; i<n; i++){
            cin >> d[i];
        }
        for(int i=0; i<n-3; i++){
            if(d[i]==2 and d[i+1] == 0 and d[i+2]==2
            and d[i+3] == 0){
                ans++;
            }  
        }
        cout << ans << endl;
    }
}