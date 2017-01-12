#include<bits/stdc++.h>
using namespace std;

char ar[51][51];
int dp[51][51];
int dirx[8]={0,0,-1,1,1,1,-1,-1};
int diry[8]={-1,1,0,0,-1,1,1,-1};

int isValid(int x,int y,int rows,int cols)
{
    if(x>=0 && y>=0 && x<rows && y<cols)
        return 1;
    else
        return 0;
}
int dfs(int x, int y,int rows,int cols)
{
    char curr=ar[x][y];
    if(dp[x][y]!=-1)
    return dp[x][y];
    int ans=1;
    for(int i=0;i<8;i++)
    {
        int newx= x+dirx[i];
        int newy= y+diry[i];
        if(isValid(newx,newy,rows,cols) && ar[newx][newy]==(int)(curr+1))
            ans=max(ans,1+dfs(newx,newy,rows,cols));
    }
    dp[x][y]=ans;
    return ans;
    
}
int MaxLength(int rows,int cols){
    int maxx=0;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
            if(ar[i][j]=='A')   
                maxx=max(dfs(i,j,rows,cols),maxx);
    }
    return maxx;
}
int main() {
    
    int a,b,count=1;
    scanf("%d %d",&a,&b);
    
    while(a!=0 && b!=0)
    {
        for(int i=0;i<=a;i++)
        for(int j=0;j<=b;j++)
        dp[i][j]=-1;
        for(int i=0;i<a;i++)
        scanf("%s",ar[i]);
        
        printf("Case %d: %d\n",count,MaxLength(a,b));
        
        scanf("%d %d",&a,&b);
        
        count++;
    }
    
    
    
}