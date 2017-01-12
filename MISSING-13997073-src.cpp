#include<iostream>

int main()
{
long long num,count=0;
long long k;
	scanf("%lld %lld",&num,&k);
	
	long long ar[num-1],Xor=0;
	long long p=num,i;
	num--;
	while(num--)
	{
	scanf("%lld",&ar[count]);
	Xor^=ar[count];
	count++;	
	}

for( i=k;i<p+k;i++)
	Xor^=i;

printf("%lld\n",Xor);	
}
