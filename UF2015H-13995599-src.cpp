#include<iostream>
using namespace std;
int main()
{
	int t,num,k,i,max=0;
	cin>>t;
	while(t--)
	{
		cin>>num>>k;
		max=0;
		int ar[num];
		int sum=0;
		for( i=0;i<num;i++)
		{		
			cin>>ar[i];
			if(i<k)
			max+=ar[i];
			//sum+=ar[i];
		}
		sum=max;
		for(i=1;i<=num-k;i++)
		{
			sum=sum-ar[i-1]+ar[k+i-1];
			if(max<sum)
				max=sum;
			
		}
		cout<<max<<endl;
	}
	return 0;
}