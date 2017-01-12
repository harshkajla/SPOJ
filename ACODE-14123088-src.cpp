#include<bits/stdc++.h>
using namespace std;
char num[5001];
int dp[5002];
int main()
{
	while(scanf("%s",&num)!=EOF)
	{
		if(num[0]=='0')
		break;
		int len=strlen(num);
		if(num[len-1]!='0')
		{
			dp[len-1]=1;
			dp[len]=1;
		}
		else
		{
			dp[len]=1;
			dp[len-1]=0;
		}
		for(int i=len-2;i>=0;i--)
		{
			int n1=num[i]-'0';
			int n2=num[i+1]-'0';
			int out=n1*10+n2;
			if(n1!=0)
			{
				if(out%10==0)
				{					
					dp[i]=dp[i+2];
				}
				else
				{
					if(out<=26)
					{
						dp[i]=dp[i+1]+dp[i+2];
					}
					else
					{
						dp[i]=dp[i+1];
					}
				}
			}
			else
			{
				dp[i]=0;
			}
		}
		cout<<dp[0]<<endl;
	}
	return 0;
}