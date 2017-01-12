#include<bits/stdc++.h>
using namespace std;
char str[2002];
int cost(char left,char right)
{
    if(left == '{' &&  right=='}')
    return 0;
    else if(left=='}' && right == '{')
    return 2;
    else
    return 1;
}
int Flip2()
{
    stack<char> s;
    int len=strlen(str);
    int ans=0;
    for(int i=0;i<len;i++)
    {
        if(str[i]=='{')
            s.push(str[i]);
        else if(str[i]=='}')
        {
            if(!s.empty()){
            if(s.top()=='{')
                s.pop();
            else
                {
                    s.pop();
                    ans++;
                }
            }
            else
            {
                ans++;
                s.push('{');
            }
        }
    }
    return ans+s.size()/2;
}
// long long dp[2002][2002];
// 
// int Flip()
// {
//     int len=strlen(str);
//     for(int i=0;i<len;i++)
//     {
//         dp[i][i]=INT_MAX;
//         dp[i][i+1]= i<len-1 ? cost(str[i],str[i+1]):INT_MAX;
//     }
//     for(int i=len-1;i>=0;i--)
//     {
//         for(int j=i+2;j<len;j++)
//         {
//             dp[i][j]=cost(str[i],str[j])+dp[i+1][j-1];
//             for(int k=i+1;k<j;k++)
//                 dp[i][j]=min(dp[i][k]+dp[k+1][j],dp[i][j]);
//         }
//     }
//     return dp[0][len-1];
// }
int main()
{
    scanf("%s",str);
    int count=0;
    
    while(str[0]!='-')
    {
        count++;
        // cout<<count<<endl;
        printf("%d. %d\n",count,Flip2());
        scanf("%s",str);
    }
    
}