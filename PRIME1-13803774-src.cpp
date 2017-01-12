#include<iostream>
#include<math.h>
using namespace std;

int isPrime(int a)
{
int i;
if(a==1|| (a%2==0&& a!=2))
return 0;
	for(i=2;i*i<a;i++)
	{
		if(a%i==0)
		return 0;
	}
	
	return 1;
	
}
void PrimeBetweenab(int k,int m)
{
	if(k==1)
	k=2;
	else if(m==1)
	m=2;
	int a,b;
	if(k>m)
	{
		a=m;
		b=k;
	}
	else
	{
	a=k;
	b=m;	
	}
	int n=b-a+1,i;
	int ar[b-a+1];

	for(i=0;i<n;i++)
	ar[i]=1;
	int k1=b;
	int near,count=0;
	for(i=2;i*i<=k1;i++)
	{
		if(isPrime(i))
		{
			near=(a/i);
			near=near*i;
			if(near==0)
			near=near+2*i;
			while(near<=b)
			{
				count++;
				if(i==near && count==1)
				{
					near=near+i;
					continue;
				}
			if(near-a>=0)
			ar[near-a]=0;
			near=near+i;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(ar[i]==1)
		{
			cout<<i+a<<endl;
		}
	}
}

int main()
{
	int a,b,t;
	
	cin>>t;
	while(t--)
	{
	
	cin>>a>>b;
	if(a!=b)
	PrimeBetweenab(a,b);
	else
	{
		if(isPrime(a))
		cout<<a;
	}
	cout<<endl;
	}
	return 0;
}