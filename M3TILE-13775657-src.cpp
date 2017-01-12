#include<iostream>
#include<map>
using namespace std;
map<int,int>m;

int bricks(int n)
{
if(m[n]!=0)
return m[n];

if(n==0)
return 1;
if(n==2)
return 3;
if(n%2!=0)
return 0;
int p=0;
	p=4*bricks(n-2)-bricks(n-4);
	m[n]=p;
	return p; 
} 

int main()
{
	int t=0,i;
	cin>>t;
	while(t!=-1)
	{
		
		cout<<bricks(t)<<endl;
		cin>>t;
	}
	
	return 0;
}
