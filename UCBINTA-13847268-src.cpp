#include<iostream>
#include<cstdio>
#define gc getchar_unlocked
using namespace std;
void scan( int &x )
{
register int c = gc();
x = 0;
int neg = 0;
for( ; ((c<48 || c>57) && c != '-'); c = gc() );
if( c=='-' ) {
neg=1;
c=gc();
}
for( ;c>47 && c<58; c = gc() ) {
x = (x << 1) + (x << 3) + c - 48;
}
if( neg )
x=-x;
}



int main()
{
	long long i,j,num,firstrow=0,totalsum=0;
	cin>>num;
	int a[num][num];
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
		scan(a[i][j]);
		if(i==0)
		firstrow+=a[i][j];
		if(i<j)
		totalsum+=a[i][j];	
		}
	}	
	if(num==2)
	{
		long a0=1;
		cout<<a0<<" ";
		
			cout<<a[0][1]-a0<<" ";
		
	
	}
	else
	{
		long long a0=(firstrow-(totalsum/(num-1)))/(num-2);
		
		cout<<a0<<" ";
		for(i=1;i<num;i++)
		{
			cout<<a[0][i]-a0<<" ";
		}
	
	}
	return 0;
}