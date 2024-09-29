#include <bits/stdc++.h>

using namespace std;
const int maxn = 10005;
int n, m, head[maxn], Next[maxn * maxn], ver[maxn * maxn], edge[maxn * maxn], tot;
struct node{
	int x, y;
	void read() {
		scanf("%d%d", &x, &y);
	}
}poi[maxn];
struct station {
	int x, y, r, t;
	void read() {
		scanf("%d%d%d%d", &x, &y, &r, &t);
	}
}sta[maxn];
bool in(node p, station s) {
	int sx = s.x - s.r, sy = s.y - s.r, ex = s.x + s.r, ey = s.y + s.r;
	if(p.x >= sx && p.x <= ex && p.y >= sy && p.y <= ey) return 1;
	return 0;
}
void add(int x, int y, int val) {
	ver[++ tot] = y, edge[tot] = val, Next[tot] = head[x], head[x] = tot;
}
const long long INF = 1e17;
long long dis[maxn];
bool vis[maxn];
void spfa() {
	for(int i = 1; i <= n + m; i ++) dis[i] = INF;
	dis[1] = 0, vis[1] = 1;
	queue<int> q;
	q.push(1);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i = head[u]; i; i = Next[i]) {
			if(dis[ver[i]] > dis[u] + edge[i]) {
				dis[ver[i]] = dis[u] + edge[i];
				if(!vis[ver[i]]) {
					vis[ver[i]] = 1;
//					if(ver[i] == n) return ;
					q.push(ver[i]);
				}
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) poi[i].read();
	for(int i = 1; i <= m; i ++) sta[i].read();
	for(int i = 1; i <= m; i ++) {
		vector<int> Add;
		for(int j = 1; j <= n; j ++) {
			if(in(poi[j], sta[i])) {
				add(j, n + i, sta[i].t);
				add(n + i, j, sta[i].t);
			} 
		}
	}
	spfa();
	if(dis[n] == INF) printf("Nan\n");
	else printf("%lld\n", dis[n] / 2);
	return 0;
}