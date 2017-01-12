#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
#define gc getchar_unlocked
// void readInt(int &x){
//     register char c = gc();
//     x = 0;
//     int neg = 0;
//     for(;((c<48 || c>57) && c != '-');c = gc());
//     if(c=='-') {neg=1;c=gc();}
//     for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
//     if(neg) x=-x;
// }
int n, q, x, y;
pair<int,int> b[100005];
int t[4*100005], f[4*100005];
 
void build(int nd, int st, int en) {
    if (st==en) {
        t[nd] = b[st].ff;
        f[nd] = 0;
        return;
    }
 
    int mid = (st+en)/2;
    build(2*nd, st, mid);
    build(2*nd+1, mid+1, en);

    t[nd] = min(t[2*nd],t[2*nd]+1);
    f[nd] = 0;
    return;
}
 
void upd(int nd, int st, int en, int p1, int p2, int val) {
    if (st > p2 || en < p1) {
        return;
    }
    if (st >= p1 && en <= p2) {
        t[nd] += val;
        f[nd] += val;
        return;
    }
 
    if (f[nd] != 0) {
        for (int i=2*nd; i<=2*nd+1; i++) {
            f[i] += f[nd];
            t[i] += f[nd];
        }
        f[nd] = 0;
    }
 
    int mid = (st+en)/2;
    upd(2*nd, st, mid, p1, p2, val);
    upd(2*nd+1, mid+1, en, p1, p2, val);
 
    t[nd] = min(t[2*nd], t[2*nd+1]);
    return;
}
 
int qry(int nd, int st, int en, int pos) {
    if (st == en) {
        return t[nd];
    }
 
    if (f[nd] != 0) {
        for (int i=2*nd; i<=2*nd+1; i++) {
            f[i] += f[nd];
            t[i] += f[nd];
        }
        f[nd] = 0;
    }
    t[nd] = min(t[2*nd], t[2*nd+1]);
 
    int mid = (st+en)/2;
    if (pos <= mid) return qry(2*nd, st, mid, pos);
    else return qry(2*nd+1, mid+1, en, pos);
}
 
int qry2(int nd, int st, int en, int val) {
    //debug(nd, st, en, val, t[nd]);
    if (st == en) {
        if (val > t[nd]) return st+1;
        else return st;
    }
 
    if (f[nd] != 0) {
        for (int i=2*nd; i<=2*nd+1; i++) {
            f[i] += f[nd];
            t[i] += f[nd];
        }
        f[nd] = 0;
    }
    t[nd] = min(t[2*nd], t[2*nd+1]);
 
    int mid = (st+en)/2;
    if (t[2*nd+1] < val) return qry2(2*nd+1, mid+1, en, val);
    else return qry2(2*nd, st, mid, val);
}
 
int loc[100005], elem[100005];
 
int main()
{
    	scanf("%d %d",&n,&q);
 
    for (int i=1; i<=n; i++) {
        scanf("%d",&b[i].ff);
        b[i].ss = i;
    }
 
    sort(b+1, b+1+n);
    build(1,1,n);
    for (int i=1; i<=n; i++) {
        loc[b[i].ss] = i;
        elem[i] = b[i].ss;
    }
 
    int tmp, other, val, pos, ans;
 
    for (int i=1; i<=q; i++) {
        	scanf("%d %d",&x,&y);
        if (x == 1) {
            val = qry(1,1,n,loc[y]);
            pos = qry2(1,1,n,val+1) - 1;
            //debug(loc[y],pos);
            if (loc[y] == pos) {
                upd(1,1,n,pos,pos,1);
            }
            else {
                other = elem[pos];
                tmp = elem[loc[y]]; elem[loc[y]] = elem[pos]; elem[pos] = tmp;
                tmp = loc[y]; loc[y] = loc[other]; loc[other] = tmp;
                upd(1,1,n,pos,pos,1);
            }
        }
        else if (x == 2) {
            pos = qry2(1,1,n,y);
            //debug(pos, y);
            ans = n-pos+1;
            printf("%d\n", ans);
        }
        else {
            pos = qry2(1,1,n,y);
            if (pos > n) continue;
            upd(1,1,n,pos,n,-1);
        }
    }
 
 
    return 0;
}