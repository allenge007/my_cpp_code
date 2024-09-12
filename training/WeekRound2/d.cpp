#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e4 + 5, maxm = 1e3 + 5;
int n, m, t, x[maxn], y[maxn], z[maxn], f[maxm][maxm];
int main()
{
	cin >> n >> m >> t;
	for(int i = 1; i <= t; i ++)
        cin >> x[i] >> y[i] >> z[i];
	f[1][0] = 1;
	for (int i = 0; i <= m;i ++)
        for (int j = 1; j <= t; j ++){
            if (i + z[j] <= m and f[x[j]][i]) f[y[j]][i + z[j]] = max(f[y[j]][i + z[j]], f[x[j]][i] + 1);
            if (i + z[j] <= m and f[y[j]][i]) f[x[j]][i + z[j]] = max(f[x[j]][i + z[j]], f[y[j]][i] + 1);
        }
	if (!f[n][m]) cout << -1 << endl;
	else cout << f[n][m] << endl;
	return 0;
}
