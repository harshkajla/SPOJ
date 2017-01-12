#include<stdio.h>

int Merge(int*a1,int n1,int*a2,int n2,int*a)
{
	int i=0,j=0,k=0,swap=0,flag=0;
	
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
int selectionSort(int *a,int n)
{
int swap;
int i;
if(n<2)
return 0;
else
	{
	int a1[n/2];
	int a2[n - n/2];
	for( i=0;i<n/2;i++)
	a1[i]=a[i];
	for(;i<n;i++)
	a2[i-n/2]=a[i];
	
	int l=selectionSort(a1,n/2);
	int r=selectionSort(a2,n-n/2);
	int k=Merge(a1,n/2,a2,n-n/2,a);
	return l+r+k;
	}
}
int main()
{
	int t,count=0,count2=0,k,a[100000];
	scanf("%d",&t);
	while(count!=t)
	{
		scanf("%d",&k);
		count2=0;
		while(count2!=k)
		{
		scanf("%d",&a[count2]);
		count2++;
		}
		printf("%d\n",selectionSort(a,k));
		count++;
	}
	
	
	return 0;
}
