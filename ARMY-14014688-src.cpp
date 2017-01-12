#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,a,b,i,j,max1,max2,num;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&a,&b);
		max1=-1;
		max2=-1;
		
		for(i=0;i<a;i++)
			{
			scanf("%d",&num);
			if(max1<num)
			max1=num;
			}
		//	sort(ar1,ar1+a);
		for(i=0;i<b;i++)
			{
				scanf("%d",&num);
			if(max2<num)
			max2=num;
			}
			//sort(ar2,ar2+b);
		
		if(max1>=max2)
		{
			printf("Godzilla\n");
		}
		else
		printf("MechaGodzilla\n");
	}
	return 0;
}