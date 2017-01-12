#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX 1000001

int ar[MAX];
long long gn[MAX];


int main()
{
	int n;
	int i=0,j;

		for(i=2;i<MAX;i++)
			{
			if(!ar[i])
				{
				ar[i]=i-1;	
				for(j=2*i;j<MAX;j+=i)
					{
					if(!ar[j])
					ar[j]=j;
					
					ar[j]-=ar[j]/i;
					}
				}
			}	

	
	for(i=1; i<MAX; i++)
		for(j=2; i*j<MAX; j++)
			gn[i*j] += i*ar[j];	
		
		for(i=2;i<MAX;i++)
			gn[i]+=gn[i-1];
			
	while(scanf("%d", &n)==1 && n)
		printf("%lld\n", gn[n]);
	
	return 0;
}