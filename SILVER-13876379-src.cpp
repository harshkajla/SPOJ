#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	while(std::cin)
	{
		cin>>num;
		if(num==0)
		break;
		int k=log2(num);
		cout<<k<<endl;
		
	}
	
	
	
	return 0;
}