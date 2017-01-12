#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
//
//long long Prime(long long  a)
//{
//
//long long k,i,pro=1;
//int count=0;
//
//for(int i=2;i*i<=a;i++)
//{
//		 count=0;
//		 k=i;
//		 while(a%k==0)
//		 {
//		 a=a/k;
//			count++;
//		}
//		pro=pro*(count+1);
//}
//if(a>1)
//pro=pro*2;
//return pro;
//}
int issquare(long long num)
{
	
	long long sq=pow(num,0.5);
	if(sq*sq==num)
	return 1;
	else
	return 0;
}
int main()
{
	
	long long t,num,count=0;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&num);
		count++;
		if(issquare(num))
		{
			printf("Case %d: Yes\n",count);
		}
		else
		printf("Case %d: No\n",count);
	}
	
	
	
	
	return 0;
}