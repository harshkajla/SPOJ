#include<iostream>
#include<math.h>
#include<cstdio>
#define gc getchar_unlocked
using namespace std;
void sc( int &x )
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
	int t,arr1[10000],arr2[10000],i,j,m=0,n=0,a,b;
	long sum=0,sum1=0,sum2=0;


	sc(t);
	while(t!=0)
	{
		
		for(i=0;i<t;i++)
		{
			sc(arr1[i]);
		}
		sc(t);
		for(j=0;j<t;j++)
		{
			sc(arr2[j]);
		}
		m=0;n=0;
		sum=0;
		sum1=0;
		sum2=0;
		while(m<i && n<j)
		{
			
			if(arr1[m]>arr2[n])
			{
				sum2=sum2+arr2[n];
				n++;
			}
			else if(arr1[m]<arr2[n])
			{
				sum1=sum1+arr1[m];
				m++;
			}
			else
			{
				sum=sum+fmax(sum1,sum2)+arr1[m];
				m++;
				n++;
				sum1=0;sum2=0;

			}
		}
	
		while(m<i)
		{
			sum1=sum1+arr1[m];
			m++;
		}
		while(n<j)
		{
			sum2=sum2+arr2[n];
			n++;
		}
		sum=sum+fmax(sum1,sum2);
		cout<<sum<<endl;
		sc(t);
	}
	
	
	
	
	return 0;
}
