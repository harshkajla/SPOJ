#include<iostream>
#include<algorithm>
using namespace std;
int cows;
int Cal(int a[],int size,int x)
{
	int i,pos=a[0],c=1;
	for(i=1;i<size;i++)
	{
		if(a[i]-pos>=x)
		{
		pos=a[i];
		c++;
		}
	}
	if(c>=cows)
	return 1;
	else
	return 0;	
}

int BinarySearch(int a[],int size)
{
	int low=1,mid=-1,last=-1;
	int high=a[size-1];
	int b=-1;
	while(low<high)
	{
		mid=(low+high)/2;
		
		if(b==mid)
		break;
		if(Cal(a,size,mid)==1)
			{
			low=mid+1;
			last=mid;
			
		}
		else
		{
			high=mid;
		}
		b=mid;
	}
	return last;
}
int main()
{
	int t,n,count;
	cin>>t;
	

	while(t--)
	{
		cin>>n>>cows;
		int arr[n];
		count=0;
		while(count!=n)
		{
		cin>>arr[count];
		count++;
		}
		sort(arr,arr+count);
			cout<<BinarySearch(arr,count)<<endl;
	}
	
	return 0;
}
