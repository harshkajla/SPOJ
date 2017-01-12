#include<iostream>
#include<algorithm>
using namespace std;
int n;

int check(int a[],int len,int m)
{
	int i;
	int c=1,prev=a[0];
	for(i=0;i<m;i++)
	{
		if(a[i]-prev>=len)
		{
			prev=a[i];
			c++;
		}
	}
	if(c>=n)
	return 1;
	else 
	return 0;
}
int bs(int a[],int m)
{
int low=1;
int high=a[m-1];
int mid;
int lastmid=-1,max=-1;
while(low<high)
{

mid=(high+low)/2;

if(lastmid==mid)
break;

lastmid=mid;
	if(check(a,mid,m)==1)
	{
	low=mid+1;
	max=mid;
	}
	else
	{
	high=mid;
	}
}	
return max;	
	
}
int main()
{
	int t;
	cin>>t;
	int i,m;
	while(t--)
	{
		cin>>m>>n;
		int a[m];
		for(i=0;i<m;i++)
			cin>>a[i];
		sort(a,a+m);
		cout<<bs(a,m)<<endl;		
		
	}
	return 0;
}