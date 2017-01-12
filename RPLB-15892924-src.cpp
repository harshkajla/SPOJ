#include <bits/stdc++.h>
using namespace std;
int ar[1005];
int dp[1005][1005];
int Pick(int i,int size,int limit,int sum)
{
	if(i>=size)
	return sum;
	if(dp[i][sum]!=-1)
	return dp[i][sum];
	if(sum+ar[i]<=limit)
	{
		dp[i][sum]=fmax(Pick(i+2,size,limit,sum+ar[i]),Pick(i+1,size,limit,sum));
		return dp[i][sum];
	}
	else
	{
		dp[i][sum]=Pick(i+1,size,limit,sum);
		return dp[i][sum];
	}
	
}
int main() {
	int t;
	cin>>t;
	int a,b;
	int scenario=1;
	int max2=0;
	
	while(t--)
	{
		memset(dp,-1,sizeof dp);
		max2=0;
		cin>>a>>b;
		//b is limit
		for(int i=0;i<a;i++)
			cin>>ar[i];
			
	printf("Scenario #%d: %d\n",scenario,Pick(0,a,b,0));    
        scenario++;		
	}		
	return 0;
}