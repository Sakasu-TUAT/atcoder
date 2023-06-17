#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    for(auto &v : s){
        int tmp = v+n;
        if(v+n > 'Z') tmp = tmp-'Z'+'A'-1;  
        v = tmp;
    } 
    cout << s << endl;
    return 0;


}