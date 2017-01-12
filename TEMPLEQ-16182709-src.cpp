//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <functional>
#include <string>
#include <iostream>
#include <cctype>
#include <set>
#include <climits>
#include <iomanip>
#include <cassert>
//#include <unordered_map>
 
#define pb push_back
#define nl puts ("")
#define sp printf ( " " )
#define phl printf ( "hello\n" )
#define ff first
#define ss second
#define POPCOUNT __builtin_popcountll
#define RIGHTMOST __builtin_ctzll
#define LEFTMOST(x) (63-__builtin_clzll((x)))
#define MP make_pair
#define FOR(i,x,y) for(int i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(int i = (y) ; i >= (x) ; --i)
#define CLR(x,y) memset(x,y,sizeof(x))
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define NUMDIGIT(x,y) (((int)(log10((x))/log10((y))))+1)
#define SQ(x) ((x)*(x))
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define ALL(x) (x).begin(),(x).end()
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define SZ(x) ((int)(x).size())
 
using namespace std;
 
#define LL long long
 
typedef long long vlong;
typedef unsigned long long uvlong;
typedef pair < int, int > pii;
typedef pair < vlong, vlong > pll;
typedef vector<pii> vii;
typedef vector<int> vi;
 
const vlong inf = 2147383647;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;
 
#ifdef forthright48
     #include <ctime>
     clock_t tStart = clock();
     #define debug(args...) {dbg,args; cerr<<endl;}
     #define timeStamp printf("Execution Time: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC)
#else
    #define debug(args...)  // Just strip off all debug tokens
    #define timeStamp
#endif
 
struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
 
 
/***********Template Ends Here***********/
 
// fast io
 
#define gc getchar_unlocked
void readInt(int &x){
    register char c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
void readVlong (vlong &x){
    register char c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
void readChar ( char &x ) {
    register char c = gc();
    while (c < 33) c = gc();
    x = c;
}
void readString(char *str){
    register char c = 0;
    register int i = 0;
 
    while (c < 33)
        c = gc();
    while (c != '\n') {
        str[i] = c;
        c = gc();
        i = i + 1;
    }
    str[i] = '\0';
}
 
// fast io ends here --------------------
 
int n, q, x, y;
pii b[100005];
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
 
int bsrc(int val) {
    int hi = n, lo = 1, mid;
    while (hi>=lo) {
        mid = (hi+lo)/2;
        int cur = qry(1,1,n,mid);
        if (cur >= val) hi = mid-1;
        else lo = mid+1;
    }
    return lo;
}
 
int loc[100005], elem[100005];
 
int main()
{
    #ifdef forthright48
    freopen ( "zz_test.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48
 
 
    //scanf ("%d %d", &n, &q);
    readInt(n);
    readInt(q);
 
    for (int i=1; i<=n; i++) {
        readInt(b[i].ff);
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
        readInt(x);
        readInt(y);
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