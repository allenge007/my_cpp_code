#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
const int maxn = 5e5 + 5;
char str[maxn];
int n, T, c[3], vis[maxn];
inline int ex(char s) {
    if(s == 'R') return 0;
    if(s == 'P') return 1;
    return 2;
}
void output(int x) {
    if(x == 0) putchar('R');
    else if(x == 1) putchar('P');
    else putchar('S');
}
void solve(int l, int r) {
    int win = 0, lose = 0;
    if(c[0] == 0 && c[1] == 0) win = 1, lose = 0;
    else if(c[0] == 0 && c[2] == 0) win = 0, lose = 2;
    else if(c[1] == 0 && c[2] == 0) win = 2, lose = 1;
    int cnt = l;
    for(int i = l; i <= r; i ++) if(ex(str[i]) == lose) vis[max(cnt, i - T)] = 1, cnt ++;
    for(int i = l; i <= r; i ++)
        if(vis[i]) output(lose);
        else output(win);
}
int main() {
    scanf("%d%d%s", &n, &T, str + 1);
    int las = 1;
    c[ex(str[1])] ++;
    for(int i = 2; i <= n; i ++) {
        c[ex(str[i])] ++;
        if(c[0] && c[1] && c[2]) {
            for(int j = 0; j < 3; j ++) if(j != ex(str[i])) c[j] = 0;
            solve(las, i - 1), las = i;
        }
    }
    int flag = 0;
    for(int i = 0; i < 3; i ++) if(c[i]) flag ++;
    if(flag == 1) for(int i = las; i <= n; i ++) putchar(str[i]);
    else {
        for(int i = 0; i < 3; i ++) {
            if(!c[i]) c[i] = 1;
            else c[i] = 0;
        }
        solve(las, n);
    }
    return 0;
}