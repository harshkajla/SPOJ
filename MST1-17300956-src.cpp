#include <bits/stdc++.h>
using namespace std;
int dp[20000009];
vector<int> input;
void RecurseSteps(int num)
 {
 	dp[1]=0;
 	for(int i=2;i<=num;i++)
 	{
 		dp[i]=1+dp[i-1];
 		if(i%2==0)
 			dp[i]=min(dp[i],1+dp[i/2]);
 		if(i%3==0)
 			dp[i]=min(dp[i],1+dp[i/3]);	
 	}
 }
int main() {
	// your code goes here
	int t;
	int maxx=1;
	scanf("%d",&t);
	while(t--)
	{
	int n;
	scanf("%d",&n);
	maxx=max(maxx,n);
	input.push_back(n);
	}
	RecurseSteps(maxx);
	for(int i=0;i<input.size();i++)
	{
		printf("Case %d: %d\n",i+1,dp[input[i]]);
	}
	return 0;
}