#include<iostream>
#include<map>
using namespace std;
#define MAX 500001
map<int,int> m;
int sq[MAX];

void pre()
{
	int i;
	sq[0]=0;
	m[0]=1;
	for(i=1;i<MAX;i++)
	{
		if(sq[i-1]>i && !m[sq[i-1]-i])
		{
			sq[i]=sq[i-1]-i;
			m[sq[i]]=1;
		}
		else if(sq[i-1]+i>0)
		{
		sq[i]=sq[i-1]+i;
		m[sq[i]]=1;
		}
	}
}

int main()
{
	int num;
	pre();

	while(std::cin)
	{
		cin>>num;
		if(num==-1)
		break;
		cout<<sq[num]<<endl;
	}
	
	
	
	return 0;
}
