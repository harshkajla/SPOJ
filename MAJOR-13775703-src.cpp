#include<iostream>
#include<map>
#include<cstdio>
#define gc getchar_unlocked
using namespace std;
map<int,int> mp;
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

	int t;
	int i=0,m,n,q,p=0,k,max,num,maxin;
	int a[1000000];
	cin>>t;
	while(t--){
	
	scanint(num);
	
	max=-1;
		maxin=-1;
	
		for(i=0;i<num;i++)
		{
			scanint(a[i]);
			if(mp[a[i]]!=0)
			mp[a[i]]=mp[a[i]]+1;
			else
			mp[a[i]]=1;
		}
		for(i=0;i<=num-1;i++)
		{
		if(mp[a[i]]>(num)/2)
	{
	max=mp[a[i]];
	maxin=i;
	}
		mp[a[i]]=0;
		}
		if(maxin!=-1)
		cout<<"YES"<<" "<<a[maxin]<<endl;
		else
		cout<<"NO"<<endl;
	
	

}
	return 0;
}
