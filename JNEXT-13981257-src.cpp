#include<iostream>
using namespace std;
int num[1000001];
#include<cstdio>
#define gc getchar_unlocked
using namespace std;
// void scanint( int &x )
// {
//     register int c = gc();
//     x = 0;
//     int neg = 0;
//     for( ; ((c<48 || c>57) && c != '-'); c = gc() );
//     if( c=='-' ) {
//         neg=1;
//         c=gc();
//     }
//     for( ;c>47 && c<58; c = gc() ) {
//         x = (x << 1) + (x << 3) + c - 48;
//     }
//     if( neg )
//         x=-x;
// } 
void reverse(int start,int size)
{

			
		int i=start,j=size-1;
	int temp;
		
		while(i<j)
		{
			temp=num[i];
			num[i]=num[j];
			num[j]=temp;	
			i++;
			j--;
		}
	

}
int main()
{
	
	int t,size,i,temp,min_index,j;
	
//	scanint(t);
	scanf("%d",&t);
	while(t--)
	{
		//int size;
		//scanint(size);
		scanf("%d",&size);
		for(i=0;i<size;i++)
		scanf("%d",&num[i]);
		
		for(i=size-1;i>=1;i--)
		{
			if(num[i-1]<num[i])
			{
				break;
			}
		}
		if(i==0)
		{
			cout<<"-1"<<endl;
			continue;
		}
			if(i==size-1 )
			{
					 temp=num[i-1];
					num[i-1]=num[i];
					num[i]=temp;
			}
			else
			{
				min_index=size-1;
				for( j=size-1;j>=i;j--)
				{
					if(num[j]>num[i-1])
						{
							min_index=j;	
							break;
						}	
				}
				
				 temp=num[i-1];
				num[i-1]=num[min_index];
				num[min_index]=temp;
				reverse(i,size);
					
			}
			
			
			
			
			
			for(i=0;i<size;i++)
				printf("%d",num[i]);
					cout<<endl;
		
	}
	
	
	return 0;
}