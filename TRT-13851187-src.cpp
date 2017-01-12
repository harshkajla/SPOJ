#include<iostream>
#include<math.h>
using namespace std;
int ar[2001][2001];
long long maxsum(int arr[],int i,int j,int no)
{
	if(ar[i][j])
		return ar[i][j];
	if(i==j)
	{
		ar[i][j]=(no+1)*arr[i];
		return (no+1)*arr[i];
	}
	long long sum1=0,sum2=0;
	sum1+=(no+1)*arr[i]+maxsum(arr,i+1,j,no+1);
	sum2+=(no+1)*arr[j]+maxsum(arr,i,j-1,no+1);	
	ar[i][j]=fmax(sum1,sum2);
	return fmax(sum1,sum2);
}
int main()
{
	int i,num;
	cin>>num;
	int a[num];
	for(i=0;i<num;i++)
		cin>>a[i];
		
	cout<<maxsum(a,0,num-1,0);	
	
	return 0;
}