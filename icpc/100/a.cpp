#include <bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        string s; 
        int y, m, d;
        cin >> s >> y >> m >> d;

        if(s=="#") return 0;
        int day = m*31;
        if(y>=31 and m>=5 and d >= 1){
            cout << "? " << y-30 << " " << m <<" " <<  d << endl;
        } else if(y>31){
            cout << "? " << y-30 << " " << m <<" " <<  d << endl;
        } else {
            cout << s << " " << y << " " << m << " " << d << endl;
        }
    
    }
}