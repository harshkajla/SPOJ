#include<bits/stdc++.h>
using namespace std;
int ara[320007],Tree[320007],cnt,n;
bool vis[320007];
pair<int,int>q[40007];
void upd(int cn,int st,int ed,int L,int R,int id)
{
    if(st==L && ed==R)
    {
        Tree[cn]=id;
        return;
    }
    int mid=(st+ed)/2,lft=cn*2,rgt=lft+1;
    if(Tree[cn])   Tree[lft]=Tree[cn],Tree[rgt]=Tree[cn],Tree[cn]=0;
    if(R<=mid) upd(lft,st,mid,L,R,id);
    else if(L>mid) upd(rgt,mid+1,ed,L,R,id);
    else
    {
        upd(lft,st,mid,L,mid,id);
        upd(rgt,mid+1,ed,mid+1,R,id);
    }
}
void qry(int cn,int st,int ed)
{
    if(Tree[cn] || st==ed)
    {
        if(Tree[cn])
        {
            cnt+=(!vis[Tree[cn]]),
                 vis[Tree[cn]]=1;
        }
        return;
    }
    int mid=(st+ed)/2,lft=cn*2,rgt=lft+1;
    qry(lft,st,mid);
    qry(rgt,mid+1,ed);
}
int main()
{
    int ks,kase;
    scanf("%d",&kase);
    for(ks=1; ks<=kase; ks++)
    {
        scanf("%d",&n);
        if(!n)
        {
            printf("0\n");
            continue;
        }
        int ind=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d %d",&q[i].first,&q[i].second);
            ara[ind++]=q[i].first;
            ara[ind++]=q[i].first-1;
            ara[ind++]=q[i].first+1;
            ara[ind++]=q[i].second;
            ara[ind++]=q[i].second-1;
            ara[ind++]=q[i].second+1;
        }
        sort(ara,ara+ind);
        int sz=unique(ara,ara+ind)-ara;
        for(int i=1; i<=n; i++)
        {
            int S=lower_bound(ara,ara+sz,q[i].first)-ara;
            int E=lower_bound(ara,ara+sz,q[i].second)-ara;
            upd(1,0,sz,S,E,i);
        }
        cnt=0;
        qry(1,0,sz);
        printf("%d\n",cnt);
        memset(Tree,0,sizeof Tree);
        memset(vis,0,sizeof vis);
    }
}