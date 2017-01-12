#include<iostream>
#include<algorithm>
#include<stdio.h>

#include<algorithm>
using namespace std;

#include<cstdio>
#define gc getchar_unlocked
using namespace std;
void sc( int &x )
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for( ; ((c<48 || c>57) && c != '-'); c = gc() );
    if( c=='-' ) {
        neg=1;
        c=gc();
    }
    for( ;c>47 && c<58; c = gc() ) {
        x = (x << 1) + (x << 3) + c - 48;
    }
    if( neg )
        x=-x;
}

using namespace std;
int psum[16008001];
long long isThere(int size,int sum)
{
	int low=0,i;
	long long count=0;
	int high=size;
	int mid;
	while(low<high)
	{
		mid=(high+low)/2;
		if((psum[mid]==sum && mid==size-1)||(psum[mid]==sum && psum[mid+1]>sum ))
		{
			//high_ans=mid;
			for(i=mid;i>=0;i--)
			{
				if(psum[i]!=sum)
				break;
				count++;
			}
			break;
		}
		else if(psum[mid]>sum)
		{
			high=mid;
		}
		else if(psum[mid]<sum)
		{
			low=mid+1;
		}
	
		else
		{
			low=mid+1;
		}
		
	}
return count;
}
int main()
{
	int t;
	scanf("%d",&t);
	int a[4001],b[4001],c[4001],d[4001];
	int count=0;
	while(t--)
	{
		//sc(a[count]);sc(b[count]);sc(c[count]);sc(d[count]);
		scanf("%d %d %d %d",&a[count],&b[count],&c[count],&d[count]);
		count++;		
	}
	long long ans=0;
	int sum=0;
	int k=0;
	int i,j;
	for(i=0;i<count;i++)
	{
		for(j=0;j<count;j++)
		{
			sum=a[i]+b[j];
				psum[k]=sum;
				k++;
		}
	}
	sort(psum,psum+k);
	ans=0;
	
	for(i=0;i<count;i++)
	{
		for( j=0;j<count;j++)
		{
			sum=c[i]+d[j];
			sum=-sum;
			
			 
				ans=ans+isThere(k,sum);
			
		}
	}
		printf("%lld\n",ans);
	return 0;
}