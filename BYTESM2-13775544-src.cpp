#include<iostream>
 #include<math.h>
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
  
    int count,t,m,n,i,j,max,sum,a[101][101],num;
	cin>>t;
	while(t--)
	{
		scanint(m);
		scanint(n);
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			scanint(a[i][j]);
	
	for(i=m-2;i>=0;i--)
	{
		for(j=n-1;j>=0;j--)
		{
			if(j==0)
			{
				a[i][j]=a[i][j]+fmax(a[i+1][j+1],a[i+1][j]);
			}
			else if(j==n-1)
			{
				a[i][j]+=fmax(a[i+1][j-1],a[i+1][j]);
			}
			else
			{
				a[i][j]+=fmax(a[i+1][j+1],fmax(a[i+1][j-1],a[i+1][j]));
			}
			
		}
		
	}
	max=a[0][0];
	for(i=0;i<n;i++)
	{
		if(max<a[0][i])
		max=a[0][i];
	}
	cout<<max<<endl;
	}
    return 0;
}
