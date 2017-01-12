#include<iostream>
#include<map>
#include<algorithm>
using namespace std;


int main()
{
	map<int,int>m;
	long long  n,k,count=0,i;
	cin>>n>>k;
	long long int ar[n];
	while(count!=n)
		{
		cin>>ar[count];
		m[ar[count++]]=1;
		}
		long long ans=0;
		
	for(i=0;i<n;i++)
	{
		if(m[ar[i]+k]==1)
		{
		ans++;
		
		}
	}
	cout<<ans<<endl;
	return 0;
}