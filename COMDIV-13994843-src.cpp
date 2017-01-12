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
int gcd(int u, int v) {
return (v != 0)?gcd(v, u%v):u;
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
        int  gcd1 = gcd(a,b);
        long long  res = 1;
        if(gcd1 == 1)
        {
            printf("1\n");
            continue;
        }
        for(int i = 0 ; prime[i]  && prime[i]*prime[i] <=gcd1  && gcd1; i++)
        {
            int count = 0;
            while(gcd1%prime[i] == 0)
            {
                count++;
                gcd1/=prime[i];
            }
            res *= (count + 1);
        }
        if(gcd1 > 1)
            res *= 2;
        printf("%lld\n",res);
    }
    return 0;
}