#include<iostream>
//#include<map>
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
int a[1000000];
int majority(int start,int end)
{
	int k=start-1;
	int l=end-1;
	int count=1;
	int compare=a[k];
	int compare_i=0;
	for(int i=k+1;i<=l;i++)
	{
		if(a[i]==compare)
		{
			count++;
		}
		else if(a[i]!=compare && count!=0)
		{
			count--;;
		}
		else
		{
			count=0;
			compare=a[i];
			compare_i=i;
		}
	}
	
	if(count>0)
	{
		int count2=0;
		for(int i=k;i<=l;i++)
		{
			if(a[compare_i]==a[i])
			count2++;
		}
		int nby2=l-k+1;
		nby2/=2;
		//cout<<nby2<<endl;
		if(count2>nby2)
		return compare_i;
		
		return -1;
	}
	else
	{
		return -1;
	}
}

int main()
{

	int t;
	int i=0,m,n,q,p=0,k,max,num,maxin;
	
	cin>>t;
	while(t--){
	
	scanint(num);
	
	max=-1;
		maxin=-1;
	
		for(i=0;i<num;i++)
		{
			scanint(a[i]);
		}
		
		maxin=majority(1,num);
		if(maxin!=-1)
		cout<<"YES"<<" "<<a[maxin]<<endl;
		else
		cout<<"NO"<<endl;
}
	return 0;
}
