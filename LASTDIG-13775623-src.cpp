#include<iostream>

using namespace std;

int power(int b,int exp)
{
	if(exp==0)
	return 1;
	if(exp==1)
	return b;
	int p=-1;
	if(exp%2==0)
	{
		
		 p=power(b,exp/2);
		 return p%10*p%10;
	}
	else
	{
	p=power(b,exp/2);
	return p%10*p%10*b%10;	
	}
}
int main()
{

	int t;
	int b,exp;
	cin>>t;
	while(t--){
	cin>>b>>exp;
	int k=power(b%10,exp);
	cout<<k<<endl;

}
	return 0;
}
