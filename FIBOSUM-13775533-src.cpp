#include<stdio.h>
#include<map>
using namespace std;
map< long long, long long> dp;
void multiply(long long F[2][2], long long M[2][2])
{
  long long x =  (F[0][0]*M[0][0]%1000000007 + F[0][1]*M[1][0]%1000000007)%1000000007;
  long long y =  (F[0][0]*M[0][1]%1000000007 + F[0][1]*M[1][1]%1000000007)%1000000007;
  long long z =  (F[1][0]*M[0][0]%1000000007 + F[1][1]*M[1][0]%1000000007)%1000000007;
  long long w =  (F[1][0]*M[0][1]%1000000007 + F[1][1]*M[1][1]%1000000007)%1000000007;

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
void power( long long F[2][2],  long long n)
{
  if( n == 0 || n == 1)
      return;
  long long M[2][2] = {{1,1},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}
long  long fib( long long n)
{
   long long F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
    if(dp[n]!=0)
    {
        return dp[n];
    }
    power(F, n-1);
   dp[n]=F[0][0];
   return F[0][0];
}





int main()

{
    int t;
    long long M,N,i;
      long long sum=0;
    scanf("%d",&t);
    while(t>0)
    {
        scanf("%lld %lld",&N,&M);


            sum = (fib(M+2)-fib(N+1)+1000000007)%1000000007;
        printf("%lld \n",sum);
        sum=0;
        t--;
    }
    return 0;
}

