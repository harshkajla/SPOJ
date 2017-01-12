#include<bits/stdc++.h>
using namespace std;
int dp[6102][6102];
char str[6102];
int main() {
    
    int t;
    scanf("%d",&t);
    while(t--){
    scanf("%s",str);
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        dp[i][i]=0;
        dp[i][i+1]= i<len-1 && str[i]==str[i+1]?0:1;
    }
    for(int i=len-1;i>=0;i--)
    {
        for(int j=i+2;j<len;j++)
        {
            if(str[i]==str[j])
                dp[i][j]=dp[i+1][j-1];
            else
            {
                dp[i][j]=1+min(dp[i][j-1],dp[i+1][j]);
            }
            // cout<<dp[i][j]<<" ->";
        }
    }
    printf("%d\n",dp[0][len-1]);
    }
}