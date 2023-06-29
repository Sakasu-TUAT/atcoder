#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,k,ans=0;cin>>h>>w>>k;vector<string> C(h);  
  for(int i=0;i<h;i++) cin>>C[i];
  for(int i=0;i<(1<<h);i++){
    int x=i,y=0,z=0;vector<int> B(w,0);
    while(x>0) {if(x&1) y++; x>>=1;}
    if(y>k) continue;
    for(int l=0;l<h;l++) if(!((i>>l)&1)) for(int j=0;j<w;j++) if(C[l][j]=='#') z++;
    ans=max(ans,z+y*w);
  }
  cout<<ans;
}