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

const int N = 100005;
// const int M = 1000005;
int dom[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int Y, las[26], pre[1000005][10], nxt[1000005][26];
char s[1000005], date[N][10], name[N][25];
long long num[1000005];
signed main() {
	for(int i = 1; i <= 12; ++i)
		for(int j = 1; j <= dom[i]; ++j) sprintf(date[++Y], "%02lld%02lld", i, j);

	int cas;
    scanf("%d", &cas);
	while(cas--) {
		int n, m;
		scanf("%d%d", &n, &m);
		int M = m+1;
		scanf("%s", s+1);
		for(int i = 1; i <= n; ++i) scanf("%s", name[i]+1);

		for(int i = 0; i <= M; ++i) {
			num[i] = 0;
			for(int j = 0; j < 10; ++j) pre[i][j] = 0;
			for(int j = 0; j < 26; ++j) nxt[i][j] = 0;
		}

		for(int i = 0; i < 26; ++i) las[i] = 0;
		for(int i = 1; i <= M; ++i) {
			for(int j = 0; j < 10; ++j) pre[i][j] = las[j];
			if(isdigit(s[i])) las[s[i]-'0'] = i;
		}
		for(int i = 1; i <= Y; ++i) {
			int p = M;
			for(int j = 3; j >= 0; --j) p = pre[p][date[i][j]-'0'];
			num[p] += 1;
		}
		for(int i = m; i >= 1; --i) num[i] += num[i+1];

		for(int i = 0; i < 26; ++i) las[i] = m + 1;
		for(int i = m; i >= 0; --i) {
			for(int j = 0; j < 26; ++j) nxt[i][j] = las[j];
			if(isalpha(s[i])) las[s[i]-'a'] = i;
		}
		long long ans = 0;
		for(int i = 1; i <= n; ++i) {
			int l = strlen(name[i]+1), p = 0;
			for(int j = 1; j <= l; ++j) p = nxt[p][name[i][j]-'a'];
			ans += num[p];
		}
		printf("%lld\n", ans);
	}
	return 0;
}

