#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<math.h>
using namespace std;
int ar[101][101];
int val[101][101];
bool visited[101][101];
int main()
{
	int m1[4]={1,0,-1,0};
	int m2[4]={0,1,0,-1};
	int t;
	cin>>t;
	pair<int,int> p;
	queue<pair<int,int> > q;
	while(t--)
	{
		int i,j,a,b,outi,time,outj;
		cin>>a>>b;
		for(i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				val[i][j]=INT_MAX;
				cin>>ar[i][j];
			}
		}
		cin>>outi>>outj>>time;
		q.push(make_pair(0,0));
		val[0][0]=ar[0][0];
		visited[0][0]=1;
		while(!q.empty())
		{
			p=q.front();
			q.pop();
			for(i=0;i<4;i++)
			{
				int x=p.first+m1[i];
				int y=p.second+m2[i];
				if(x>=0 && y>=0 && x<a && y<b &&  (val[x][y]>ar[x][y]+val[p.first][p.second]))
				{
					val[x][y]=ar[x][y]+val[p.first][p.second];
					q.push(make_pair(x,y));
				}
			}
			
		}
		// for(i=0;i<a;i++)
		// {
		// 	for(j=0;j<b;j++)
		// 	cout<<val[i][j]<<" ";
		// 	cout<<endl;
		// }
		if(val[outi-1][outj-1]<time)
		cout<<"YES"<<endl<<time-val[outi-1][outj-1]<<endl;
		else
		cout<<"NO"<<endl;
	}
	
return 0;
}