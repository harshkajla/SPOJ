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
	int t,num,i,j,min;
	cin>>t;
	while(t--)
	{
		scanint(num);
		
		int a[num][3];
		for(i=0;i<num;i++)
		{
			for(j=0;j<3;j++)
			scanint(a[i][j]);
		}
		for(i=num-2;i>=0;i--)
		{
			for(j=2;j>=0;j--)
			{
				if(j==2)
				a[i][j]=a[i][j]+fmin(a[i+1][j-2],a[i+1][j-1]);
				else if(j==1)
				a[i][j]=a[i][j]+fmin(a[i+1][j-1],a[i+1][j+1]);
				else
				a[i][j]=a[i][j]+fmin(a[i+1][j+2],a[i+1][j+1]);
			}
		}
				min=a[0][0];
			for(i=0;i<3;i++)
			{
			if(a[0][i]<min)
				min=a[0][i];
			}
		
		cout<<min<<endl;
	}
	
	
	return 0;
}