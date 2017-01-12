#include<bits/stdc++.h>
using namespace std;
int arr1[] ={-2,-2,-1,-1,1,1,2,2};
int arr2[] ={-1,1,-2,2,-2,2,-1,1};
//int visited[8][8];
int val[8][8];
int minmove(int i,int j,int i2,int j2)
{
	pair<int,int>p;
	queue <pair<int,int> > q;
	int k;
	for(int m=0;m<8;m++)
	{
		for(int n=0;n<8;n++)
		{
			val[m][n]=INT_MAX;
		}
	}
	q.push(make_pair(i,j));
	//visited[i][j]=1;
	val[i][j]=0;
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		for(k=0;k<8;k++)
		{
			int x=p.first+arr1[k];
			int y=p.second+arr2[k];
			if(x>=0 && x<8 && y>=0 && y<8  && val[x][y]>x*p.first+y*p.second+val[p.first][p.second])
			{
					q.push(make_pair(x,y));
					val[x][y]=x*p.first+y*p.second+val[p.first][p.second];					
			}
		}
	}
 
 
	return val[i2][j2];
}
int main() {
  char s[3], t[3];
  int n,a,b,c,d;

  while (scanf("%d %d %d %d",&a,&b,&c,&d)!=EOF) {

    //cin>>a>>b>>c>>d;
    if(minmove(a,b,c,d)!=INT_MAX)
    printf("%d\n", minmove(a,b,c,d));
    else
    printf("-1\n");
 
  }
 
  return 0;
}