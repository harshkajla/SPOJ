#include <bits/stdc++.h>
using namespace std;
 map<int,long long> mapp;
int dp[20000009];
vector<int> input;
int RecurseSteps(int num)
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
 	return dp[num];
 }
 long long StepsTo1(int num)
 {
 	if(num ==1)
 	return 0;
 	if(mapp[num]) 
 	return mapp[num];
 	long long call= 1+StepsTo1(num-1);
 	if(num%2==0)
 	{
 		call=min(call,1+StepsTo1(num/2));
 	}
 	if(num%3==0){
 		call=min(call,1+StepsTo1(num/3));
 	}
 	mapp[num]=call;
 	return call;
 }
int main() {
	// your code goes here
	int t;
	int cases=0;
	int maxx=1;
	scanf("%d",&t);
	while(t--)
	{
	int n;
	cases++;
	scanf("%d",&n);
	maxx=max(maxx,n);
	input.push_back(n);
	// printf("Case %d: %d\n",cases,RecurseSteps(n));
	}
	RecurseSteps(maxx);
	for(int i=0;i<input.size();i++)
	{
		printf("Case %d: %d\n",i+1,dp[input[i]]);
	}
	return 0;
}