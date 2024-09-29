#include <bits/stdc++.h>

using namespace std;
int to[1005], siz[1005];
string str;
int main() {
//	freopen("test.in", "r", stdin);
	getline(cin, str);
	int n;
	cin >> n;
	string Nul;
	getline(cin, Nul);
	for(int i = 1; i <= n; i ++) {
		string ptr;
		getline(cin, ptr);
		to[ptr[1]] = ptr[2];
	}
	for(int i = 0; i <= 1000; i ++) if(!to[i]) to[i] = i;
	int m, lth = str.size();
	cin >> m;
	for(int i = 1; i <= m; i ++) {
		int k;
		cin >> k;
		cout << "#";
		for(int j = 1; j < lth - 1; j ++) {
			memset(siz, 0, sizeof siz);
			int lft = k, p = str[j];
			siz[str[j]] = 1;
			while(!siz[to[p]] && lft) siz[to[p]] = siz[p] + 1, p = to[p], lft --;
			int cir = (siz[p] - siz[to[p]] + 1);
			if(!lft) cout << (char)p;
			else {
				lft %= cir;
				while(lft) p = to[p], lft --;
				cout << (char)p;
			}
		}
		cout << "#\n";
	}
	return 0;
}