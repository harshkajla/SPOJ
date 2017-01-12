#include<iostream>
using namespace std;
#define MAX 500001
int ar[MAX];
int main()
{
	int i,j;
	for(i=0;i<MAX;i++)
	ar[i]=0;
	for(i=1;i<=MAX/2;i++)
	{
			for(j=2*i;j<=MAX;j+=i)
			{
				if(!ar[j])
				ar[j]=i;
				else
				ar[j]+=i;
			}
	}
	int t,num;
	cin>>t;
	while(t--)
	{
		cin>>num;
		cout<<ar[num]<<endl;
	}
	
	return 0;
}