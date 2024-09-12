#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

template<typename T = int>
inline T read() {
	T x = 0; bool f = 1; char c = getchar();
	while(isdigit(c)^1) f &= (c != 45), c = getchar();
	while(isdigit(c)) x = (x<<1) + (x<<3) + (c^48), c = getchar();
	return f ? x : -x;
}

const int N = 5005;
const int P = 998244353;
int r, c, a[N][4], b[N][4], s[N][N];
i64 inv[N], num[N], C[N][N];

inline i64 quickPow(i64 a, i64 b = P-2) {
	i64 c = 1;
	while(b) {
		if(b&1) c = c * a % P;
		a = a * a % P, b >>= 1;
	}
	return c;

}

int main() {
	int n = read();
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j < 4; ++j) a[i][j] = read();

	auto san = [=](int &m, vector<int> &vv, int sg) {
		for(int i = 1; i <= n; ++i) vv.push_back(a[i][sg]), vv.push_back(a[i][sg+2]);
		sort(vv.begin()+1, vv.end());
		m = unique(vv.begin()+1, vv.end()) - vv.begin() - 1;
		for(int i = 1; i <= n; ++i) {
			for(int j = sg; j < 4; j += 2) {
				b[i][j] = lower_bound(vv.begin()+1, vv.begin()+m+1, a[i][j]) - vv.begin();
				assert(b[i][j] <= m);
			}
		}
	};
	vector<int> rr(1, -1), cc(1, -1);
	san(r, rr, 0), san(c, cc, 1);

	for(int i = 1; i <= n; ++i) {
		int x = b[i][0], y = b[i][1];
		int p = b[i][2], q = b[i][3];
		// cerr << x << " " << y << " " << p << " " << q << endl;
		++s[x][y], --s[x][q], --s[p][y], ++s[p][q];
	}
	// for(int i = 1; i <= r; ++i)
	// 	for(int j = 1; j <= c; ++j) cerr << s[i][j] << " \n"[j == c];

	for(int i = 1; i <= r; ++i)
		for(int j = 1; j <= c; ++j)
			s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];

	// for(int i = 1; i <= r; ++i)
	//	for(int j = 1; j <= c; ++j) cerr << s[i][j] << " \n"[j == c];

	for(int i = 1; i < r; ++i) {
		int las = 0;
		for(int j = 0; j < c; ++j) {
			if(s[i][j] != s[i][j+1]) {
				num[s[i][j]] += cc[j+1] - cc[las];
				las = j+1;
			}
		}
	}

	// for(int i = 0; i <= n; ++i) cerr << num[i] << endl;
	// cerr << "=========\n";

	C[0][0] = 1;
	for(int i = 1; i <= n; ++i) {
		C[i][0] = 1;
		for(int j = 1; j <= i; ++j) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % P;
	}
	
	i64 S = 0;
	for(int i = 1; i <= n; ++i) S += num[i] * i % P, inv[i] = quickPow(C[n][i]);
	S %= P;
	for(int i = 1; i <= n; ++i) {
		i64 res = 0;
		for(int j = 1; j <= n; ++j) {
			res += (C[n][i] - C[n-j][i] + P) % P * num[j] % P;
		}
        res *= inv[i], res %= P;
		printf("%lld\n", (res % P + P) % P);
	}

	return 0;
}

