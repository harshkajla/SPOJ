#include<cstdio>
#include<iostream>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<math.h>
using namespace std;
char ar[1001][1001];
long long aux[1001][1001];
long long val[1001][1001];
int main()
{
	
	int i,n;
	cin>>n;
	long long mod=pow(2,31)-1;
	int flag=1,flag2=1;
	for(i=0;i<n;i++)
		{
		cin>>ar[i];
			if(ar[0][i]!='#' && flag==1)
			val[0][i]=1;
			else{
			val[0][i]=0;
			flag=0;
			}
			if(ar[i][0]!='#' && flag2==1)
			val[i][0]=1;
			else{
			val[i][0]=0;
			flag2=0;
			}
			for(int j=0;j<n;j++)
			{
			aux[i][j]=0;
			}
		}
for(i=1;i<n;i++)
{
	for(int j=1;j<n;j++)
	{
		if(ar[i][j]=='.')
		{
			val[i][j]=(val[i][j-1]+val[i-1][j])%mod;
		}
	}
}


	int m1[4]={1,0,-1,0};
	int m2[4]={0,1,0,-1};
				
		if(val[n-1][n-1]!=0 )
			cout<<val[n-1][n-1];
		else
		{
			pair<int,int> p;
			queue<pair<int,int> > q;
			q.push(make_pair(0,0));
			while(!q.empty())
			{
			p=q.front();
			q.pop();
		
			for(i=0;i<4;i++)
			{
				long long x=p.first+m1[i],y=p.second+m2[i];
				if(x>=0 && x<n && y>=0 && y<n && ar[x][y]!='#')
				{
				aux[x][y]++;
				ar[x][y]='#';
				if(x==n-1 && y==n-1)
				{
					cout<<"THE GAME IS A LIE"<<endl;
					return 0;
				}
				q.push(make_pair(x,y));
				}
				}
			}
			if(aux[n-1][n-1]!=0)
				cout<<"THE GAME IS A LIE"<<endl;
			else
			cout<<"INCONCEIVABLE"<<endl;
		}
		
return 0;
}