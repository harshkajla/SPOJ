#include<iostream>
#include<map>
#include<math.h>

using namespace std;
int abs(int a,int b)
{
	if(a>b)
	return a-b;
	else
	return b-a;
}
void primedistance(int a,int b)
{
	map<int,int> m;
int k=a;
int l=b;
int count=0,i,ini=0,count4=0;
int sum=0;

for (i=2;i*i<=a;i++) 
    {
        if (a%i==0) 
		{  
        	count=0;
			while (a % i == 0) {
                a /= i;
                count++;
        		
				}
			m[i]=count;
			sum=sum+count;
			count4++;	
        		
        }
    }
    if(a>1)
    {
		m[a]=1;
		sum=sum+1;
		count4++;
	}
	int count2=0;
	for (i=2;i*i<=b;i++) 
    {
        if (b%i==0) 
		{  
           count2=0;
			while (b % i == 0) {
                b /= i;
                count2++;
				}
			if(m[i]!=0)
			{
			sum=sum-m[i];
			m[i]=abs(m[i],count2);
			sum=sum+m[i];
			}
			else
			{
			m[i]=count2;
			count4++;
			sum=sum+m[i];
			}        		
        }
    }
     if(b>1)
    {
		if(m[b]==0)
		{
		m[b]=1;
		count4++;
		sum=sum+m[b];
		}
		else
		{
			sum=sum-m[b];
		m[b]=abs(m[b],1);
		sum=sum+m[b];
		}
	}
	 cout<<count4<<":"<<sum;
	
}
int main()
{
	int a,b,count=1;
	cin>>a>>b;
	while(a!=0 && b!=0)
	{
		cout<<count<<". ";
		primedistance(a,b);
		cout<<endl;
		count++;
		cin>>a>>b;
	}
	
	
	
	return 0;
}