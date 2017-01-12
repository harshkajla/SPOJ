#include<stdio.h>
#define Z 1299710  
int m[Z],v[Z];int main(){int i,k=2,j,c=1,n;v[1]=2;for(i=3;i*i<=Z;i+=2){if(!m[i]){for(j=i*i;j<=Z;j+=2*i){m[j]=1;}}}for(i=3;i<=Z;i+=2){if(!m[i]){c++;v[k++]=i;}}while(scanf("%d",&n)!=EOF){printf("%d\n",v[n]);}return 0;}