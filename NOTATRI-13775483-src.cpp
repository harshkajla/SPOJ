#include<iostream>
#include<algorithm>
using namespace std;


int Bs(int a[],int k,int c)
{
	int find;
	int low=-1;
	int high=k-1;
	int sum1=0,i,mid;
	for(i=0;i<k;i++)
	{
	find=c-a[i];
	low=i;
	high=k;
	mid=i;
		while(low<=high)
		{
		mid=(low+high)/2;
			if(a[mid]<find && a[mid+1]>=find)
			{
			break;
			}
			else if(a[mid]<find && a[mid+1]<find)
			{
				low=mid+1;
			}
			else if(a[mid]>=find)
			{
				high=mid-1;
			}
		}
	sum1=sum1+mid-i;
	}
	return sum1;
	
}
int main()
{
	int t=0,i,sum,count=0;
	int a[2001];
	cin>>t;
	while(t!=0)
	{
	sum=0;
	count=0;
	while(count!=t)
		{	
		cin>>a[count];
		count++;
		}
		sort(a,a+t);
	for(i=t-1;i>=1;i--)
	{
		sum=sum+Bs(a,i-1,a[i]);
	}
	cout<<sum<<endl;
	cin>>t;
	}
	return 0;
}
