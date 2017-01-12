#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,h,p,a;
	cin>>t;
	while(t--)
	{
		scanf("%d%d%d",&h,&p,&a);
		if(h<=p)
		{
				printf("%d\n",1);
				continue;
		}
		double root=(p-2*a)*(p-2*a) - 8*p*(a-h);
		root=sqrt(root);
		double n=ceil(((2*a) -p+root)/(2*p));
		int ans=(2*n)-1;
		printf("%d\n",ans);		
	}
	
	
	
	return 0;
}