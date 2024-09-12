#include <bits/stdc++.h>
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
const int maxn = 1e6 + 5;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' or ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' and ch <= '9') w = (w << 1) + (w << 3) + ch - '0', ch = getchar();
    return w;
}
int T, n;
int Begin[maxn], End[maxn], tail, cnt, tot, ver[maxn << 1], Next[maxn << 1], head[maxn], in[maxn];
long long times[maxn];
int id[maxn], A[maxn];
pair<int, int> B[maxn];
bool vis[maxn];
unordered_map<int, long long> Cnt2;
void add(int x, int y) {
    ver[++ tot] = y, Next[tot] = head[x], head[x] = tot;
}
void solve() {
    for(int i = 1; i <= n; i ++) times[i] = 0, vis[i] = 0;
    vector<pair<int, long long>> seq;
    queue<int> q;
    times[n] = 1;
    for(int i = 1; i <= n; i ++) if(!in[i]) q.push(i);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        bool flag = 0;
        for(int i = head[x]; i; i = Next[i]) {
            int y = ver[i];
            in[y] --;
            times[y] += times[x];
            if(in[y] == 0) q.push(y);
            flag = 1;
        }
        if(!flag) {
            seq.push_back(make_pair(id[x], times[x]));
        }
    }
    sort(seq.begin(), seq.end());
    long long lenth = 0;
    int top = 0, lim = seq.size();
    for(int i = 0; i < lim; i ++) {
        lenth += (long long)seq[i].second * (End[seq[i].first] - Begin[seq[i].first] + 1);
    }
    long long maxNum = 0;
    for(int i = 0; i < lim; i ++) {
        for(int j = Begin[seq[i].first]; j <= End[seq[i].first]; j ++) {
            Cnt2[A[j]] += seq[i].second;
            if(Cnt2[A[j]] > lenth / 2) {
                maxNum = Cnt2[A[j]];
            }
        }
    }
    Cnt2.clear();
    if(maxNum) {
        printf("%lld\n", (lenth - maxNum) * 2ll);
        return ;
    }
    printf("%lld\n", lenth);
}
int main() {
    T = read();
    while(T --) {
        n = read();
        for(register int i = 1; i <= n; i ++) {
            int opt = read();
            if(opt == 1) {
                int k = read();
                Begin[++ tail] = cnt + 1;
                for(int j = 1; j <= k; j ++) {
                    int x = read();
                    A[++ cnt] = x;
                }
                End[tail] = cnt;
                id[i] = tail;
            }
            else {
                int x = read(), y = read();
                add(i, x), add(i, y);
                in[x] ++, in[y] ++;
            }
        }
        solve();
        for(register int i = 1; i <= tot; i ++) ver[i] = Next[i] = 0;
        for(register int i = 1; i <= n; i ++) head[i] = 0, in[i] = 0;
        cnt = tot = tail = 0;
    }
    return 0;
}