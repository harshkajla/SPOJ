#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
#include<cstdio>
#define gc getchar_unlocked

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
	map<int,int>m;
	long long  n,k,count=0,i;
	cin>>n>>k;
	int ar[n];
	while(count!=n)
		{
		scanint(ar[count]);
		m[ar[count++]]=1;
		}
		long long ans=0;
		
	for(i=0;i<n;i++)
	{
		if(m[ar[i]+k]==1)
		{
		ans++;
		
		}
	}
	cout<<ans<<endl;
	return 0;
}