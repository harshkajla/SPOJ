#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX 1000001
int ar[MAX];
int main()
{
	
	ar[1]=1;
	int i,j,t,n;

	
	for(i=2;i<=MAX;i++)
			{
			if(!ar[i])
				{
				ar[i]=i-1;	
				for(j=i*2;j<=MAX;j+=i)
					{
					if(!ar[j])
					ar[j]=j;
					
					ar[j]-=ar[j]/i;
					}
				}
			}	
		cin>>t;
	while(t--)
	{
	scanf("%d",&n);
	printf("%d\n",ar[n]);
		
	}
	
	
	return 0;
}