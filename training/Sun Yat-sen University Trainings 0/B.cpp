# include <bits/stdc++.h>

using namespace std;

int N,k,m,a[1000][1000];


int main() {
	cin >>N >> k;
	m = N * N - N;
	if (k > m) {
		printf("NO\n");
		return 0;
	}
	if (N == 2) {
		if (k >= 2) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i == j) continue;
			if (k) a[i][j] = 1, --k;
		}
	}
	swap(a[1][1],a[1][N]);
	swap(a[N][1],a[N][N]);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j)  printf("%c",a[i][j]?'#':'.');
		putchar('\n');
	}
	return 0;
} 