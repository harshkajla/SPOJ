#include<iostream>
#include<map>
long long ar[1000001];
long long psum[1000001];
using namespace std;
int main()
{
	long long i,t,num,count,ans=0;
	cin>>t;
	while(t--)
	{
		map<long long,long long> m;
		map<long long,long long> k;
		ans=0;
		cin>>num;
		count=0;
		while(num--)
		{
		cin>>ar[count];
		if(count>=1)
		psum[count]=psum[count-1]+ar[count];
		else
		psum[count]=ar[count];
	
		m[psum[count]]++;
		if(psum[count]==0)
		 	ans++;
		count++;
		}
		long long t;
		for( i=0;i<count;i++)
		{
			t=m[psum[i]];
			if(t>1 && k[psum[i]]!=1)
			{
			 
				k[psum[i]]=1;
			
				ans=ans+ (t*(t-1))/2;
			}
		}
		cout<<ans<<endl;
		
	}
}