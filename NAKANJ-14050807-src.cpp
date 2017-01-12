#include<bits/stdc++.h>
using namespace std;
int arr1[] ={-2,-2,-1,-1,1,1,2,2};
int arr2[] ={-1,1,-2,2,-2,2,-1,1};
int visited[8][8];
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
			val[m][n]=100000;
		}
	}
	q.push(make_pair(i,j));
	visited[i][j]=1;
	val[i][j]=0;
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		for(k=0;k<8;k++)
		{
			int x=p.first+arr1[k];
			int y=p.second+arr2[k];
			if(x>=0 && x<8 && y>=0 && y<8  && val[x][y]>1+val[p.first][p.second])
			{
					q.push(make_pair(x,y));
					val[x][y]=1+val[p.first][p.second];					
			}
		}
	}
 
 
	return val[i2][j2];
}
int main() {
  char s[3], t[3];
  int n;
 
  scanf( "%d", &n );
  while ( n-- ) {
 	memset(val,100000,8*8*sizeof(int));
    memset(visited,0,8*sizeof(int));
    scanf("%s %s", &s, &t );
    printf("%d\n", minmove(s[0]-'a',s[1] - '1',t[0]-'a', t[1] - '1'));
 
 
  }
 
  return 0;
}