#include<iostream>
#include<math.h>
#include<cmath>
using namespace std;
int main()
{
	long long len=0;
	long long t,num;
	cin>>t;
	while(t--)
	{
		cin>>num;
		if(num==0 || num==1||num==2)
		{
		cout<<"1"<<endl;
		continue;
		}
		
		cout<<(long long int)floor(((log(2*acos(-1)*num)/2+num*(log(num)-1))/log(10))+1)<<endl;
		
		
	
	}
}