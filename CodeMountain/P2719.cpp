#include <bits/stdc++.h>

using namespace std;
const int maxn = 630;
double f[maxn][maxn];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n / 2; i++)
        f[0][i] = f[i][0] = 1;
    for (int i = 1; i <= n / 2; i++)
        for (int j = 1; j <= n / 2; j++) {
            f[i][j] = f[i - 1][j] / 2 + f[i][j - 1] / 2;
        }
    printf("%.4lf", f[n / 2][n / 2]);
    return 0;
}