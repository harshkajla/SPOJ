#include<stdio.h>
int main()
{
	int t=-2,count=0,arr[10000],c=0,count2=0,sum=0;
	
		scanf("%d",&t);
	while(t>0)
	{
		sum=0;
		c=0;
		count2=0;
		count=0;
	
			while(t!=count)
			{
				scanf("%d",&arr[count]);
			
				sum=sum+arr[count];
				count++;
			}
			if(sum%count==0)
			{
				while(c!=t)
				{
					if(arr[c]>sum/count)
					{
					
						arr[c]=arr[c]-1;
						count2++;
					}
					
					else
					{
						c++;
					}
				}
				
				printf("%d\n",count2);
			}
			if(sum%count!=0)
			{
				printf("-1\n");
			}
			scanf("%d",&t);
		}
		
		
	

	
}
