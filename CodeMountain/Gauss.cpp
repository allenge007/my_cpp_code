#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' or ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' and ch <= '9') w = w*10 + ch - '0', ch = getchar();
    return w*f;
}
const int maxn = 105;
double a[maxn][maxn];
int N;
int main() {
    N = read();
    for(int i = 1; i <= N; i ++)
        for(int j = 1; j <= N + 1; j ++)
            scanf("%lf", &a[i][j]);
    for(int i = 1; i <= N; i ++) {
        int maxi = i;
        for(int j = i + 1; j <= N; j ++) 
            if(fabs(a[j][i]) > fabs(a[maxi][i]))
                maxi = j;
        if(i != maxi) swap(a[i], a[maxi]);
        if(!a[i][i]) return printf("No Solution"), 0;
        for(int j = 1; j <= N; j ++) {
            if(j ^ i) {
                for(int k = N + 1; k >= i; k --)
                    a[j][k] -= a[j][i] / a[i][i] * a[i][k];
            }
        }
    }
    for(int i = 1; i <= N; i ++) printf("%.2lf\n", a[i][N + 1] / a[i][i]);
    return 0;
}