#include<stdio.h>

int main()
{
	int t=-1,i;
	int prev=0,current=0;
	while(t!=0)
	{
		
		scanf("%d",&t);
		if(t==0)
		break;
		prev=0;
		current=0;
		for(i=1;i<=t;i++)
		{
		current=prev+i*i;
		prev=current;
		}
		printf("%d\n",current);
	}
	
	return 0;
}
