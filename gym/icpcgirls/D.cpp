//Edmonds-Karp
#include<bits/stdc++.h>
using namespace std;
const int maxn = 5005, maxm = 50005, INF = 1e9+7;
int head[maxn], ver[maxm<<1], edge[maxm<<1], Next[maxm<<1], cost[maxm<<1], tot;
void add(int x,int y,int z,int w)
{
    ver[++tot] = y, edge[tot] = z, cost[tot] = w, Next[tot] = head[x], head[x] = tot;
    ver[++tot] = x, edge[tot] = 0, cost[tot] = -w, Next[tot] = head[y], head[y] = tot;
}
int pre[maxn], incf[maxn], dis[maxn], s, t, maxflow, ans;
int n, m;
bool spfa()
{
    bool vis[maxn] = {};
    queue<int> Q;
    Q.push(s);incf[s] = INF;vis[s] = true;
    for(int i=1; i<=n; i++) dis[i] = INF;
    dis[s] = 0;
    while(!Q.empty())
    {
        int x = Q.front(); Q.pop();
        for(int i = head[x]; i; i=Next[i])
           if(edge[i])
           {
              int y = ver[i];
              if(dis[y] > dis[x]+cost[i])
              {
              	  dis[y] = dis[x]+cost[i];
              	  incf[y] = min(incf[x], edge[i]);
              	  pre[y] = i;
              	  if(!vis[y]) vis[y] = true, Q.push(y);
              }
           }
        vis[x] = false;
    }
    if(dis[t] == INF) return false;
    return true;
}
void update()
{
    int x = t;
    while(x!=s)
    {
        int i = pre[x];
        edge[i] -= incf[t];
        edge[i^1] += incf[t];
        x = ver[i^1];
    }
    maxflow+=incf[t];
    ans+=dis[t]*incf[t];
}
int main()
{
	scanf("%d%d%d%d", &n, &m, &k);
    for(int i = 1 , x; i <= n; i ++)
        for(int j = 1;j <= m;j ++) scanf("%d")    
   
    while(spfa()) update();
    printf("%d %d", maxflow, ans);
    return 0;
}