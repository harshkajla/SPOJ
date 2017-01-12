#include<bits/stdc++.h>
using namespace std;
pair<int,int> cols[11];

int dirx[8]={1,2,1,2,-1,-2,-1,-2};
int diry[8]={2,1,-2,-1,2,1,-2,-1};

int visited[11][11];
int dp[11][11];
int isValid(int x,int y,int rows)
{
    if(cols[x].first<=y && cols[x].second>=y && x>=0 && x<rows )
    return 1;
    return 0;
}
int MaxPathDFS(int x,int y,int rows)
{
    int newx,newy;
    int ans=1;
    for(int i=0;i<8;i++)
    {
        newx=x+dirx[i];
        newy=y+diry[i];
        if(isValid(newx,newy,rows))
        {
            if(!visited[newx][newy]){    
                visited[newx][newy]=1;    
                ans= max(ans,1+MaxPathDFS(newx,newy,rows));
            }
        }
    }
    visited[x][y]=0;
    dp[x][y]=ans;
    return ans;
}
int NotVisit(int rows)
{
 visited[0][0]=1;    
 int total=0;
 for(int i=0;i<rows;i++)
 total+=cols[i].second-cols[i].first+1;
 return total-MaxPathDFS(0,cols[0].first,rows);  
}

int main()
{
    int rows,cases=1;
    scanf("%d",&rows);
    while(rows)
    {
            for(int i=0;i<rows;i++){
            scanf("%d %d",&cols[i].first,&cols[i].second);
            cols[i].second+=cols[i].first-1;}
            int ans=NotVisit(rows);
            if(ans>1 || ans<1)
            printf("Case %d, %d squares can not be reached.\n",cases,ans);
            else
            printf("Case %d, %d square can not be reached.\n",cases,ans);
            cases++;
            for(int i=0;i<11;i++)
            for(int j=0;j<11;j++)
            visited[i][j]=0,dp[i][j]=0;
            scanf("%d",&rows);
    }
    
}