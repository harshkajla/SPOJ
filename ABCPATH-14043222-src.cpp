#include<cstdio>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
int main()
{
	int r,c,x,y,i,j,q1;
	char s[50][50];
	int a[50][50],visited[50][50];
	int m1[]={-1,0,1,1,1,0,-1,-1};
	int m2[]={-1,-1,-1,0,1,1,1,0};
	int max;
	queue <pair<int,int> > q;
	pair <int,int> p;
	scanf("%d%d",&r,&c);
	q1=1;
	while(r!=0 || c!=0)
	{
		
		max=0;
		memset(a,0,sizeof(a));
		memset(visited,0,sizeof(visited));
		for(i=0;i<r;i++)
			scanf("%s",&s[i]);
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(s[i][j]=='A') 
				{	a[i][j]=1; max=1;
					q.push(make_pair(i,j));
				}
			}
		}
		while(!q.empty())
		{
		p=q.front();
		q.pop();
		for(int i=0;i<=7;i++)
			{
				x=m1[i]+p.first;
				y=m2[i]+p.second;
				if(x>=0 && x<r && y>=0 && y<c && s[x][y]==(1+s[p.first][p.second]))
				{
					if(visited[x][y]==0)
					{
						a[x][y]=(1+a[p.first][p.second]);
						visited[x][y]=1;
						if(max<a[x][y])
						max=a[x][y];
						q.push(make_pair(x,y));
					}
				}
							
			}	
		
		}
		printf("Case %d: %d\n",q1,max);
		scanf("%d%d",&r,&c);
		q1++;
		
		
	}
	
	
	return 0;
}