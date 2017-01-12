#include<bits/stdc++.h>
using namespace std;
char str[100001];
long long num[100002];
map<char,long long> m;
int main()
{
	long long len,t,i;
	cin>>t;
	int k=1000000007;
	while(t--)
	{
		cin>>str;		
		len=strlen(str);
		m[str[len-1]]=len-1;
		num[len-1]=2;
		num[len]=1;
		for(i=len-2;i>=0;i--)
		{
			num[i]=2*num[i+1];
				
			if(num[i]>=k)
			num[i]-=k;
				
			if(m[str[i]]){
			
				num[i]-=num[m[str[i]]+1];
			if(num[i]<0)
			num[i]+=k;
			}
			m[str[i]]=i;			
		}
		cout<<num[0]<<endl;
		m.clear();
	}
	
	return 0;
}