#include<iostream>
using namespace std;
long long power(long long b,long long exp,long long m)
{
	if(exp==0)
	return 1;
	if(exp==1)
	return b%m;
	long long p=-1;
	if(exp%2==0)
	{
		
		 p=power(b,exp/2,m);
		 return p%m*p%m;
	}
	else
	{
	p=power(b,exp/2,m);
	return p%m*p%m*b%m;	
	}
}
int main(){
    int t,c=0;
    cin>>t;
    while(t--){
        c++;
        long long m,e,b,out;
        cin >>b>>e>>m;
        
        cout<<c<<". "<<power(b,e,m)<<endl;
   }

	return 0;
}


