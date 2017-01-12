#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	long long r,n;
	double ans=0,k;
	while(std::cin)
	{
		cin>>r>>n;
		if(n==0)
		break;
		
	
		ans=r/(sin(acos(-1)/(2*n)));
		printf("%.2f\n",ans);
		
	}
	
	return 0;
}