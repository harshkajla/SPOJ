#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
char num1[2001];
char num2[2001];
int dp[2001][2001];
int editDistance(int i,int j,int len1,int len2)
{
	
	if(dp[i][j]!=0)
	return dp[i][j];
	if(i==len1)
	{
	
	return len2-j;	
	}
	if(j==len2)
	return len1-i;
	
	if(num1[i]==num2[j]){
	
		int q=fmin(1+editDistance( i+1,j,len1,len2),fmin(editDistance(i+1,j+1,len1,len2),1+editDistance(i,j+1,len1,len2)));
		dp[i][j]=q;
		return q;
		}
	else{
	
		int s=fmin(1+editDistance( i+1,j,len1,len2),fmin(1+editDistance(i+1,j+1,len1,len2),1+editDistance(i,j+1,len1,len2)));
		dp[i][j]=s;
		return s;
	}
	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%s",&num1);
		scanf("%s",&num2);
		
		int len1=strlen(num1);
		int len2=strlen(num2);
		cout<<editDistance(0,0,len1,len2)<<endl;
		memset(dp, 0, 2001*2001*sizeof dp[0][0]);
	}
	
	return 0;
}