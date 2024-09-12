#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;
const int maxn = 205;
int n, a[maxn];
long long f[maxn][256], ans;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    f[0][0] = 1;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			for(int k = 0; k < 256; k ++){
				if(i ^ j) f[j][k] = (f[j - 1][k] + f[j - 1][k ^ a[j]]) % mod;
				else f[j][k] = f[j - 1][k];
			}
		}
		for(int k = a[i]; k < 256; k ++)
        	ans += f[n][k], ans %= mod;
	}
    printf("%lld", ans);
	return 0;
}