#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
long long ar[101];
int main()
{
	long long t,num,count=0,ans=0,i;
	cin>>t;
	while(t--)
	{
		map<long long,long long> m;
		cin>>num;
		count=0;
		while(num--)
		{
		cin>>ar[count];
		m[ar[count]]++;
		count++;
		}
		ans=0;
		sort(ar,ar+count);
		for(i=0;i<count;i++)
		{
			if( m[ar[i]]!=0 && m[2*ar[i]]!=0)
			{
				ans++;
				m[ar[i]]--;
				m[2*ar[i]]--;
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;
}