#include<iostream>
using namespace std;
#define MAX 1000001
bool a[MAX];
int ar[MAX];
void pre()
{
	int i=0,k=0,j=0;
	for(i=2;i*i*i<MAX;i++)
	{
		k=i*i*i;
		for(j=k;j<MAX;j+=k)
		a[j]=1;		
	}
	ar[0]=0;
	for(i=1;i<MAX;i++)
	{
		if(a[i]==1)
			ar[i]=ar[i-1];
		else
		ar[i]=ar[i-1]+1;	
	}
}
int main()
{
	pre();
	int t,i,j,num,count=0;
	ar[0]=0;
	
	cin>>t;
	while(t--)
	{
		cin>>num;
		count++;
		if(a[num]!=0)
		{
			cout<<"Case "<<count<<": Not Cube Free"<<endl;	
		}
		else
		{
			cout<<"Case "<<count<<": "<<ar[num]<<endl;

		}		
	}
	
	return 0;
}