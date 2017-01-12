#include <bits/stdc++.h>
using namespace std;
bool m[10000009];
int m1[10000000];

int main()
{
	int i,t,k,j,num;

			for(i=3;i<=3163;i+=2)
			{
				if(!m[i])
				{
					for(j=i*i;j<=10000001;j+=2*i)
					{
					m[j]=1;
					}
				}
			}
		m1[2]=1;
		for(i=3;i<10000001;i++)
		{
			if(m[i]==0 && i%2!=0)
				m1[i]=m1[i-1]+1;
			else
				m1[i]=m1[i-1];
		}
		
scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&num);
		printf("%d\n",m1[num]-m1[num>>1]);
	}
	
	
	return 0;
}