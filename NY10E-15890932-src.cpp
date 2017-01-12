#include <bits/stdc++.h>
using namespace std;
long long dp[10];
long long NON(long long num)
{
	if(num==1)
	return 10;
	for(int i=0;i<=9;i++)
	dp[i]=1;
	long long sum=1;
	num--;
	while(num--)
	{
		sum=1;
		for(int i=8;i>=0;i--)
		{
			dp[i]=dp[i]+dp[i+1];
			sum+=dp[i];
		}
	}
	return sum;
}
int main() {
	// your code goes here
	// long long t,a,b;
	// cin >>t;
	// while(t--)
	// {
	// 	cin>>a>>b;
	// 	cout<<a<<" "<<NON(b)<<endl;
	// }
	int t=0,i,count=1,a,b;
	cin>>t;
	while(t+1!=count)
	{
		cin>>a;
		cin>>b;
		cout<<a<<" "<<NON(b)<<endl;
		count++;
	}
	return 0;
}