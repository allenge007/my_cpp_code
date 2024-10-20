#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e6 + 5;
const long long INF = 1e18;
int R[maxn], B[maxn], n;
long long f[maxn], g[maxn], F[maxn];
int main() {
    scanf("%d", &n);
    for(int i = 0; i < (1 << n); i ++) scanf("%d", &R[i]), f[i] = R[i];
    for(int i = 0; i < (1 << n); i ++) scanf("%d", &B[i]), g[i] = B[i];
    for (int i = 1; i < (1 << n); i <<= 1) 
		for (int j = 0; j < (1 << n); j += i << 1) 
			for (int k = 0; k < i; k++) {
				f[i + j + k] += f[j + k];
				g[i + j + k] += g[j + k];
			}
    for(int i = 0; i < (1 << n); i ++) F[i] = INF;
    F[0] = min(f[0], g[0]);
    for(int i = 0; i < (1 << n); i ++) {
        for(int j = 0; j < n; j ++) {
            if(i >> j & 1) {
                int t = i ^ (1 << j);
                F[i] = min(F[i], F[t] + min(f[i] - f[t], g[i] - g[t]));
            }
        }
    }
    printf("%lld\n", F[(1 << n) - 1]);
    return 0;
}