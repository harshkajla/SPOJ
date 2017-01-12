#include<iostream>
using namespace std;
int main()
{
	int t,a,b;
	cin>>t;
	while(t!=0)
	{
		cin>>a>>b;
		
		
		if(a==b+2 || a==b) 
		{
			if(a%2==0 && b%2==0)
			cout<<a+b<<endl;
			else if((a%2!=0 || b%2!=0))
			cout<<a+b-1<<endl;
			
		}
		else
		{
		cout<<"No Number"<<endl;	
		}
		
		t--;
	}
	
	return 0;
}
