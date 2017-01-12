#include<iostream>
#include<stdio.h>
#include<string.h>
#define MAX 10000001
#define MAXPRIME 664580
int primes[MAXPRIME];
int pr[MAX];

void sieve()
{
	int i;
	
	int k=1;
	for(i=2;i*i<=MAX;i++)
	{
		if(!pr[i]){
				primes[k]=i;
				
				pr[i]=0;
			for(int j=2*i;j<MAX;j+=i)
				{
				if(!pr[j])
				pr[j]=k;
				}
				k++;
		}
			}
	
	
}
void PrimeFactor(int n)
{
	if(n==1)
	{
	printf("1");
	return ;
	}
	printf("1");
	int k,i;
	int p=pr[n];
	if(p==0)
	{
		printf(" x %d",n);
		return;
	}
	for(i=p;primes[i]*primes[i]<=n && primes[i]!=0 ;i++)
	{
		if(n % primes[i]==0){
		 k=primes[i];
		while(n%k==0)
		{
			n=n/k;
			printf(" x %d",k);
		}		
			}
	}
	if(n>1)
		printf(" x %d",n);	
}
int main()
{
	int num;
	sieve();
	while(scanf("%d",&num) != EOF) 
	{ 
		PrimeFactor(num);
		printf("\n");
	}
	
	
	return 0;
}