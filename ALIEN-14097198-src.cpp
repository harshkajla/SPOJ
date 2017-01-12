#include<bits/stdc++.h>
using namespace std;
long long ar[1000001];
int main()
{
	long long t,i,num,sum;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&num,&sum);
		for(i=0;i<num;i++)
		scanf("%lld",&ar[i]);
		
		long long sum1=0;
		long long maxsum=INT_MAX;
		long long len=0,maxlen=-1;
		long long k=0;
		for(i=0;i<num;)
		{
			if(sum1+ar[i]<=sum)
			{
			sum1=sum1+ar[i];
			i++;
			len++;
			if(len>maxlen &&  len>1)
				{	
					maxsum=sum1;
					maxlen=len;
				}
				else if(len==maxlen && maxsum>sum1)
				{
				maxsum=sum1;
				maxlen=len;
				}
			}
			else
			{
				if(sum1==0)
				{
				i++;
				k++;				
				}
				else
				{	
					sum1=sum1-ar[k];
					k++;
					len--;
				}
						
			}
		}
		printf("%lld %lld\n",maxsum,maxlen);		
	}
	
	return 0;
}