#include<bits/stdc++.h>
using namespace std;
int ar[502][502];
int dp[502][502];

int main()
{
    int t,m,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&m,&n);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&ar[i][j]);
        dp[m-1][n-1]=1;
    for(int i=m-2;i>=0;i--)
    {
    int need=dp[i][n-1]=dp[i+1][n-1]-ar[i][n-1];
            dp[i][n-1]= need>0 ?need:1; 
    }
    for(int i=n-2;i>=0;i--)
    {
        int need=dp[m-1][i]=dp[m-1][i+1]-ar[m-1][i];
            dp[m-1][i]= need>0 ?need:1; 
    }
    //base case
    for(int i=m-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            int need=min(dp[i+1][j],dp[i][j+1])-ar[i][j];
            dp[i][j]= need>0 ?need:1; 
        }
    }        
          printf("%d\n",dp[0][0]);
    }
    
}