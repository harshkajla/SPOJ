#include<iostream>
using namespace std;
#include <math.h> 
#include<cstdio>
#define MAX 100000001
bool m[MAX];
int m1[MAX];
double round( double f )
{   
    return floor((f * 10 ) + 0.5) / 10;
}
int main()
{
	float num;
	int i,j;
	m1[2]=1;
	m1[0]=0;m1[1]=0;
	for(i=3;i*i<=MAX;i+=2)
			{
				if(!m[i])
				{
					m[i]=0;
					for(j=i*i;j<=MAX;j+=2*i)
					{
					m[j]=1;
					}
				}
			}
		
		for(i=3;i<MAX;i++)
		{
			if(m[i]==0 && i%2!=0)
				m1[i]=m1[i-1]+1;
			else
				m1[i]=m1[i-1];
		}

	double res=0;	
	while(std::cin)
	{
			cin>>num;
			if(num==0)
			break;
			
	res=100*(m1[(int)num]-(num/log(num)))/m1[(int)num];		
	if(res<0)
	res=res*-1;
//	cout<<round(res)<<endl;
printf("%0.1lf\n",res);		
	}
	
	
	return 0;
}