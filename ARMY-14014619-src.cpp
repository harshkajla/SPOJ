#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t,a,b,i,j;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		int ar1[a];
		int ar2[b];
		for(i=0;i<a;i++)
			cin>>ar1[i];
			sort(ar1,ar1+a);
		for(i=0;i<b;i++)
			cin>>ar2[i];
			sort(ar2,ar2+b);
		
		i=0;j=0;
		int coun1=0,count2=0;
		while(i<a && j<b)
		{
			if(ar1[i]>ar2[j])
			{
				j++;			
			}
			else if(ar1[i]<ar2[j])
			i++;
			else
			j++;
		}
		if(j==b)
		{
			cout<<"Godzilla"<<endl;
		}
		else
		cout<<"MechaGodzilla"<<endl;
	}
	return 0;
}