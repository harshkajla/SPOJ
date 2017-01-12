#include<iostream>
using namespace std;
#define MAX 500001
#include<cstdio>
#define gc getchar_unlocked
using namespace std;
int ar[MAX];
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
	int i,j;
	for(i=0;i<MAX;i++)
	ar[i]=0;
	for(i=1;i<=MAX/2;i++)
	{
			for(j=2*i;j<=MAX;j+=i)
			{
				if(!ar[j])
				ar[j]=i;
				else
				ar[j]+=i;
			}
	}
	int t,num;
	cin>>t;
	while(t--)
	{
		scan(num);
		cout<<ar[num]<<endl;
	}
	
	return 0;
}