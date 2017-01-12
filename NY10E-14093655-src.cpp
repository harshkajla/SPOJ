#include<bits/stdc++.h>
using namespace std;
long long summation(long long num)
{
	if(num==0)
	return 0;
	long long ar[10],out=0,i;
	for( i=0;i<10;i++)
	{
	ar[i]=1;
	out+=ar[i];
	}
	num--;
	
	while(num!=0)
	{
	out=ar[0];
	for(i=1;i<10;i++)
		{
		ar[i]+=ar[i-1];
		if(num==1)
		out+=ar[i];
		}	
		num--;
	}

	return out;
}
int main()
{
	long long t,a,num;
	cin>>t;
	while(t--)
	{
		cin>>a>>num;
		cout<<a<<" "<<summation(num)<<endl;
	}
	
	return 0;
}