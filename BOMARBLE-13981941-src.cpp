#include<iostream>
using namespace std;
int main()
{
	int num;
	while(std::cin)
	{
		cin>>num;
		if(num==0)
		break;
		cout<<((3*num*num)+5*num+1)/2+1<<endl;
	}
	
	return 0;
}