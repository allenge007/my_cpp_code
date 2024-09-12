#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
const int N=10000;
const db pi=acos(-1.0);
#define lowbit(x) (x)&(-x)
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define fir first
#define sec second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define maxd 1000000007
#define eps 1e-8
int n,m,tot=0,val[100100],rob[100100],hol[100100],tot1=0;
ll f[100100];
pii p[100100];

struct fenwick_tree{
	int a[100100];
	
	void modify(int x,int p)
	{
		for (int i=p;i<=tot;i+=lowbit(i)) a[i]=(a[i]+x)%maxd;
	}
	
	int query(int p)
	{
		int ans=0;
		for (int i=p;i;i-=lowbit(i)) ans=(ans+a[i])%maxd;
		return ans;
	}
}tr;

int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

bool cmp(pii p,pii q) {return ((p.fir<q.fir) || ((p.fir==q.fir) && (p.sec>q.sec)));}

int main()
{
	n=read();m=read();
	rep(i,1,n) rob[i]=read();
	rep(i,1,m) hol[i]=read();
	rep(i,1,n)
	{
		if ((rob[i]<=hol[1]) || (rob[i]>=hol[m])) continue;
		int pos=lower_bound(hol+1,hol+1+m,rob[i])-hol;
		if (hol[pos]==rob[i]) continue;
		p[++tot1]=mp(rob[i]-hol[pos-1],hol[pos]-rob[i]);
		val[++tot]=hol[pos]-rob[i];
	}
	//rep(i,1,n) cout << p[i].fir << " " << p[i].sec << endl;
	sort(val+1,val+1+tot);
	tot=unique(val+1,val+1+tot)-val-1;
	rep(i,1,tot1) p[i].sec=lower_bound(val+1,val+1+tot,p[i].sec)-val;
	sort(p+1,p+1+tot1,cmp);
	tot1=unique(p+1,p+1+tot1)-p-1;
	//cout << endl;
	// rep(i,1,tot1) cout << p[i].fir << " " << p[i].sec << endl;
	rep(i,1,tot1)
	{
		f[i]=tr.query(p[i].sec-1)+1;
		tr.modify(f[i],p[i].sec);
	}
	//rep(i,1,tot1) cout << f[i] << " ";cout << endl;
	ll ans=1;
	rep(i,1,tot1) ans=(ans+f[i])%maxd;
	printf("%lld",ans);
	return 0;
}
