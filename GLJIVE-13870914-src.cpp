#include<iostream>
using namespace std;
int main()
{
	int i;
	int num;
	int sum=0;
	int flag=1;
	for(i=0;i<10;i++)
	{
		cin>>num;
		
		if(sum<100)
		sum=sum+num;
		
		if(sum==100 && flag==1)
		{
			cout<<"100";
			flag=0;
		}
		if(sum>100)
		{
			if(flag==1)
			{
				flag=0;
				
				if(100-(sum-num)>=sum-100)
				cout<<sum;
				else
				cout<<sum-num;
			}
		}
	
	}
	
	if(flag==1)
	cout<<sum<<endl;
	return 0;
}