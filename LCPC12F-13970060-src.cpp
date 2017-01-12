#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
	long long i,t,ans,sum,count=0,j,n;
	cin>>t;
	while(t--)
	{
		map<long long,long long> m;
		count++;
		cin>>sum;		
		ans=0;
		cin>>n;
		long long ar[n];
		for(i=0;i<n;i++)
		{
		cin>>ar[i];
		m[ar[i]]++;
		}
		
		
		for(i=0;i<n;i++)
		{
			 
			 if((sum-ar[i])== ar[i])
			 {
			 	if(m[sum-ar[i]]>1)
			 	{
			 	long long k=m[sum-ar[i]];
			 	ans=ans+k*(k-1)/2;
			 	m[sum-ar[i]]=0;	
			 	}
			 	else
			 	{
			 		m[sum-ar[i]]=0;	
			 	}
			 	
			 
			 }			 
			 else if(m[sum-ar[i]] )
				{
				//cout<<(sum-ar[i])<<" "<<ar[i]<<endl;
				ans=ans+(m[sum-ar[i]]*m[ar[i]]);
				
				m[sum-ar[i]]=0;
				m[ar[i]]=0;
			}
		}
		cout<<count<<". "<<ans<<endl;
	}
	
	return 0;
}