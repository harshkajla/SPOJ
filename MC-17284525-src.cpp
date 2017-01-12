#include<bits/stdc++.h>
using namespace std;
int dp[1002][1002];
char S[1002];
char T[1002];
int main() {
    
    // int t;
    scanf("%s",S);
    while(S[0]!='#'){
    scanf("%s",T);
    int slen=strlen(S);
    int tlen=strlen(T);
    for(int i=0;i<=slen;i++)
    {
        dp[i][0]=i*15;
    }
    for(int j=1;j<=tlen;j++)
        dp[0][j]=j*30;
    for(int i=1;i<=slen;i++)
    {
        for(int j=1;j<=tlen;j++)
        {
            if(S[i-1]==T[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
            {
                dp[i][j]=min(30+dp[i][j-1],15+dp[i-1][j]);
            }
            
        }
    }
    printf("%d\n",dp[slen][tlen]);
    scanf("%s",S);
    }
}