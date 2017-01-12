#include<iostream>
#include<algorithm>
using namespace std;
long long ar[50001];
long long check(int size,long long val,long long persons)
{
	long long i,k,count=0;
	for(i=size-1;i>=0;i--)
	{			
			k=ar[i]/val;
			count+=k;
			if(k==0)
			break;	
	}
	if(persons<=count)
	return 1;
	else
	return 0;
}
long long bs(long long size,long long k)
{
long long low=1;
long long high=ar[size-1]+1;
long long mid;
long long lastmid=-1,max=-1;
while(low<high)
{

mid=(high+low)/2;

if(lastmid==mid)
break;

lastmid=mid;
	if(check(size,mid,k)==1)
	{
	low=mid+1;
	max=mid;
	}
	else
	{
	high=mid;
	}
}	
return max;	
	
}
int main()
{
	long long t,i,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		
		for( i=0;i<n;i++)
		cin>>ar[i];
		
		sort(ar,ar+n);
		long long k1=bs(n,k);
		if(k1!=-1)
		cout<<k1<<endl;
		else
		cout<<"0"<<endl;
	}
	
	
	return 0;
}