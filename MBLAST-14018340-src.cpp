#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
char num1[2001];
char num2[2001];
int dp[2001][2001];
int hifun;	
int editDistance(int i,int j,int len1,int len2)
{		
	
	if(dp[i][j]!=0)
	return dp[i][j];
	if(i==len1)
	return (len2-j)*hifun;	
	if(j==len2)
	return (len1-i)*hifun;

	int k=num1[i]-num2[j];
	if(k<0)
	k=-k;
	dp[i][j]=fmin(hifun+editDistance( i+1,j,len1,len2),fmin(k+editDistance(i+1,j+1,len1,len2),hifun+editDistance(i,j+1,len1,len2)));

	return dp[i][j];
	
}
int editDistance2(int len1,int len2)
{
	int i,j,k;
	for(i=0;i<=len1;i++)
	dp[i][0]=i*hifun;
	for(i=0;i<=len2;i++)
	dp[0][i]=i*hifun;
	
	for(i=1;i<=len1;i++)
	{
		for(j=1;j<=len2;j++)
		{
			k=num1[i-1]-num2[j-1];
			if(k<0) k=-k;
			dp[i][j]=fmin(hifun+dp[i-1][j],fmin(k+dp[i-1][j-1],hifun+dp[i][j-1]));
		}
	}
	return dp[len1][len2];
}
int main()
{
	scanf("%s",&num1);
	scanf("%s",&num2);
	scanf("%d",&hifun);
	
	
		int len1=strlen(num1);
		int len2=strlen(num2);
		
		printf("%d\n",editDistance2(len1,len2));

		
	
	
	return 0;
}