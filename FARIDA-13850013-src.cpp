#include<iostream>
#include<math.h>
#include<cstdio>
#define gc getchar_unlocked
using namespace std;
void scanint( long long &x )
{
register long long c = gc();
x = 0;
long long neg = 0;
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
	long long i,t,num,max=0;
	cin>>t;
	while(t--)
	{
		max++;
		cin>>num;
		if(num==0)
		{
			cout<<"Case "<<max<<": "<<0<<endl;
			continue;
		}
		long long ar[num];
		for(i=0;i<num;i++)
		scanint(ar[i]);
		
		if(num>=2)
		ar[num-2]=fmax(ar[num-1],ar[num-2]);
		for(i=num-3;i>=0;i--)
		{
			if(i==num-3 )
			ar[i]=ar[i]+ar[i+2];
			if(i<=num-4)
			{
				ar[i]=ar[i]+fmax(ar[i+2],ar[i+3]);
			}
			
		}
		long long max2=ar[0];
		for(i=0;i<num;i++)
		{
			if(max2<ar[i])
			max2=ar[i];
		}
		cout<<"Case "<<max<<": "<<max2<<endl;
	}
	return 0;
}