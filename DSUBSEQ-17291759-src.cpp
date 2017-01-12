#include<bits/stdc++.h>
using namespace std;
int dp[1000005];
int lastOccurence[26];
char num[1000005];
int mod=1000000007;
int main() {
    
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",num);
        int len=strlen(num);
        dp[len]=1;
        for(int i=0;i<26;i++)
        lastOccurence[i]=-1;
        for(int i=len-1;i>=0;i--)
        {
            if(lastOccurence[num[i]-'A']==-1)
                dp[i]=((long long)(2*dp[i+1]))%mod;
            else
                dp[i]=((long long)(2*dp[i+1]-dp[lastOccurence[num[i]-'A']+1]))%mod;
            lastOccurence[num[i]-'A']=i;
            if(dp[i]<0)
            dp[i]=dp[i]+mod;
        }
        printf("%d\n",dp[0]);
    }
    
}