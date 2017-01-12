#include <bits/stdc++.h>
using namespace std;
#define MAX 10000000
bool m[MAX];
int m1[MAX];
int main()
{
	int i,t,k=2,j,num;
	m1[0]=0;m1[1]=2;
			for(i=3;i*i<=MAX;i+=2)
			{
				if(!m[i])
				{
					for(j=i*i;j<=MAX;j+=2*i)
					{
					m[j]=1;
					}
				}
			}
		int count=1,k1=1;
		printf("3");
		printf("\n");
		for(i=3;i<=MAX;i++)
		{
			if(m[i]==0 && i%2!=0)
				{
					count++;
					if(!m[count] && count%2!=0 && i<MAX)
					{
						printf("%d\n",i);
						k1++;	
					}
				}
		}
	return 0;
}