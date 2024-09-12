#include <bits/stdc++.h>
using namespace std;

#define max(x,y) (x > y ? x : y)

using i64 = long long;

template<typename T = int>
inline T read() {
	T x = 0; bool f = 1; char c = getchar();
	while(isdigit(c)^1) f &= (c != 45), c = getchar();
	while(isdigit(c)) x = (x<<1) + (x<<3) + (c^48), c = getchar();
	return f ? x : -x;
}

const int maxn = 100005;
const int maxm = 5000005;
int n, m, x, y, l, r, v, st[20][maxn];
i64 ans;
unsigned X, Y, Z, W, f[maxm * 3];

int RNG() {
	X ^= (X << 11);
	X ^= (X >> 4);
	X ^= (X << 5);
	X ^= (X >> 14);
	W = X ^ Y ^ Z;
	X = Y, Y = Z, Z = W;
	return Z;
}

int main() {
	int cas = read();
	while(cas--) {
		n = read(), m = read(), X = read(), Y = read(), Z = read();
		for(int i = 1; i <= 3 * m; ++i) f[i] = RNG();
		for(int i = 1; i <= (n<<1); ++i) tag[i] = 0;
		for(int i = 1; i <= m; ++i) {
			x = f[3*i-2] % n + 1;
			y = f[3*i-1] % n + 1;
			l = x < y ? x : y;
			r = x > y ? x : y;
			v = f[3*i] & ((1<<30)-1);
            int p = __lg(r - l  +1);
            st[p][l] = max(st[p][l], v);
            st[p][r - (1 << p) + 1] = max(st[p][r - (1 << p) + 1], v);
		}
        for(int i = 19; i; i --)
            for(int j = 1; j + (1 << i) - 1 <= n; j ++) {
                st[i - 1][j] = max(st[])
            }
		ans = 0;
		cout << ans << endl;
	}
	return 0;
}


