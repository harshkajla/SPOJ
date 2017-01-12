#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
    int t,c=0;
    cin>>t;
    while(t--){
        c++;
        long long m,e,b,res;
        cin >>b>>e>>m;
        res=1;
        while(e>0){
            if(e&1) 
            res = res*b%m;
            e=e/2;
            b=b%m*b%m;
        }
        cout<<c<<". "<<res<<endl;
   }

	return 0;
}