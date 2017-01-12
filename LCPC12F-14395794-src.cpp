#include<bits/stdc++.h>
using namespace std;
long long ar[100005];
long long numberofpairs(long long num,long long sum)
{
	sort(ar,ar+num);
	long long i=0;
	long long j=num-1;
	long long numpairs=0;
		long long count=0,count2=0,k,flag=0;
		
	while(i<j)
	{
		if(ar[i]+ar[j]>sum)
		{
			j--;
		}
		else if(ar[i]+ar[j]<sum)
		{
			i++;
		}
		else
		{
			if(ar[i]==ar[j])
			{
			numpairs+=((j-i+1)*(j-i))/2;
			return numpairs;
			}
			count=0;
			count2=0;
			long long oldi=i;
			for(k=i;k<j;k++){
				if(ar[k]==ar[i])
					count++;
				else
					break;
				}
		
				i=k;
			for(k=j;k>oldi;k--){
			
				if(ar[k]==ar[j])
					count2++;
				else
					break;
				}
				j=k;
				
		
			numpairs+=count*count2;
		}
	}
	return numpairs;
}
int main()
{
	long long i,t,num,sum,count=0;
	cin>>t;
	while(t--){
	cin>>sum;	
	count++;
	cin>>num;
	for(i=0;i<num;i++)
		cin>>ar[i];
		
	cout<<count<<". "<<numberofpairs(num,sum)<<endl;	
}
	
	
	return 0;
}
