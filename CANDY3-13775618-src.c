#include<stdio.h>
int main()
{
	int t=-2;
	int count=0;
	int size=0;
	long long k;
	long long sum;
	scanf("%d",&t);
	while(t>0)
	{
		sum=0;
		
		count=0;
		printf("\n");
		scanf("%d",&size);
			while(count!=size)
			{
				scanf("%lld",&k);
				sum=(sum%size+k%size)%size;
				count++;
			}
			if(sum==0)
				printf("YES\n");
			else
				printf("NO\n");
			
			t--;
		}
		
		
	
return 0;
	
}



