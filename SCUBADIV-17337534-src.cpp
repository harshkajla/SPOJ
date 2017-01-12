#include<bits/stdc++.h>
using namespace std;

int o2[1024];
int n2[1024];
int wt[1024];
int dp[1024][22][80];
int MinWeight(int index,int o2Needed,int n2Needed,int maxCylinders){
    
    if(o2Needed==0 && n2Needed==0)
    {
        dp[index][o2Needed][n2Needed]=0;
        return 0;
    }
    if(index == maxCylinders)
    {
        dp[index][o2Needed][n2Needed]=INT_MAX;
        return 999999999;
    }
    
    if(dp[index][o2Needed][n2Needed]!=-1)
    return dp[index][o2Needed][n2Needed];
    
    int left=MinWeight(index+1,o2Needed,n2Needed,maxCylinders);
    int right=wt[index]+MinWeight(index+1,max(0,o2Needed-o2[index]),max(0,n2Needed-n2[index]),maxCylinders);
    // if(index == 1)
    // {
    //     cout<<left <<" : "<<right<<endl;
    //     cout<<min(left,right)<<endl;
    // }
    int ans=min(left,right);
    dp[index][o2Needed][n2Needed]=ans;
    return ans;
}
int main(){
    
    int t,Ocon,Ncon,cyl;
    scanf("%d",&t);
    while(t--)
    {
        
        scanf("%d %d",&Ocon,&Ncon);
        scanf("%d",&cyl);
        for(int i=0;i<=cyl;i++)
        {
            for(int j=0;j<=Ocon;j++)
            {
                for(int k=0;k<=Ncon;k++)
                dp[i][j][k]=-1;
            }
        }
        for(int i=0;i<cyl;i++)
            scanf("%d %d %d",&o2[i],&n2[i],&wt[i]);
        
        printf("%d\n",MinWeight(0,Ocon,Ncon,cyl));  
        
    }
    
}