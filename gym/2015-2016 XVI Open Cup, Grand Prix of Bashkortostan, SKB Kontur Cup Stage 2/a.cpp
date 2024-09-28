#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pci = pair<char, int>;

template <typename T = int>
constexpr T read() {
	T x = 0; bool f = 1; char c = getchar();
	while(isdigit(c)^1) f &= (c != 45), c = getchar();
	while(isdigit(c)) x = (x<<1) + (x<<3) + (c^48), c = getchar();
	return f ? x : -x;
}

const int N = 3005;
bool vstr[N], vstc[N];
char s[N][N];
int hasr[N], hasc[N], numr[N][128], numc[N][128];
multiset<pci> sr[N], sc[N];
tuple<char, int, char> ans[N << 1];

int main() {
	int n = read();
	for(int i = 1; i <= n; i++, getchar())
		for(int j = 1; j <= n; j++) s[i][j] = getchar();

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(s[i][j] != '?') hasr[i] += !numr[i][s[i][j]]++, hasc[j] += !numc[j][s[i][j]]++;

	int cur = n + n, foo = 1, bar = 1;
	while(foo || bar) {
		foo = bar = 0;
		for(int i = 1; i <= n; i++) {
			if(vstr[i] || hasr[i] != 1) continue;

			char c = 0;
			for(int j = 'a'; j <= 'z'; j++)
				if(numr[i][j]) { c = j; break; }

			for(int j = 1; j <= n; ++j)
				if(s[i][j] == c) hasc[j] -= !--numc[j][c];

			foo = vstr[i] = 1, ans[cur--] = { 'h', i, c };
		}
		for(int i = 1; i <= n; i++) {
			if(vstc[i] || hasc[i] != 1) continue;

			char c = 0;
			for(int j = 'a'; j <= 'z'; j++)
				if(numc[i][j]) { c = j; break; }

			for(int j = 1; j <= n; ++j)
				if(s[j][i] == c) hasr[j] -= !--numr[j][c];

			bar = vstc[i] = 1, ans[cur--] = { 'v', i, c };
		}
	}

	for(int i = 1; i <= n; ++i)
		if(!vstr[i]) ans[cur--] = { 'h', i, 'a' };
	for(int i = 1; i <= n; ++i)
		if(!vstc[i]) ans[cur--] = { 'v', i, 'a' };

	for(int i = 1; i <= n + n; ++i) printf("%c %d %c\n", get<0>(ans[i]), get<1>(ans[i]), get<2>(ans[i]));
	return 0;
}

