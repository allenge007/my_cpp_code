#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' or ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' and ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w*f;
}
const int maxn = 1e5 + 5;
char str[maxn];
int f[maxn][63][2][2][2], n;
int main() {
    n = read();
    scanf("%s", str + 1);
    return 0;
}