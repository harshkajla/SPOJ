#include<bits/stdc++.h>
using namespace std;
char ar[201];
int dp[201][201];
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
		cout<<rock(0,len-1)<<endl;
		memset(dp,0,201*201*sizeof(int));
	}
	
	return 0;
}