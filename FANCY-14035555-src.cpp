#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;
char num[32];
int dp[32];
int main()
{
int t,i,j;
scanf("%d",&t);
	while(t--)
		{
			scanf("%s",&num);
			int len=strlen(num);
			dp[len-1]=1;
			
		
			for(i=len-2;i>=0;i--)
			{
				if(num[i]==num[i+1])
				{
					dp[i]=2*dp[i+1];
				}
				
				else
				dp[i]=dp[i+1];
			}
//			for(i=0;i<len;i++)
//			cout<<dp[i]<<" ";
			
			cout<<dp[0]<<endl;
		}
	}