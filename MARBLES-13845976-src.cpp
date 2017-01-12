#include<iostream>
using namespace std;
long long C(int n, int m){
    if(m>n-m) m=n-m;
    
    long long ans=1;
    
    for(int i=0;i<m;i++) ans=ans*(n-i)/(i+1);
    
    return ans;
}

int main()
{
	int t,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		cout<<C(a-1,b-1)<<endl;
	}
	
	return 0;
}