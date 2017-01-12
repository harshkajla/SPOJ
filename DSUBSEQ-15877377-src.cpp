#include <bits/stdc++.h>
using namespace std;
long long  dp[100005];
int distinctseq(string s)
{
	int mod=1000000007;
	dp[s.length()]=1;
	map<char,int> m;
	for(int i=s.length()-1;i>=0;i--)
	{
		if(!m[s[i]])
			 dp[i]=2*dp[i+1];
		else
			dp[i]=2*dp[i+1]-dp[m[s[i]]];
		dp[i]=(dp[i]+mod)%mod;	
		m[s[i]]=i+1;
	}
	return dp[0];
}
int main() {
	// your code goes here
	int t;
	string k;
	cin>>t;
	while(t--)
	{
		cin>>k;
		cout<<distinctseq(k)<<endl;
	}
	return 0;
}