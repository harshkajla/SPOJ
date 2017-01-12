#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long ar1[10005];
long long ar2[10005];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,num1,num2;
    cin>>t;
    while(t--)
     {
        cin>>num1>>num2;
        for(int i=0;i<num1-1;i++)
            cin>>ar1[i];
        for(int i=0;i<num2-1;i++)
            cin>>ar2[i];
        
        sort(ar1,ar1+num1-1);
        sort(ar2,ar2+num2-1);
        int i=num1-2,j=num2-2;
        int xcut=0;
        int ycut=0;
        long long cost=0;
        while(i>=0 && j>=0)
        {
          if(ar1[i]>=ar2[j])
          {
                cost+= ((1+ycut)*ar1[i]);
                i--;
                xcut++;
          }
            else
                {
                cost+=((1+xcut)*ar2[j]);
                j--;
                ycut++;
            }
            cost=cost%(1000000007);
        }
        while(i>=0)
        {
                cost+=((1+ycut)*ar1[i]);
                i--;
                xcut++;
            cost=cost%(1000000007);
        }
        while(j>=0)
        {
                cost+=((1+xcut)*ar2[j]);
                j--;
                ycut++;   
            cost=cost%(1000000007);
        }
        
        cout<<cost<<endl;
    }
     
    return 0;
}
