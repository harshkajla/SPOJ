#include<bits/stdc++.h>
using namespace std;
char num[201];
int m[201];
//map<int,int> m;
int main()
{
	int cols,rows;
	while(std::cin)
	{
		cin>>cols;
		if(cols==0)
		break;
		
		cin>>num;
		int len=strlen(num),i=0,j;
		
		rows=len/cols;
		int k;
		bool flag=false;
		int t=0;
		int br=0;
		int count=1;
		for(j=0;j<len;j++){
			
			i=j;
			flag=false;
			while(m[i]!=1 && i<len)
			{
			cout<<num[i];
			m[i]=1;
			
			flag=!flag;
			if(flag==false)
			i+=1+t;
			else
			i=i+(2*(cols))-1-t;
			}
			t+=2;
		
			}
			cout<<endl;
			memset(m,0,201*sizeof(int));
	}
	return 0;
}