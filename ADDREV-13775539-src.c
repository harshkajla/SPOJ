#include <stdio.h>
int Reverse(int a)
{
	int n=a;
	int value=0;
	int rem=-1;
	while(n!=0)
	{
		rem=n%10;
		value=10*value+rem;
		n=n/10;
	}
	return value;
}
int main() {
int t=0,a=0,b=0,count=0,rev1=0,rev2=0;
scanf("%d",&t);
while(count<t)
{
	scanf("%d  %d",&a,&b);
    rev1=Reverse(a);
    rev2=Reverse(b);
    printf("%d\n",Reverse(rev1+rev2));	
count++;	
}
	return 0;
}
