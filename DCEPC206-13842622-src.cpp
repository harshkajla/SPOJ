#include<iostream>
using namespace std;
long long merge(long long a[],long long n1,long long b[],long long n2,long long c[])
{
	long long i=0,j=0,k=0,sum=0;
	while(i<n1 && j<n2)
	{
		if(a[i]<b[j])
		{
			sum=sum+(n2-j)*a[i];
			c[k]=a[i];
			k++;
			i++;
		}
		else 
		{
				c[k]=b[j];
				k++;
				j++;
		}
	}
	while(i<n1)
	{
		c[k]=a[i];
		k++;
		i++;
	}
	while(j<n2)
	{
		
		c[k]=b[j];
		k++;
		j++;
	}
	return sum;
}
long long mergesort(long long a[],long long n)
{
	if(n<2)
	return 0;
	long long left[n-n/2],i;
	long long  right[n/2],k1,k2;
	for(i=0;i<n-n/2;i++)
	left[i]=a[i];
	for(i=n-n/2;i<n;i++)
	right[i-n+n/2]=a[i];
	
	 k1=mergesort(left,n-n/2);
	 k2=mergesort(right,n/2);
	return k1+k2+merge(left,n-n/2,right,n/2,a);
}

int main()
{
	long long  t,num,count;
	cin>>t;
	while(t--)
	{
		cin>>num;
		long long ar[num];
		count=0;
		while(count!=num)
		{
			cin>>ar[count++];
		}
		cout<<mergesort(ar,num)<<endl;
	}
}