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

int t,size,max,j,i;
cin>>t;
size=t;
int arr[t];
int count=0;
while(count!=t)
{
	scanint(arr[count]);
	count++;
}
int k;
cin>>k;

for(i=0;i<=size-k;i++)
{
	max=arr[i];
	for(j=i;j<i+k;j++)
	{
		if(max<arr[j])
		max=arr[j];
	}
	cout<<max<<" ";
	
}

	return 0;
}
