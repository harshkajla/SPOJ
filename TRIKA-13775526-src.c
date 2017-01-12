#include<stdio.h>
int main()
{
int m,n,a,b,i,j;	
	scanf("%d %d %d %d",&m,&n,&a,&b);
	int ar[m][n];
	int dp[m][n];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&ar[i][j]);
			dp[i][j]=0;
		}
	}
	dp[m-1][n-1]=ar[m-1][n-1];
	for(i=m-2;i>=a-1;i--)
	{
		dp[i][n-1]=dp[i+1][n-1]+ar[i][n-1];
	}
	for(j=n-2;j>=b-1;j--)
	{
		dp[m-1][j]=ar[m-1][j]+dp[m-1][j+1];
	}
	for(i=m-2;i>=a-1;i--)
	{
			for(j=n-2;j>=b-1;j--)
			{
				if(i==a-1 && j==b-1)
				{
				if(dp[i][j+1]<dp[i+1][j])
				dp[i][j]=-dp[i][j+1]+ar[i][j];
				else
				dp[i][j]=-dp[i+1][j]+ar[i][j];
				break;		
				}	
			
			
			if(dp[i][j+1]<dp[i+1][j])
			{
				dp[i][j]=dp[i][j+1]+ar[i][j];
			}
			else
			dp[i][j]=dp[i+1][j]+ar[i][j];
					
			}	
	}
	
if(m==a && n==b)
{
	printf("Y %d\n",0);
	return 0;
}
if(m!=a && n==b)
{
	if(ar[a-1][b-1]-dp[a][b-1]>=0)
	printf("Y %d\n",ar[a-1][b-1]-dp[a][b-1]);
	else
	printf("N\n");
	return 0;
}
if(m==a && n!=b)
{
	if(ar[a-1][b-1]-dp[a-1][b]>=0)
	printf("Y %d\n",ar[a-1][b-1]-dp[a-1][b]);
	else
	printf("N\n");
	return 0;
}

	
	if(dp[a-1][b-1]>=0)
	printf("Y %d\n",dp[a-1][b-1]);
	else
	printf("N\n");
	
	return 0;
}
