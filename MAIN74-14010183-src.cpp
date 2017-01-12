#include<iostream>
#include<map>
using namespace std;
map< unsigned long long, unsigned long long> dp;
void multiply(unsigned long long F[2][2], unsigned long long M[2][2])
{
  unsigned long long x =  (F[0][0]*M[0][0]%1000000007 + F[0][1]*M[1][0]%1000000007)%1000000007;
	unsigned long long y =  (F[0][0]*M[0][1]%1000000007 + F[0][1]*M[1][1]%1000000007)%1000000007;
 unsigned long long z =  (F[1][0]*M[0][0]%1000000007 + F[1][1]*M[1][0]%1000000007)%1000000007;
 unsigned long long w =  (F[1][0]*M[0][1]%1000000007 + F[1][1]*M[1][1]%1000000007)%1000000007;

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
void power( unsigned long long F[2][2],  unsigned long long n)
{
  if( n == 0 || n == 1)
      return;
  unsigned long long M[2][2] = {{1,1},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}
unsigned long  long fib( unsigned long long n)
{
  unsigned  long long F[2][2] = {{1,1},{1,0}};
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
	scanf("%d",&t);
	unsigned long long p;
	while(t--)
	{
		
		cin>>p;
		if(p==0 )
		printf("0\n");
		else if(p==1)
		printf("2\n");
		else{		
		printf("%llu\n",(fib(p+3)+1000000007)%1000000007);
		}
	}
	
	return 0;
}