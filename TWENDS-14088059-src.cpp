#include<bits/stdc++.h>
using namespace std;
int ar[1000001];
int dp[1001][1001];
int better(int i,int j,bool player)
{
	if(i==j)
	return ar[i];
	if(dp[i][j])
	return dp[i][j];
	int val;	
	int sum1,sum2,sum3,sum4;
	if(player==true)
	{
	sum1=ar[i]-better(i+1,j,!player);
	sum2=ar[j]-better(i,j-1,!player);
	val= fmax(sum1,sum2);
	
	}
	else
	{
		int sum;
		if(ar[i]>ar[j])
		sum=ar[i]-better(i+1,j,!player);
		else if(ar[i]<ar[j])
		sum=ar[j]-better(i,j-1,!player);
		else
		sum=ar[i]-better(i+1,j,!player);		
			
		val= sum;	
	}
	dp[i][j]=val;
	return val;		
}

int main()
{
	int num,count=0;
	while(scanf("%d",&num)!=EOF)
	{
		count++;
		if(num==0)
		break;
		for(int i=0;i<num;i++)
		scanf("%d",&ar[i]);
		int p=better(0,num-1,true);
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",count,p);
		memset(dp,0,1001*1001*sizeof(int));
	}
	
	return 0;
}