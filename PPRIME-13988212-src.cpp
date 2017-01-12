#include <bits/stdc++.h>
#define MAX 1366662 
bool m[MAX];int main(){int i,t,k=2,j,num,count=1,k1=1;for(i=3;i*i<=MAX;i+=2)if(!m[i]){for(j=i*i;j<=MAX;j+=2*i) {m[j]=1;}}printf("3 ");for(i=3;i<=MAX;i++)if(m[i]==0 && i%2!=0){count++;if(!m[count] && count%2!=0){printf("%d ",i);k1++;}}return 0;}