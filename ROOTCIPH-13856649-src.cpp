#include<iostream>
#include<stdio.h>
using namespace std;
int main(){

long long b,c,d,t;
	cin>>t;
	while(t--)
	{
		scanf("%lld%lld%lld",&b,&c,&d);
		cout<<(b*b)-2*c<<endl;
	}
	
	
	
	return 0;
}