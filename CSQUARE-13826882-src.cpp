#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<stdio.h>
using namespace std;

int main(){
		
		string ex="";
		char ex1[251];
    	int t,i;
    	cin>>t;
    	unsigned long long pow,ans=0,e,m,b,res;
    	
		while(t--){
        	
        	ans=1,e,m,b,res=1;
        	ex="";
        	scanf("%llu %s %llu",&b,&ex1,&m);
//			cin >>b>>ex>>m;
        	ex.append(ex1);
        	pow=1;
			for(i=ex.length()-1;i>=0;i--)
        	{
        		if(((int)ex[i]-(int)'0')==1)
        		{
        			ans=(b%m*ans%m)%m;
				}
				if(((int)ex[i]-(int)'0')==2)
				{
					ans=(ans%m*b%m*b%m)%m;
				}
				b=(b%m*b%m*b%m)%m;
			}
			
		
//     	   while(e>0)
//     	   {
//           if(e%2!=0)
//            res = (res%m*b%m)%m;
//            e=e/2;
//            b=(b%m*b%m)%m;
//     	   }
     	   printf("%llu\n",ans);
   		}

	return 0;
}
