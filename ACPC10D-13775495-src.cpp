#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int t,i,j,count=1;
	cin>>t;
	while(t!=0)
	{
	
	
	int a[t][3];
	for(i=0;i<t;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>a[i][j];
		}
	}
	a[t-1][0]=a[t-1][0]+a[t-1][1];a[t-1][2]=0;a[0][0]=0;
	
	for(i=t-2;i>=0;i--)
	{
		for(j=2;j>=0;j--)
		{
			if(i==0 && j==0)
			break;
			
			
			if(j==2 && i!=t-2)
			{
				a[i][j]=fmin(a[i+1][j],a[i+1][j-1])+a[i][j];
			}
			else if(j==2 && i==t-2)
			{
				a[i][j]=a[i][j]+a[i+1][j-1];
			}
			else if(j==1 && i!=t-2)
			{
				a[i][j]=a[i][j]+fmin(fmin(a[i][j+1],a[i+1][j]),fmin(a[i+1][j-1],a[i+1][j+1]));
			}
			else if(j==1 && i==t-2)
			{
				a[i][j]=a[i][j]+fmin(a[i+1][j],fmin(a[i+1][j-1],a[i][j+1]));
			}
			else if(j==0)
			{
				a[i][j]=a[i][j]+fmin(a[i][j+1],fmin(a[i+1][j],a[i+1][j+1]));
			}
		}
	}
	cout<<count<<". "<<a[0][1]<<endl;
	count++;
	cin>>t;	
}
		return 0;
}
