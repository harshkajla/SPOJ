#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[51][51]={0};
char input[51][51];
int maxlen(int i,int j,int a,int b)
{
if(dp[i][j])
return dp[i][j];
int out=0,max=-1;
int dir[2][8]={{1,1,-1,-1,0,0,1,-1},{1,-1,1,-1,1,-1,0,0}};	
for(int p=0;p<8;p++)
{
	int newi,newj;
	newi=i+dir[0][p];
	newj=j+dir[1][p];
	if(newi>=0 && newi<a && newj>=0 && newj<b)
	{
		int t2=input[newi][newj];
		int t1=input[i][j];
		if((t2-t1)==1)
		{
			out=1+maxlen(newi,newj,a,b);
			if(max<out)
			max=out;
		}
	}
}
int returnval=max;
if(max==-1)
returnval=1;
dp[i][j]=returnval;
return returnval;
}
int main()
{
	int a,b,count=0;
	cin>>a>>b;
	while(a!=0 && b!=0)
	{
		count++;
		for(int i=0;i<a;i++)
		scanf("%s",&input[i]);
		
	int max=0,k;
	
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			if(input[i][j]=='A')
			{
			k=maxlen(i,j,a,b);
			if(max<k)
			max=k;
			}
		}
	}	
	cout<<"Case "<<count<<": "<<max<<endl;
	memset(dp,0,51*51*sizeof(int));
	cin>>a>>b;
		
	}
	
}