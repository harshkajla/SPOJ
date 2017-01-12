#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
char str1[100000];
char out[100000];
bool ar[4]={0,0,0,0};
int main()
{
	int n;
	cin>>n;
	cin>>str1;
	int count=0,i;
	int len=strlen(str1);
	int count2=0;
	for(i=0;i<len-1;i+=2)
	{
		count++;
		ar[str1[i]-'A']=1;
		ar[str1[i+1]-'A']=1;
		count2=0;
		char a,b;
		int flag=1;
		for(int j=0;j<4;j++)
		{
			
					if(ar[j]==0)
					{
					count2++;
					if(count==1)
					{
					if(count2==1)
					a='A'+j;
					else
					b='A'+j;
					}
					else
					{
						if(count2==1)
						{
							if(out[i-1]=='A'+j)
							flag=0;
						}
						if(flag==1)
						{
							if(count2==1)
							a='A'+j;
							else
							b='A'+j;
						}
						if(flag==0)
						{
							if(count2==1)
							b='A'+j;
							else
							a='A'+j;
						}
					}
				}
		}
		out[i]=a;
		out[i+1]=b;
		
		ar[str1[i]-'A']=0;
		ar[str1[i+1]-'A']=0;
	}
	 cout<<out<<endl;
	return 0;
}