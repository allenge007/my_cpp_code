#include <bits/stdc++.h>
using namespace std;

const int N = 1000006;
int l[N], r[N], to[N], vst[N], wst[N], c[N];

inline int solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> l[i] >> r[i];
    for(int i = 1; i <= n; ++i) vst[i] = wst[i] = c[i] = 0;

    for(int i = 1; i <= n; ++i) {
        if(vst[l[i]]) {
            if(vst[r[i]]) return 0;
            else vst[r[i]] = 1, to[r[i]] = l[i];
        }
        else vst[l[i]] = 1, to[l[i]] = r[i];
    }

    int res = 1, col = 0;
    vector<int> vv;
    for(int i = 1; i <= n; ++i) {
        if(wst[i]) continue;
        int num = 0, p = i;
        col ++;
        while(!wst[p]) c[p] = col, wst[p] = ++num, p = to[p];
        if(c[p] == col) res &= num - wst[p] + 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int cas;
    cin >> cas;
    while(cas--) printf("%d\n", solve());
    return 0;
}