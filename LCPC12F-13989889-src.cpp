#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
	long long i,t,ans,sum,count=0,j,n;
	cin>>t;
	long long leftcount=1,p,q;
		long long rightcount=1,k;
	while(t--)
	{
		//map<long long,long long> m;
		count++;
		cin>>sum;		
		ans=0;
		cin>>n;
		long long ar[n];
		for(i=0;i<n;i++)
		{
		cin>>ar[i];
		}
		sort(ar,ar+n);
		i=0;
		j=n-1;
		 leftcount=1;
		rightcount=1;
		while(i<j)
		{
			if(ar[i]+ar[j]==sum)
			{
				if(ar[i]==ar[j])
				{
					k=j-i+1;
					ans=ans+(k*(k-1))/2;
					break;
				}
				else
				{
					
					for(p=i+1;p<j;p++)
					{
						if(ar[p]!=ar[i])
						break;
						else
						leftcount++;
					}
				
					for( q=j-1;q>i;q--)
					{
						if(ar[q]!=ar[j])
						break;
						else
						rightcount++;
					}
					i=p;
					j=q;
					ans=ans+leftcount*rightcount;
					leftcount=1;
					rightcount=1;
				}
			}
			else if(ar[i]+ar[j]<sum)
			{
				i++;
			}
			else
			{
				j--;
			}
		}
		
		cout<<count<<". "<<ans<<endl;
	}
	return 0;
}