#include <bits/stdc++.h>
using namespace std;

const int N = 8e5 + 10, M = 2e6 + 10;

struct edge {
	int from, to;
	edge() { }
	edge(int a, int b) : from(a), to(b) { }
} edges[M];
int head[N], nxt[M], tot;

inline void init() {
	memset(head, -1, sizeof(head));
	tot = 0;
}

inline void add_edge(int x, int y) {
	edges[tot] = edge(x, y);
	nxt[tot] = head[x];
	head[x] = tot++;
	edges[tot] = edge(y, x);
	nxt[tot] = head[y];
	head[y] = tot++;
}

int n, m, q;

bool iscut[N];

int dfn[N], low[N], bel[N], dfs_clock;
stack<int> stk;
vector<int> dcc[N]; int total;

void Tarjan(int x, int fa) {
	dfn[x] = low[x] = ++dfs_clock;
	stk.push(x);
	
	if (!fa && head[x] == -1) {
		dcc[++total].push_back(x);
		return;
	}
	
	int cnt = 0;
	for (int i = head[x]; ~i; i = nxt[i]) {
		edge & e = edges[i];
		if (!dfn[e.to]) {
			cnt++;
			Tarjan(e.to, x);
			low[x] = min(low[x], low[e.to]);
			if (low[e.to] >= dfn[x]) {
				iscut[x] = 1;
				total++;
				for (; ; ) {
					int u = stk.top(); stk.pop();
					dcc[total].push_back(u);
					if (u == e.to) break;
				}
				dcc[total].push_back(x);
			}
		} else if (e.to != fa)
			low[x] = min(low[x], dfn[e.to]);
	}
	
	if (cnt == 1 && !fa) iscut[x] = 0;
}

vector<int> g[N];
int sz[N], siz[N], in[N], out[N], cnt;
int father[N][25], dep[N];

void dfs(int x, int fa, int depth) {
	in[x] = ++cnt;
	dep[x] = depth + 1;
	father[x][0] = fa;
	for (int i = 1; (1 << i) <= dep[x]; i++)
		father[x][i] = father[father[x][i - 1]][i - 1];
	siz[x] = sz[x];
	for (int y : g[x]) {
		if (y == fa) continue;
		dfs(y, x, depth + 1);
		siz[x] += siz[y];
	}
	out[x] = cnt;
}

int jump(int x, int k) {
	for (int i = 24; i >= 0; i--)
		if (k >= (1 << i)) {
			k -= (1 << i);
			x = father[x][i];
		}
	return x;
}

void build() {
	memset(dfn, 0, sizeof(int) * (n + 1));
	memset(low, 0, sizeof(int) * (n + 1));
//	memset(vis, 0, sizeof(int) * (n + n + 1));
	memset(iscut, 0, sizeof(bool) * (n + n + 1));
	while (!stk.empty()) stk.pop();
	total = dfs_clock = 0;
	
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) Tarjan(i, 0);
		
	for (int i = 1; i <= n + total; i++) g[i].clear();
	memset(bel, 0, sizeof(int) * (n + total + 1));
	memset(sz, 0, sizeof(int) * (n + total + 1));
	memset(siz, 0, sizeof(int) * (n + total + 1));
	memset(in, 0, sizeof(int) * (n + total + 1));
	memset(out, 0, sizeof(int) * (n + total + 1));
	
//	cout << "cut : " << endl;
	for (int i = 1; i <= n; i++)
		if (iscut[i]) {
			sz[i] = 1;
			bel[i] = i;
//			cout << i << " ";
		}
//	cout << endl;
	for (int i = 1; i <= total; i++) {
		sz[n + i] = dcc[i].size();
//		cout << "dcc " << n + i << ": ";
		for (int x : dcc[i]) {
//			cout << x << " ";
			if (iscut[x]) {
				g[x].push_back(i + n);
				g[i + n].push_back(x);
				sz[n + i]--;
			} else
				bel[x] = i + n;
		}
//		cout << endl;
	}
	
	cnt = 0;
	dfs(n + 1, 0, 1);
	
//	cout << siz[n + 1] << endl;
//	for (int i = 1; i <= n; i++)
//		cout << bel[i] << ' ';
//	cout << endl;
	
//	for (int i = 1; i <= n; i++)
//		if (iscut[i]) cout << "sz " << i << ' ' << sz[i] << endl;
//	for (int i = 1; i <= total; i++)
//		cout << "sz " << n + i << ' ' << sz[n + i] << endl;
	for (int i = 1; i <= total; i++) dcc[i].clear();
}

int query(int x, int y) {
	x = bel[x];
	y = bel[y];
//	cout << x << ' ' << y << endl;
	if (x == y) return sz[x];
	if (dep[x] > dep[y]) swap(x, y);
	if (in[x] <= in[y] && out[x] >= in[y]) {
		int u = jump(y, dep[y] - dep[x] - 1);
		return siz[u] - siz[y] + sz[y] + sz[x];
	}
	return n - siz[x] - siz[y] + sz[x] + sz[y];
}

int T;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		
		init();
		
		for (int i = 1; i <= m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			add_edge(x, y);
		}
		
		build();
		
		scanf("%d", &q);
		for (int i = 1; i <= q; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			printf("%d\n", query(x, y));
		}
		
		for (int i = 1; i <= n + total; i++)
			memset(father[i], 0, sizeof(father[i]));
		memset(dep, 0, sizeof(int) * (n + total + 1));
	}
}