#include<stdio.h>
int main()
{
	int t=0,count=0,n=0,m=0,d=0,num=0,k,arr[501],count2=0;
	scanf("%d",&t);
	while(count!=t)
	{
	scanf("%d %d %d",&n,&m,&d);
		count2=0;
		for(k=0;k<n;k++)
		{
			scanf("%d",&arr[num]);
			while((arr[num]-=d)>0)
			{
				count2++;
			}

		}
		if(count2>=m)
		printf("YES\n");
		else
		printf("NO\n");
		count++;
	}
	return 0;
}

