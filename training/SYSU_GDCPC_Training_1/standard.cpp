#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<vector>
#include<bitset>
#include<ctime>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
char buf[1<<20],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
inline int read()
{
	int s=0,f=1;
	char x=getchar();
	while(!isdigit(x))f=(x=='-'?-1:1),x=getchar();
	while(isdigit(x))s=s*10+x-'0',x=getchar();
	return s*f;
}
#define reaD read
vector<int> e[200005];
int dep[200005];
int fa[200005][20];
void dfs(int x,int f)
{
	for(int i=1;i<=17;i++)
	fa[x][i]=fa[fa[x][i-1]][i-1];
	for(auto to:e[x])
	{
		if(to==f)continue;
		fa[to][0]=x;
		dep[to]=dep[x]+1;
		dfs(to,x);
	}
}
int lca(int x,int y)
{
	if(x==y)return x;
	if(dep[x]<dep[y])swap(x,y);
	for(int i=17;i>=0;i--)
	if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=17;i>=0;i--)
	if(fa[x][i]!=fa[y][i])
	x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int dis(int x,int y)
{
    int l=lca(x,y);
    return dep[x]+dep[y]-2*dep[l];
}
vector<pii> E;
int f[200005];
int s1[200005],s2[200005];
int dia[200005];
vector<int> d[200005];
map<pii,bool> m;
int ans[200005];
int mxdia;
int fd(int x)
{
    return x==f[x]?x:f[x]=fd(f[x]);
}
void mg(int x,int y,int id)
{
    // cout<<"mg: "<<x<<" "<<y<<" "<<id<<endl;
    // m[mp(x,y)]=m[mp(y,x)]=1;
    // d[id].pb(mp(x,y));
    x=fd(x),y=fd(y);
    f[x]=y;
    int ts1=s1[y],ts2=s2[y];
    if(dia[x]>dia[y])
    dia[y]=dia[x],ts1=s1[x],ts2=s2[x];

    int ndia=dis(s1[x],s1[y]);
    if(ndia>dia[y])
    dia[y]=ndia,ts1=s1[x],ts2=s1[y];

    ndia=dis(s1[x],s2[y]);
    if(ndia>dia[y])
    dia[y]=ndia,ts1=s1[x],ts2=s2[y];

    ndia=dis(s2[x],s1[y]);
    if(ndia>dia[y])
    dia[y]=ndia,ts1=s2[x],ts2=s1[y];

    ndia=dis(s2[x],s2[y]);
    if(ndia>dia[y])
    dia[y]=ndia,ts1=s2[x],ts2=s2[y];

    s1[y]=ts1,s2[y]=ts2;

    mxdia=max(mxdia,dia[y]);
    // ans[id]=max(ans[id],mxdia);

    return ;
}
void init(int n)
{
    for(int i=1;i<=n;i++)
    f[i]=i,s1[i]=s2[i]=i,dia[i]=0;
    mxdia=0;
}
int vis[200005];
int main()
{
    int T=read();
    while(T--)
    {
        int n=read(),q=read();
        for(int i=1;i<n;i++)
        {
            int x=read(),y=read();
            e[x].pb(y);
            e[y].pb(x);
            if(x>y)swap(x,y);
            E.pb(mp(x,y));
        }
        fa[1][0]=1;
        dfs(1,1);
        init(n);
        for(int i=1;i<=q;i++)
        {
            int x=read(),y=read();
            if(!vis[x])
            {
                vis[x]=1;
                d[i].pb(x);
                for(auto j:e[x])
                {
                    if(j!=fa[x][0]&&vis[j])
                    mg(j,x,i);
                }
            }
            if(!vis[y])
            {
                vis[y]=1;
                d[i].pb(y);
                for(auto j:e[y])
                {
                    if(j!=fa[y][0]&&vis[j])
                    mg(j,y,i);
                }
            }
            int l=lca(x,y);
            while(dep[fd(x)]>dep[l])
            {
                int tmp=fa[fd(x)][0];
                mg(fd(x),fa[fd(x)][0],i);
                if(!vis[tmp])
                {
                    d[i].pb(tmp);
                    vis[tmp]=1;
                    for(auto o:e[tmp])
                    {
                        if(o!=fa[tmp][0]&&vis[o])
                    mg(o,tmp,i);
                    else if(o==fa[tmp][0]&&vis[o])
                    mg(tmp,o,i);
                    }
                }
            }
            while(dep[fd(y)]>dep[l])
            {
                int tmp=fa[fd(y)][0];
                mg(fd(y),fa[fd(y)][0],i);
                if(!vis[tmp])
                {
                    d[i].pb(tmp);
                    vis[tmp]=1;
                    for(auto o:e[tmp])
                    {
                        if(o!=fa[tmp][0]&&vis[o])
                    mg(o,tmp,i);
                    else if(o==fa[tmp][0]&&vis[o])
                    mg(tmp,o,i);
                    }
                }
            }
            
            ans[i]=max(ans[i],mxdia);
        }
        // for(int i=1;i<=q;i++)
        // printf("%d\n",ans[i]);
        init(n);
        for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            int tmp=i;
            for(auto o:e[tmp])
            {
                if(o!=fa[tmp][0]&&!vis[o])
                mg(o,tmp,q);
                else if(o==fa[tmp][0]&&!vis[o])
                mg(tmp,o,q);
            }
        }
        for(int i=q;i>=2;i--)
        {
            for(auto j:d[i])
            {
                vis[j]=0;
                int tmp=j;
                for(auto o:e[tmp])
                {
                    if(o!=fa[tmp][0]&&!vis[o])
                    mg(o,tmp,i-1);
                    else if(o==fa[tmp][0]&&!vis[o])
                    mg(tmp,o,i-1);
                }
            }
            ans[i-1]=max(ans[i-1],mxdia);
        }
        for(int i=1;i<=q;i++)
        printf("%d\n",ans[i]+1),d[i].clear();
        for(int i=1;i<=n;i++)
        vis[i]=0,e[i].clear(),dep[i]=0;
        E.clear(),m.clear();
        for(int i = 1; i <= n; i ++)
            for(int j = 0; j < 20; j ++) 
                fa[i][j]=0; 
    }
    system("pause");
	return 0;
}