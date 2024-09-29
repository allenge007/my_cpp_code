#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int c[maxn], id[maxn], n, m, k, tot = 1, kind[maxn];
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i ++) scanf("%d", &c[i]), id[i] = 1;
	for(int i = 1; i <= k; i ++) {
		int x, l, r;
		scanf("%d%d%d", &x, &l, &r);
		int las = 0, num = 0, duan = 0;
		for(int j = l; j <= r; j ++) {
			if(id[j] == x) {
				if(!las) las = c[j], duan = 1;
				else {
					if(c[j] != las) duan ++, las = c[j];
				}
				kind[c[j]] ++;
				if(kind[c[j]] == 1) num ++;
			}
		}
		printf("%d %d\n", num, duan);
//		cout << "----------------\n";
//		for(int j = 1; j <= n; j ++) cout << id[j] << " ";
//		cout << endl;
		tot ++;
		for(int j = l; j <= r; j ++) {
			if(id[j] == x) {
				id[j] = tot;
				kind[c[j]] --;
			}
		}
//		cout << endl;
	}
	return 0;
}