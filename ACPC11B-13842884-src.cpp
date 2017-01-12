#include<iostream>
using namespace std;
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
int ar[200][1000];
int size[200];
int main()
{
	int t,i,j,k,l,min,p,diff;
	cin>>t;
		for(i=0;i<2*t;i++)
		{
			scanint(size[i]);	
			for(j=0;j<size[i];j++)
			scanint(ar[i][j]);	
		}
		
		for(i=0;i<2*t;i+=2)
		{
			min=10000000;
			for(j=0;j<size[i];j++)
			{
				for(p=0;p<size[i+1];p++)
				{
					diff=ar[i+1][p]-ar[i][j];
					if(diff<0)
					diff=-1*diff;
					if(diff<min)
					min=diff;
				}
			}
			cout<<min<<endl;
		}
	return 0;
}