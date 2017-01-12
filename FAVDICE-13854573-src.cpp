#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,i,num;
	double ans=0.0;
	cin>>t;
	while(t--)
	{
		ans=0;
		
		cin>>num;
		if(num!=1)
		for(i=1;i<=num;i++)
		{
			ans+=(double)num/(num-i+1);
		}
		else
		ans=1.0;
		printf("%0.2f\n",ans);
	}
	
	return 0;
}