#include<iostream>

#include<math.h>
#include<cstdio>
#define gc getchar_unlocked
using namespace std;
int dp[2500][2500][3];
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int rec(int a, int b,int c)
{
	if(a<=0 || b<=0)
	return 0;
	if(dp[a][b][c])
	return dp[a][b][c];
	
	
		if(c==0)
		{
		return dp[a][b][c]=fmax(1+rec(a-5,b-10,1),1+rec(a-20,b+5,2));
		}
		if(c==1)
		{
		return dp[a][b][c]=fmax(1+rec(a-20,b+5,2),1+rec(a+3,b+2,0));
		}
		if(c==2)
		{
		return dp[a][b][c]=fmax(1+rec(a-5,b-10,1),1+rec(a+3,b+2,0));
		}
}
int main()
{
	int t,m,n,i,j,min,sum;
	scanint(t);

	int max=0;
	while(t>0)
	{
		scanint(m);
		scanint(n);
		
		max=fmax(rec(m,n,0),fmax(rec(m,n,1),rec(m,n,2)))-1;
		cout<<max<<endl;
		t--;
	}
	
	
	
	
	return 0;
}
