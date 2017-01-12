#include<iostream>
#include<math.h>
#include<limits.h>
#include<stdio.h>
using namespace std;
int sum[105][105];
int dp[105][105];
int arr[105];
int matrixchain(int n)
{	
	for(int i=1;i<=n;i++)
	{		
	dp[i][i]=arr[i-1];
	sum[i][i]=0;
	}
	
	int i=0,j=0,k;
	
	int max;
	int a=-1;
	int b=-1;
	int p=-1;
	for(i=n;i>=1;i--)
	{
		for(j=i+1;j<=n;j++)
		{
			int min=INT_MAX,q;
			for(k=i;k<j;k++)
			{				 
				q=(dp[i][k]*dp[k+1][j])+sum[i][k]+sum[k+1][j];
				if(q<min)
					{				
					min=q;
					a=dp[i][k];
					b=dp[k+1][j];
					p=k;
					}
			
			}
			//sum=sum+min;
		
			sum[i][j]=min;
			p=-1;
			dp[i][j]=(a+b)%100;					
		}
	}

	return sum[1][n];

}
int main()
{
	int n,k,i;
	while( scanf("%d",&n) > 0 ) {
	
	
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		cout<<matrixchain(n)<<endl;
	}
	return 0;
}