#include<iostream>
#include<algorithm>
using namespace std;
#include<cstdio>
#define gc getchar_unlocked
using namespace std;
void scanint( long long &x )
{
register long long c = gc();
x = 0;
long long neg = 0;
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


long long arr[10000001];
long long check(long long a[],long long n,long long len,long long sumform)
{
	long long i,count,sum=0;
	for(i=0;i<n;i++)
	{
		if(a[i]>len)
		sum=sum+(a[i]-len);
	}
	return sum;
}
int main()
{
	long long count=0,max=-1,a,b,low,high,mid;
	cin>>a>>b;
	
	while(count!=a)
	{
	scanint(arr[count++]);
	if(max<arr[count-1])
	max=arr[count-1];
	}
	
	low=0;
	high=max;
	long long bk=-1,last=-1;
	while(low<high)
	{
		mid=(low+high)/2;
		
		if(bk==mid)
		break;
		long long p=check(arr,a,mid,b);
		 if(p==b)
			{
				last=mid;
				break;
			}
		else if(p>b)
			{
			low=mid+1;
			last=mid;
			}
		else
			high=mid;
		
		bk=mid;
	}	
	cout<<last<<endl;
	return 0;
}