#include<bits/stdc++.h>
using namespace std;
pair<int,int> dp[100][100];
// first -> smoke , second-> color ;
int main() {
    int num,arval;
    
    while(scanf("%d",&num)!=EOF){
        for(int i=0;i<num;i++)
        {
            scanf("%d",&arval);
            dp[i][i]=make_pair(0,arval);
        }
        
        for(int i=num-1;i>=0;i--)
        {
            for(int j=i+1;j<num;j++)
            {
                int minsmoke=INT_MAX;
                int mincolor;
                for(int k=i;k<j;k++)
                {
                    if(minsmoke>dp[i][k].first+dp[k+1][j].first+dp[i][k].second*dp[k+1][j].second)
                    {
                        minsmoke=dp[i][k].first+dp[k+1][j].first+dp[i][k].second*dp[k+1][j].second;
                        mincolor=(dp[i][k].second+dp[k+1][j].second)%100;
                    }
                }
                dp[i][j]=make_pair(minsmoke,mincolor);
            }
        }
        printf("%d\n",dp[0][num-1].first);
    }
   
}