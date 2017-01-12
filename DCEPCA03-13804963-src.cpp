#include<iostream>

using namespace std;
int isPrime(int a)
{
	int i;
	if(a==2)
	return 1;
	if(a==1 || a%2==0)
	return 0;
	for(i=2;i*i<=a;i++)
	{
		if(a%i==0)
		return 0;
	}
	return 1;
}

int main()
{
	int t,n,i,j;
	long long H=0,k=0;
	cin>>t;
long long ar[10001];
for(i=0;i<=10000;i++)
		ar[i]=i;
	for(i=2;i<=10000;i++)
		{
			if(isPrime(i)==1)
			{
				for(j=i;j<=10000;j+=i)
				{
					ar[j]-=ar[j]/i;
				}
			}
		}
	while(t--)
	{
		cin>>n;
		
		
		H=0;
		k=0;
		for(i=1;i<=n;i++)
			{
                k=k+ar[i];
			}
			for(i=1;i<=n;i++)
			{
                H=H+k*ar[i];
			}
			cout<<H<<endl;
	}
	return 0;
}