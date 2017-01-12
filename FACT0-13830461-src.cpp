#include<iostream>
#include<stdio.h>
using namespace std;
void Prime(long long  a)
{
if(a==1)
{
	printf("1^1");
	return;
}
	
	long long i,p;
int count=0;
for (i=2;i*i<=a;i++) 
    {
        if (a%i==0) 
		{  
			count=0;
			while (a % i == 0) {
                count++;
				a /= i;
					
				}	
				printf("%lld^%d ",i,count);		        		
        }
    }
    if(a>1)
    {
		printf("%lld^1",a);  
	}
	
}
int main()
{
	long long num;
	while(scanf("%lld",&num) != EOF)
	{
		if(num==0)
		break;
		Prime(num);
		printf("\n");
	}
	
	
	
	return 0;
}