#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 5;
char str[maxn];
int n, nxt[maxn], pre[maxn], ourr[maxn], t[maxn];
deque<int> q[maxn], q2[maxn];
int main() {
    scanf("%d%s", &n, str + 1);
    for(int i = 1; i <= n; i ++) {
        nxt[i] = i + 1, pre[i] = i - 1;
    }
    for(int i = 1; i <= n; i ++) {
        int x = 0;
        if(str[i] == '0') continue;
        for(int j = 0; j < 20 and i + j <= n; j ++) {
            x = (x << 1) + str[i + j] - '0';
            t[x] ++;
            q[x].push_back(i);
            q2[i].push_back(x);
        }
    }
    for(int i = 1; i <= n; i ++) {
        if(t[i]) {
            printf("%d %d\n", *q[i].begin(), t[i]);
            for(int j = *q[i].begin(), k = 0; k < 20 and j <= n; j = nxt[j]) {
                for(auto it = q2[j].begin(); it != q2[j].end(); ++ it) {
                    t[*it] --;
                    q[*it].pop_front();
                }
            }
        }
    }
    return 0;
}