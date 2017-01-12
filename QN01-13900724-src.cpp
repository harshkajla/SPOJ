#include<iostream>
using namespace std;
void maxXor(int ar[],int n)
{
	int i,j;
	int ans=0,val,max=-1,maxin=0,maxout=0;
	for(i=0;i<n;i++)
	{
		val=0;
		for(j=i;j<n;j++)
		{
			if((val^ar[j])==0)
			break;
			val=val^ar[j];
			if(val>max)
			{
			max=val;
			maxin=i;
			maxout=j;
			}
			
		}
	}
	cout<<max<<endl;
	cout<<maxin+1<<" "<<maxout+1<<endl;
}
int main()
{
	int t;
	cin>>t;
	int ar[t],count=0;
	while(t--)
	{
		cin>>ar[count++];
	}
	maxXor(ar,count);
	
	
	return 0;
}