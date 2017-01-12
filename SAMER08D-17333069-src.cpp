#include<bits/stdc++.h>
using namespace std;
int dp[1009][1009];
char S[1009];
char T[1009];
int checks[1009][1009];
int slen,tlen;
void FillCheck()
{
    for(int i=0;i<=slen;i++)
    {
        for(int j=0;j<=tlen;j++)
        {
            if(i==0 || j==0)
                checks[i][j]=0;
            else if(S[i-1]==T[j-1])
                checks[i][j]=1+checks[i-1][j-1];
            else
                checks[i][j]=0;
        }
    }
}
int main() {

    int k;
    scanf("%d",&k);
    while(k){
    scanf("%s",S);
    scanf("%s",T);
    slen=strlen(S);
    tlen=strlen(T);
    
    FillCheck();
    for(int i=0;i<=slen;i++)
    {
        for(int j=0;j<=tlen;j++)
        {
            
            if(i>=k && j>=k)
            {
               dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                int back=checks[i][j];
                if(back>=k){
                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    for(int z=k;z<=back;z++)
                        dp[i][j]=max(dp[i][j],z+dp[i-z][j-z]);
                }
            }
            else
                dp[i][j]=0;
        }
    }
    printf("%d\n",dp[slen][tlen]);
    scanf("%d",&k);
    }
return 0;
}