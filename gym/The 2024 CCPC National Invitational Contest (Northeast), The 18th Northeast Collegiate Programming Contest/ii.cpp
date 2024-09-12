#include <bits/stdc++.h>
using namespace std;
 
typedef long long i64;
const int maxn = 100005;
const int mod = 998244353;
int n, k;
i64 f[maxn], fac[maxn], fap[maxn];
 
int main() {
	cin >> n >> k;
 
//	int st = clock();
 
	fac[0] = 1;
	for(register int i = 1; i <= k; ++i) fac[i] = fac[i-1] * i % mod;
	for(register int i = 1; i <= k; ++i) {
        fap[i] = fac[i];
		for(register int j = 1; j < i; ++j) {
			fap[i] = (fap[i] - fac[j] * fap[i-j]) % mod;
		}
	}
 
	f[k] = fac[k];
	for(register int i = k+1; i <= n; ++i) {
		for(register int j = i-k; j < i; ++j) {
			f[i] = (f[i] + fap[i-j] * f[j]) % mod;
		}
	}
	cout << (f[n] + mod) % mod << endl;
 
//	int ed = clock();
 
//	cout << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
	
	return 0;
}