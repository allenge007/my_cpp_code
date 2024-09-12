//树链剖分 2020.8.19
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, mod = 998244353;
int id[maxn], f[maxn], d[maxn], siz[maxn], son[maxn], top[maxn], val[maxn], cnt;
int head[maxn], Next[maxn<<1], ver[maxn<<1], tot, xx[maxn], yy[maxn], iid[maxn], LCA[maxn];
struct node{
	int l, r;
	int sum, add;
}t[maxn<<2];
int N, M, root, a[maxn];
//以下为区间修改线段树 
void build(int p, int l, int r){
	t[p].l = l, t[p].r = r;
	if(l == r){
		t[p].sum = val[l];
		return ;
	}
	int mid = (l+r)>>1;
	build(p<<1, l, mid);
	build(p<<1|1, mid+1, r);
	t[p].sum = (t[p<<1].sum + t[p<<1|1].sum)%mod;
}
void spread(int p){
	if(t[p].add){
		t[p<<1].sum = (t[p<<1].sum + t[p].add*(t[p<<1].r-t[p<<1].l+1)%mod)%mod;
		t[p<<1|1].sum = (t[p<<1|1].sum + t[p].add*(t[p<<1|1].r-t[p<<1|1].l+1)%mod)%mod;
		t[p<<1].add = (t[p<<1].add + t[p].add)%mod;
		t[p<<1|1].add = (t[p<<1|1].add + t[p].add)%mod;
		t[p].add = 0;
	}
}
void change(int p, int l, int r, int x){
	if(t[p].l >= l and t[p].r <= r){
		t[p].sum = (t[p].sum + x*(t[p].r-t[p].l+1)%mod)%mod;
		t[p].add = (t[p].add + x)%mod;
		return ;
	}
	spread(p);
	int mid = (t[p].l + t[p].r)>>1;
	if(l <= mid) change(p<<1, l, r, x);
	if(r > mid) change(p<<1|1, l, r, x);
	t[p].sum = (t[p<<1].sum + t[p<<1|1].sum)%mod;
}
int ask(int p, int l, int r){
	if(t[p].l >= l and t[p].r <= r) return t[p].sum;
	spread(p);
	int mid = (t[p].l + t[p].r)>>1;
	int v = 0;
	if(l <= mid) v = (v + ask(p<<1, l, r))%mod;
	if(r > mid) v = (v + ask(p<<1|1, l, r))%mod;
	return v;
}
//邻接链表建边 
void add(int x, int y){
	ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}
//处理出f,d,siz,son数组 
void dfs1(int x, int fa, int deep){
	f[x] = fa, d[x] = deep, siz[x] = 1;
	for(int i=head[x]; i; i=Next[i]){
		int y = ver[i];
		if(y == fa) continue;
		dfs1(y, x, deep+1);
		siz[x] += siz[y];
		if(siz[y] > siz[son[x]] or son[x] == 0) son[x] = y;
	}
	return ;
}
//处理出top,id数组 
void dfs2(int x, int t){
	top[x] = t, id[x] = ++cnt, val[cnt] = a[x];
	if(!son[x]) return ;
	dfs2(son[x], t);
	for(int i=head[x]; i; i=Next[i]){
		int y = ver[i];
		if(y == son[x] or y == f[x]) continue;
		dfs2(y, y);
	}
	return ;
}
int lca(int x, int y) {
	while(top[x] != top[y]){//如果x,y不在一条重链上 
		if(d[top[x]] < d[top[y]]) swap(x, y);//保证x所在的重链始终比y更深 
		x = f[top[x]];//x上升到重链顶端的父节点 
	}
	if(d[x] > d[y]) swap(x, y);//保证x始终比y浅(即保证x的id始终比y小，x在连续序列上始终在y前) 
	return x;
}
void updRange(int x, int y, int z){
	while(top[x] != top[y]){//如果x,y不在一条重链上 
		if(d[top[x]] < d[top[y]]) swap(x, y);//保证x所在的重链始终比y更深 
		change(1, id[top[x]], id[x], z);//区间修改链 
		x = f[top[x]];//x上升到重链顶端的父节点 
	}
	if(d[x] > d[y]) swap(x, y);//保证x始终比y浅(即保证x的id始终比y小，x在连续序列上始终在y前) 
	change(1, id[x], id[y], z);//区间修改 
}
//同上 
int qRange(int x, int y){
	int ans = 0;
	while(top[x] != top[y]){
		if(d[top[x]] < d[top[y]]) swap(x, y);
		ans = (ans + ask(1, id[top[x]], id[x]))%mod;
		x = f[top[x]];
	}
	if(d[x] > d[y]) swap(x, y);
	ans = (ans + ask(1, id[x], id[y]))%mod;
	return ans;
}
void updSon(int x, int z){
	change(1, id[x], id[x] + siz[x] - 1, z);//一个子树的编号一定是连续的，直接区间修改即可 
}
int qSon(int x){
	return ask(1, id[x], id[x] + siz[x] - 1);//同上 
}
int main(){
    root = 1;
	scanf("%d", &N);
	for(int i=1; i<N; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y); add(y, x);
	}
	dfs1(root, 0, 1);
	dfs2(root, root);
	build(1, 1, N);
    scanf("%d", &M);
	for(int i = 1; i <= M; i ++) {
        scanf("%d%d", &xx[i], &yy[i]);
        // cout << xx[i] << " " << yy[i] << endl;
        LCA[i] = lca(xx[i], yy[i]);
        iid[i] = i;
    }
    sort(iid + 1, iid + M + 1, [](int x, int y){
        return d[LCA[x]] > d[LCA[y]];
    });
    vector<int> ans;
    for(int i = 1; i <= M; i ++) {
        // cout << LCA[iid[i]] << endl;
        if(qRange(xx[iid[i]], yy[iid[i]]) == 0) {
            ans.push_back(LCA[iid[i]]);
            updRange(LCA[iid[i]], LCA[iid[i]], 1);
        }
    }
    printf("%d\n", ans.size());
    for(auto it : ans) printf("%d ", it);
	return 0;
}