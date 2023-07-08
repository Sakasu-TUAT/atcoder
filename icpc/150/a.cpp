#include <bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        int n, m; cin >> n >> m;
        if(n==0 and m==0) break;
        vector<int> vec(m+1);
        vector<int> a(n+1), b(m+1);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        
        for(int i=0; i<m; i++){
            cin >> b[i];
        }
        string s;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                s += a[i]*b[j];
            }
        }
        map<int, int>mp;
        for(int i=0; i<s.length()-1; i++){
            mp[s[i]] ++;
        }
        int ans = 0;
        for(int i=1; i<=9; i++){
            cout << mp[i] << " ";
        }
        cout << endl;
    
    }
}