#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' or ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' and ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
const int maxn = 2505;
int n, k, s[maxn], e[maxn], v[maxn];
int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i ++) scanf("%d%d%d", &s[i], &e[i], &v[i]);
    
    return 0;
}