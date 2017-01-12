#include<iostream>
using namespace std;
int main()
{
	int i,m,max,count=0;
	cin>>m>>max;
	int a[m];
	while(count!=m)
	{
		cin>>a[count];
		count++;
	}
	int sum=0;int val=0;int s=0;	
		for(i=0;i<m;)
		{
			if(sum+a[i]<=max)
			{	
			sum=sum+a[i];
			i++;
			}
			else
			{
			if(sum<=max && sum>=val)
			val=sum;
			
			sum=sum-a[s];
			s++;
			if(sum<0)
			break;	
			
			}
		}
		if(sum<=max && sum>=val)
			val=sum;
		printf("%d",val);
	
	return 0;
}
