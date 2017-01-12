#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t,sum,var=0,num,ans,i,ans2,j;
	cin>>t;
	while(t--)
	{
		var++;
		ans2=0;
		ans=0;
		cin>>sum>>num;
		int ar[num];
		for(i=0;i<num;i++)
		cin>>ar[i];
		sort(ar,ar+num);
		
		for(j=num-1;j>=0;j--)
		{
		
		
		if(ans>=sum)
		break;
		ans+=ar[j];
		ans2++;	
		}
		if(ans>=sum)
		cout<<"Scenario #"<<var<<":"<<endl<<ans2<<endl;
		else
		cout<<"Scenario #"<<var<<":"<<endl<<"impossible"<<endl;
		// cout<<endl;
	}
	
	
	return 0;
}