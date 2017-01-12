#include<iostream>
using namespace std;
int main()
{
	unsigned long long int  t,n;
	cin>>t;
	unsigned long long int out,p,q;
	while(t--)
	{
		cin>>n;
		p=(n*(3*n+1))/2;
		
		out=(p)%1000007;
		cout<<out<<endl;	
	}
	return 0;
}
