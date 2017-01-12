#include<bits/stdc++.h>
using namespace std;
char arr[1001][1001];
int visited[1001][1001];
int dp[1001][1001];
int dirx[4]={1,0,-1,0};
int diry[4]={0,1,0,-1};
int mod=2147483647;
int isValid(int x,int y,int n)
{
    if(x>=0 && y>=0 && x<n && y<n && !visited[x][y] && arr[x][y]=='.')
    return 1;
    else
    return 0;
}
int bfs(int n)
{
    queue<pair<int,int>>Q;
    Q.push(make_pair(0,0));
    visited[0][0]=1;
    int isReachable=0;
    while(!Q.empty())
    {
        pair<int,int> front=Q.front();
        Q.pop();
        if(front.first == n-1 &&front.second==n-1)
        isReachable=1;
        for(int i=0;i<4;i++)
        {
            int newx=front.first+dirx[i];
            int newy=front.second+diry[i];
            if(isValid(newx,newy,n))
            {
                Q.push(make_pair(newx,newy));
                visited[newx][newy]=1;
            }
        }
    }
    return isReachable;
}
int DPAnswer(int n)
{
    if(n==1)
    return 1;
 dp[0][0]= arr[0][0]=='.'?1:0;
 for(int i=1;i<n;i++)
 {
     if(!dp[i-1][0])
     dp[i][0]=0;
     else
     dp[i][0]=arr[i][0]=='.'?1:0;
 }
 for(int i=1;i<n;i++)
 {
     if(!dp[0][i-1])
     dp[0][i]=0;
     else
     dp[0][i]=arr[0][i]=='.'?1:0;
 }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++){
        long long paths=((long long)dp[i-1][j]+(long long)(dp[i][j-1]))%mod;
        dp[i][j] = arr[i][j]=='.'? paths:0;   
        }
    }
    return dp[n-1][n-1];
}

int main()
{
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    scanf("%s",arr[i]);
    int dpans=DPAnswer(num);
    if(dpans)
    printf("%d",dpans);
    else if(!dpans)
    {
        int bfans=bfs(num);
        if(bfans)
        printf("THE GAME IS A LIE");
        else
        printf("INCONCEIVABLE");
    }
    
}