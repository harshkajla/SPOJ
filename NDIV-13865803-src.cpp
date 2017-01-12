#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX 34105
bool m[MAX+1];
int m1[MAX+1];
void pre()
{
	int i,t,k=1,j,num;
		m1[0]=0;m1[1]=2;
			for(i=3;i*i<=MAX;i+=2)
			{
				if(!m[i])
				{
					for(j=i*i;j<=MAX;j+=2*i)
					{
					m[j]=1;
					}
				}
			}
	m1[0]=2;
	k=1;
		for(i=3;i<=MAX;i++)
		{
			if(m[i]==0 && i%2!=0)
				{
					m1[k]=i;
					k++;
				}			
		}		
}
long long Prime(long long  a)
{

long long k,i,pro=1;
int count=0;

for(int i=0;m1[i]*m1[i]<=a;i++)
{
		 count=0;
		 k=m1[i];
		 while(a%k==0)
		 {
		 a=a/k;
		count++;
		}
		pro=pro*(count+1);
}
if(a>1)
pro=pro*2;
return pro;

}
int main()
{
	long long num,a,b,count=0;
	pre();
//	while(scanf("%lld",&num) != EOF)
//	{
cin>>a>>b>>num;
	for(long long i=a;i<=b;i++)
	{
		if(Prime(i)==num)
		{
			count++;
		}
	}
	cout<<count;
	
	
	
	return 0;
}