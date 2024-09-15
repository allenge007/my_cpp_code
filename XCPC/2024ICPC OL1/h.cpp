#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll inf = 1e16;
const int N = 1010;

struct edge {
    int from, to, flow, cap, cost, next;
    edge() { }
    edge(int a, int b, int c, int d, int e, int f) : from(a), to(b), flow(c), cap(d), cost(e), next(f) { }
};
vector<edge> edges;
int head[N], tot;

inline void init() {
    memset(head, -1, sizeof(head));
    edges.clear();
}

inline void add_edge(int x, int y, int z, int k) {
    edges.emplace_back(x, y, 0, z, k, head[x]);
    head[x] = edges.size() - 1;
    edges.emplace_back(y, x, 0, 0, -k, head[y]);
    head[y] = edges.size() - 1;
}

int cur[N], s, t;
ll dist[N];
bool inq[N];

bool SPFA() {
    for (int i = 1; i <= t; i++) {
        dist[i] = inf;
        inq[i] = 0;
    }
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    inq[s] = 1;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        inq[x] = 0;
        cur[x] = head[x];
        for (int i = head[x]; ~i; i = edges[i].next) {
            edge & e = edges[i];
            if (e.cap > e.flow && dist[e.to] > dist[x] + e.cost) {
                dist[e.to] = dist[x] + e.cost;
                if (!inq[e.to]) {
                    inq[e.to] = 1;
                    q.push(e.to);
                }
            }
        }
    }
    return dist[t] != inf;
}

bool vis[N];

int dfs(int x, int a) {
    if (x == t || a == 0) return a;
    vis[x] = 1;
    int flow = 0, f;
    for (int & i = cur[x]; ~i; i = edges[i].next) {
        edge & e = edges[i];
        if (e.cap > e.flow && (f = dfs(e.to, min(e.cap - e.flow, a)))) {
            e.flow += f;
            edges[i ^ 1].flow -= f;
            cost += e.cost * f;
            flow += f;
            a -= f;
            if (a == 0) break;
        }
    }
    vis[x] = 0;
    return flow;
}

int main() {
    return 0;
}