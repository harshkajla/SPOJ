#include<iostream>
#include<cstdio>
#define gc getchar_unlocked
using namespace std;
void scanint( int &x )
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
	int t;
	cin>>t;
	int ans=0,num;
	while(t--)
	{
		scanint(num);
		ans=ans^num;
	}
	cout<<ans;
	return 0;
}