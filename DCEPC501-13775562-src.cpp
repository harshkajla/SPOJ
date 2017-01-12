#include<stdio.h>

long long Max(long long a,long long b)
{
if(a>b)
return a;
else return b;
}
long long Recur(long long arr[],long long dp[],int i,int n)
{

	if(i>=n)
	{
		return 0;
	}
	if(dp[i]!=-1)
	{
		return dp[i];
	}
		
	dp[i]=arr[i]+Recur(arr,dp,i+2,n);
	if(i+1<n)
	{
		dp[i]=Max(dp[i],arr[i]+arr[i+1]+Recur(arr,dp,i+4,n));
	}
	if(i+2<n)
	{
		dp[i]=Max(dp[i],arr[i]+arr[i+1]+arr[i+2]+Recur(arr,dp,i+6,n));
	}
	
	return dp[i];
}
int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		long long arr[n],dp[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
			dp[i]=-1;
		}
		printf("\n%lld\n",Recur(arr,dp,0,n));
	}
	return 0;
}
