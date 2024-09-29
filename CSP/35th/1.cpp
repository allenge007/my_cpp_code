#include <bits/stdc++.h>
using namespace std;
int vis[1005];
int main() {
	int n;
	cin >> n;
	while(n --) {
		string str;
		cin >> str;
		memset(vis, 0, sizeof vis);
		int lth = str.size(), dig = 0, let = 0, spe = 0, mid = 0;
		for(int i = 0; i < lth; i ++) {
			if(isdigit(str[i])) dig = 1;
			else if(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z') let = 1;
			else spe = 1;
			vis[str[i]] ++;
			if(vis[str[i]] > 2) mid = 1;
		}
		if(dig && let && spe && !mid && lth >= 6) cout << 2 << endl;
		else if(dig && let && spe && mid && lth >= 6) cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
}