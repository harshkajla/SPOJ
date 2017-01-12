#include<bits/stdc++.h>
using namespace std;
int dp[5001][5001];
int main()
{
	int i,len,j;
	scanf("%d",&len);
	char ar[len];
	scanf("%s",&ar);
	
	
	for(i=0;i<len;i++)
		for(j=0;j<len;j++)
			dp[i][j]=0;
	
	for(i=len-2;i>=0;i--)
	{
		for(j=i+1;j<len;j++)
		{
		
			if(ar[i]==ar[j])
			{
			dp[i][j]=dp[i+1][j-1];	
			}
			else
			dp[i][j]=1+fmin(dp[i+1][j],dp[i][j-1]);
			
		}
	}
	printf("%d\n",dp[0][len-1]);
	
	return 0;
}