#include<iostream>
using namespace std;
void print(int a,int b)
{
	int l,m,flag=0;
	if(a>b)
	{
	l=a;
	m=b;
	flag=1;
	}
	else
	{
	l=b;
	m=a;
	}
  int i;
  for(i=2;i*i<=m;i++)
  {
  	if(m%i==0)
  	{
  		while(m%i==0 && l%i==0)
  		{
  			m/=i;
  			l/=i;
		}
	  }
  }
  if(m>1)
  {
  	if(l%m==0)
  	{
	l=l/m;
	m=m/m;
	}
  }
  if(flag==0)
  {
  	cout<<m<<" "<<l<<endl;
  }
  else
  cout<<l<<" "<<m<<endl;
	
}
int main()
{
	int t,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		print(b,a);			
		
		
	}
	
	
	return 0;
}