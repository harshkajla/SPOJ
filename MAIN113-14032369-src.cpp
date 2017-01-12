#include<iostream>
#include<math.h>
using namespace std;
long long dp[32];
void pre()
{
	int i=0;
	dp[0]=0;
	dp[1]=3;
	dp[2]=9;
	for(i=3;i<31;i++)
	{
		dp[i]=2*dp[i-1]+dp[i-2];
	}
}
int main()
{
	long long t,num;
	pre();
	cin>>t;
	while(t--)
	{
		cin>>num;
		
		cout<<dp[num]<<endl;
	}
	
}