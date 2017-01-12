#include <bits/stdc++.h>
using namespace std;
int prime[1001];
bool check[1001];
void pre()
{
    for(int i = 3 ; i*i<=1000 ; i+=2)
    {
        if(!check[i])
        {
            for(int j = i*i ; j<=1000 ; j+=2*i)
                check[j] = true;
        }
    }
    int j  = 1;
    prime[0] = 2;
    for(int i = 3; i <=1000 ; i+=2)
        if(!check[i])
            prime[j++] = i;
}
int main()
{
    pre();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        long long  gcd = __gcd(a,b);
        long long  res = 1;
        if(gcd == 1)
        {
            printf("1\n");
            continue;
        }
        for(int i = 0 ; prime[i]  && prime[i]*prime[i] <= gcd  && gcd; i++)
        {
            int count = 0;
            while(gcd%prime[i] == 0)
            {
                count++;
                gcd/=prime[i];
            }
            res *= (count + 1);
        }
        if(gcd > 1)
            res *= 2;
        printf("%lld\n",res);
    }
    return 0;
}