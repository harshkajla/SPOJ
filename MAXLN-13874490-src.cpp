#include<iostream>
using namespace std;
int main()
{
	int t,count=0;
	long long r;
	double ans=0;
	cin>>t;
	while(t--)
	{
		cin>>r;
		count++;
		ans=(4*r*r)+0.25;
		printf("Case %d: %0.2f\n",count,ans);
	}
	
	return 0;
}