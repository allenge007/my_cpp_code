#include<bits/stdc++.h>
using namespace std;
const int maxn = 305;
const long long INF = 1e15 + 7;
long long d[maxn][maxn], m[maxn][maxn], p[maxn];
int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            p[i] = d[i][j] = m[i][j] = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j]; 
            if (d[i][j] == -1) d[i][j] = INF;
            if (i == j) d[i][j] = m[i][j] = 0;
            m[i][j] = d[i][j];
        }
    }
    for (int k = 1;k <= n;k++) {
        for (int i = 1;i < k;i++)
            for (int j = i + 1;j < k;j++)
                if (d[i][j] + m[i][k] + m[k][j] < p[i])
                    p[i] = p[j] = p[k] = d[i][j] + m[i][k] + m[k][j];

        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
    }
    for (int i = 1; i <= n; i++) cout << ((p[i] == INF) ? -1 : p[i]) << "\n";
    return 0;
}