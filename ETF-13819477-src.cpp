#include<iostream>
using namespace std;
#define MAX 1000001
int ar[MAX];
int main()
{
	ar[1]=1;
	int i,j,n;
	for(i=2;i<=MAX;i++)
			{
			if(!ar[i])
				{
				ar[i]=i-1;	
				for(j=i*2;j<=MAX;j+=i)
					{
					if(!ar[j])
					ar[j]=j;
					
					ar[j]-=ar[j]/i;
					}
				}
			}	
	int t;
			cin>>t;
	while(t--)
	{
	cin>>n;
	cout<<ar[n]<<endl;
		
	}
	
	
	return 0;
}