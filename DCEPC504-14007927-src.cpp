#include<iostream>
using namespace std;

int main()
{
	long long n,k,count=0;
	int t;
	
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		count=0;
		while(k!=1)
		{
			if(k%2==0)
			{
				k=k/2;
				count++;
			}
			else
			{
				k=(k+1)/2;
				count+=2;
			}
		}
		if(count%2==0)
		{
			cout<<"Male"<<endl;
		}
		else
		{
			cout<<"Female"<<endl;
		}
	}
}