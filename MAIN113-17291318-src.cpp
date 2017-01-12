#include<bits/stdc++.h>
using namespace std;
long long dp[3][3][32];
long long Combinations_Helper(int fs,int sec,int num)
{
    if(num<2)
        return 0;
    if(num==2)
        return 1;
    if(dp[fs][sec][num])
    return dp[fs][sec][num];
    long long ans=0;
    if(fs==sec)
        ans+=Combinations_Helper(0,fs,num-1) + Combinations_Helper(1,fs,num-1)+Combinations_Helper(2,fs,num-1);
    else
        ans+=Combinations_Helper(fs,fs,num-1)+Combinations_Helper(sec,fs,num-1);
    dp[fs][sec][num]=ans;
    return ans;
}
long long Combinations(int num)
{
    long long ans=0;
    if(num == 1)
    return 3;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            ans+=Combinations_Helper(i,j,num);
        }
    }
    return ans;
}
int main() {
    
    int t;
    cin>>t;
    int num;
    while(t--) {
    cin>>num;
    // dp[x][0]=dp[y][0]=dp[z][0]=1;
    // dp[x][1]=dp[y][1]=dp[z][1]=3;
    // for(int i=2;i<num;i++)
    // {
    //         dp[x][i]=dp[x][i-1];
    //         dp[y][i]=dp[y][i-1];
    //         dp[z][i]=dp[z][i-1];
    //         dp[x][i]+=(2*dp[x][i-2]+dp[y][i-2]+dp[z][i-2]);
    //         dp[y][i]+=(dp[x][i-2]+2*dp[y][i-2]+dp[z][i-2]);
    //         dp[z][i]+=(dp[x][i-2]+dp[y][i-2]+2*dp[z][i-2]);
    // }
    // cout<<dp[x][num-1]+dp[y][num-1]+dp[z][num-1];
    cout<<Combinations(num)<<endl;
    }
}