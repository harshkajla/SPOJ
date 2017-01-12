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

int fmin(int a,int b)
{
	if(a>b)
	return b;
	else 
	return a;
}
int main()
{
	int count,t,m,n,i,j,min,sum,a[501][501],num;
	cin>>t;
	while(t>0)
	{
		scanint(m);
		scanint(n);
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			{
			scanint(num);
			a[i][j]=num;
				
				}
			
		min=0;
	count=0;
		for(i=n-2;i>=0;i--)
		{
			if(a[m-1][i]<=0)
			{
			
				count++;
				if(count==1)
					min=min+(-1)*a[m-1][i]+1;
					else
						min=min+(-1)*a[m-1][i];

			}
			else
				{
					if(min-a[m-1][i]>0)
					min=min-a[m-1][i];
					else
					min=1;
				}
			
			a[m-1][i]=min;
		}
			
		min=0;
		count=0;
		for(i=m-2;i>=0;i--)
		{
			if(a[i][n-1]<=0)
			{
				count++;
				if(count==1)
				min=min+(-1)*a[i][n-1]+1;
				else
				min=min+(-1)*a[i][n-1];
				
			}
			else
				{
				if(min-a[i][n-1]>0)
				min=min-a[i][n-1];	
				else
				min=1;
				}
				a[i][n-1]=min;
			
		}
		
		for(i=m-2;i>=0;i--)
		{
			for(j=n-2;j>=0;j--)
			{
				min=fmin(a[i][j+1],a[i+1][j]);
				if(a[i][j]<0)
				{
					a[i][j]=min+(-1)*a[i][j];
				}
				else
				{
				if(min-a[i][j]>0)
					a[i][j]=min-a[i][j];	
				else
					a[i][j]=1;;
				}
			}		
		}		
		
		cout<<a[0][0]<<endl;	
		
		t--;
	}
	
	
	
	
	return 0;
}
