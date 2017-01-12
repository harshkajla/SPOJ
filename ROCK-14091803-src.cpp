#include<bits/stdc++.h>
using namespace std;
char ar[201];
int dp[201][201];
int rockdp(int len)
{
	for(int i=0;i<len;i++)
	{
		if(ar[i]=='1')
		dp[i][i]=1;
		else
		dp[i][i]=0;
	}
	int i,j,max,out,count,t;
	for(i=len-1;i>=0;i--)
	{
		for(j=i+1;j<len;j++)
		{
			count=0;
			out=0;
			max=-1;
				
			for(t=i;t<=j;t++)
				{
				count=0;
				for(int p=t;p<=j;p++)
				{
					if(ar[p]=='1')
					count++;
					if(count>((p-t+1)/2))
					{
					out=p-t+1+dp[p+1][j];
					}
					if(out>max)
					max=out;
				}
				}	
			dp[i][j]=max;
			
		}
		
	}

	return dp[0][len-1];
}
int rock(int i,int j)
{
	int val=0,out=0,t;
	if(dp[i][j])
	return dp[i][j];
	int max=0,count=0;
	for(t=i;t<=j;t++)
		{
		count=0;
		for(int p=t;p<=j;p++)
		{
			if(ar[p]=='1')
				count++;
			if(count>((p-t+1)/2))
			{
			out=p-t+1+rock(p+1,j);
			}
		if(out>max)
		max=out;
		}
	}	
	dp[i][j]=max;
	return max;	
}
int main()
{
	int t,i,j,p,len;
	cin>>t;
	while(t--)
	{
		int num;
		cin>>num;
		cin>>ar;
		len=num;
		cout<<rockdp(len)<<endl;
		memset(dp,0,201*201*sizeof(int));
	}
	
	return 0;
}