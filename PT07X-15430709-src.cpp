#include <bits/stdc++.h>
using namespace std;
int dp[100005][2];
struct Node
{
vector<int> nbr;
} ar[100003];
int path(int curr,int parent,int state)
{
	if(dp[curr][state]!=-1)
	return dp[curr][state];
	int val=0;
	if(state==0)
	{
		for(int j=0;j<ar[curr].nbr.size();j++){
			if(ar[curr].nbr[j]!=parent)
			val+=path(ar[curr].nbr[j],curr,1);
		}
			dp[curr][state]=val;
			return val;
	}
	else 
	{
		val=1;
		for(int j=0;j<ar[curr].nbr.size();j++)
			{if(ar[curr].nbr[j]!=parent)
				val+=fmin(path(ar[curr].nbr[j],curr,1),path(ar[curr].nbr[j],curr,0));}
	dp[curr][state]=val;
		return val;		
	}
	
}
int main() {
	int num,a,b;
	scanf("%d",&num);
	int size=num;
	num--;while(num--) {scanf("%d %d",&a,&b);ar[a].nbr.push_back(b);ar[b].nbr.push_back(a);}
	memset(dp,-1,sizeof(dp));
	

	int ans=path(1,0,1);
	int val=path(1,0,0);
	// for(int i=0;i<ar[1].nbr.size();i++)
	// {
	// 	val+=path(ar[1].nbr[i],1,1);
	// }
cout<<fmin(val,ans);
	return 0;
}