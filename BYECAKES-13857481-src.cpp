#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	int i,j,k;
	int ar1[4];
	int ar2[4];
	int flag=0;
	int out[4];
	int br=0;
	while(std::cin)
	{
		flag=0;
		for( i=0;i<4;i++)
		{
			cin>>ar1[i];
			if(ar1[i]!=-1)
			flag=1;
			out[i]=-1*ar1[i];
		}
		for(i=0;i<4;i++)
		{
			cin>>ar2[i];
			if(ar2[i]!=-1)
			flag=1;
		}
	
		if(flag==0)
		break;
		if(ar1[0]==0 && ar1[1]==0 && ar1[2]==0 && ar1[3]==0)
			{
			
				cout<<"0 0 0 0"<<endl;
				
				continue;
				
			}
		br=0;	
		int flag2=0;	
			while(br!=1)
			{
				flag2=0;
				for(i=0;i<4;i++)
				{
				out[i]+=ar2[i];
				}
				for(i=0;i<4;i++)
				{
					if(out[i]<0)
					{
						flag2=1;		
					}
				}
				if(flag2==0)
					br=1;
			}
			for(i=0;i<4;i++)
			cout<<out[i]<<" ";
		cout<<endl;
	}
	
	return 0;
}