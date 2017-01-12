#include<bits/stdc++.h>
using namespace std;
long long dp[2002][2002];
char S[2002];
char T[2002];
int main() {
    
    int dash;
    scanf("%s",S);
    scanf("%s",T);
    scanf("%d",&dash);
    int slen=strlen(S);
    int tlen=strlen(T);
    for(int i=0;i<=slen;i++)
        dp[i][0]=i*dash;
     for(int j=0;j<=tlen;j++)
        dp[0][j]=j*dash;
    for(int i=1;i<=slen;i++)
    {
        for(int j=1;j<=tlen;j++)
        {
            if(S[i-1] == T[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=min(abs(S[i-1]-T[j-1])+dp[i-1][j-1],dash+min(dp[i-1][j],dp[i][j-1]));
        }
    }
    cout<<dp[slen][tlen];
    // int t;
    // scanf("%d",&t);
    // while(t--)
    // {
    //     scanf("%s",num);
    //     int len=strlen(num);
    //     dp[len]=1;
    //     for(int i=0;i<26;i++)
    //     lastOccurence[i]=-1;
    //     for(int i=len-1;i>=0;i--)
    //     {
    //         if(lastOccurence[num[i]-'A']==-1)
    //             dp[i]=((long long)(2*dp[i+1]))%mod;
    //         else
    //             dp[i]=((long long)(2*dp[i+1]-dp[lastOccurence[num[i]-'A']+1]))%mod;
    //         lastOccurence[num[i]-'A']=i;
    //         if(dp[i]<0)
    //         dp[i]=dp[i]+mod;
    //     }
    //     printf("%d\n",dp[0]);
    // }
    
}