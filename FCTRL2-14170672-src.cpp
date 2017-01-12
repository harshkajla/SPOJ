#include<bits/stdc++.h>
using namespace std;
int out[1000];
//int copy
int main()
{
	int t,num;
	cin>>t;
	long long ans=1;
	while(t--)
	{
		ans=1;
		cin>>num;
		
		if(num<20)
		{	
			for(int i=2;i<=num;i++)
			ans=ans*i;
			cout<<ans<<endl;
		}
		else
		{
			memset(out,0,999*sizeof(int));	
			for(int i=2;i<=20;i++)
			ans=ans*i;
						
			long long temp=ans;
			int k=999;
			
			while(temp!=0)
			{
				out[k]=temp%10;
				temp=temp/10;
				k--;
			}
					
			for(int i=21;i<=num;i++)
			{											
					int unitdigit=999;
					int carry=0;
					int j;
					for(j=999;j>=0;j--)
					{
						out[j]=i*out[j]+carry;
						if(out[j]>=10)
						{
							carry=out[j]/10;
							out[j]=out[j]%10;		
						}
						else
						carry=0;
					}					
					int k=j+1;
					carry=0;
					
				
			}
			int i;
			for(i=0;i<=999;i++)
				if(out[i]!=0)
					break;
					
			for(int p=i;p<=999;p++)
			cout<<out[p];
			
			cout<<endl;
//			
			
		}
		
		
	}
	
	return 0;
}