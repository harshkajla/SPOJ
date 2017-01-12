#include<stdio.h>

long long Merge(long long *a1,long long n1,long long *a2,long long n2,long long *a)
{
	long long i=0,j=0,k=0,swap=0,flag=0;
	
	while(i<n1 && j<n2)
	{
		if(a1[i]>a2[j])
		{
			a[k]=a2[j];
			k++;
			j++;
			swap=swap+n1-i;
		}
		else
		{
			a[k]=a1[i];
			k++;
			i++;
		}
	}

	while(i<n1)
	{
			a[k]=a1[i];
			k++;
			i++;
	}
	while(j<n2)
	{
			a[k]=a2[j];
			k++;
			j++;
	}
	return swap;
}
long long selectionSort(long long *a,long long n)
{
long long swap;
long long i;
if(n<2)
return 0;
else
	{
	long long a1[n/2];
	long long a2[n - n/2];
	for( i=0;i<n/2;i++)
	a1[i]=a[i];
	for(;i<n;i++)
	a2[i-n/2]=a[i];
	
	long long  l=selectionSort(a1,n/2);
	long long r=selectionSort(a2,n-n/2);
	long long k=Merge(a1,n/2,a2,n-n/2,a);
	return l+r+k;
	}
}
int main()
{
	int t,count=0;
	long long count2=0,k;
	long long a[200000];
	scanf("%d",&t);
		printf("\n");
	while(count!=t)
	{
		scanf("%lld",&k);
		count2=0;
		while(count2!=k)
		{
		scanf("%lld",&a[count2]);
		count2++;
		}
		printf("\n");
		printf("%lld\n",selectionSort(a,k));
	
		count++;
	}
	
	
	return 0;
}
