#include<bits/stdc++.h>
using namespace std;

int dp[10][10];
int dirx[8]={1,1,-1,-1,2,2,-2,-2};
int diry[8]={2,-2,2,-2,-1,1,1,-1};

int isValid(int x,int y,int rows,int cols)
{
    if(x>=0 && y>=0 && x<rows && y<cols)
        return 1;
    else
        return 0;
}
int BFS(int start_x,int start_y , int end_x,int end_y)
{
    queue<pair<int,int>>Q;
    Q.push(make_pair(start_x,start_y));
    dp[start_x][start_y]=0;
    while(!Q.empty()){
        
        pair<int,int> front=Q.front();
        Q.pop();
        // if(front.first==end_x && front.second==end_y)
        // return dp[end_x][end_y];
        for(int i=0;i<8;i++)
        {
            int newx=front.first + dirx[i];
            int newy=front.second+ diry[i];
            if(isValid(newx,newy,8,8) && (dp[newx][newy]> (newx*front.first+newy*front.second+dp[front.first][front.second])))
            {
                dp[newx][newy]= newx*front.first+newy*front.second+dp[front.first][front.second];
                Q.push(make_pair(newx,newy));
            }
        }
    }
    return dp[end_x][end_y]==INT_MAX?-1:dp[end_x][end_y];
}

int main() {
    
    int t,a,b,c,d;
    
    while(scanf("%d",&a)!=EOF)
    {
        scanf("%d %d %d",&b,&c,&d);
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                dp[i][j]=INT_MAX;
        printf("%d\n",BFS(a,b,c,d));
    }
    
}