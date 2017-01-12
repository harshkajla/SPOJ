#include <stdio.h>

int zero(int n)
{
	int k=n;
	int div=5;
	int value=0;
	while(k/div!=0)
	{
		value=value+k/div;
		div=5*div;
	}
	return value;
}
int main() {
int t=0,a=0,count=0;
scanf("%d",&t);
while(count<t)
{
scanf("%d",&a);
printf("%d\n",zero(a));   	
count++;	
}
	return 0;
}
