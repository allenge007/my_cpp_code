#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
using i64 = long long;
string ans1, ans2, s, mini, maxi;
bool vis[11];
int k, lenth;
template<typename T = int>
inline T read() {
	T x = 0; bool f = 1; char c = getchar();
	while(isdigit(c)^1) f &= (c != 45), c = getchar();
	while(isdigit(c)) x = (x<<1) + (x<<3) + (c^48), c = getchar();
	return f ? x : -x;
}
void dfs(string t, int p, int opt) {
    if(opt <= 0 || p >= lenth - 1) return void(ans1 = min(ans1, t));
    if(t[p] == mini[p]) dfs(t, p + 1, opt);
    else {
        for(int i = p + 1; i < lenth; i ++) {
            if(t[i] == mini[p]) {
                swap(t[p], t[i]);
                dfs(t, p + 1, opt - 1);
                swap(t[p], t[i]);
            }
        }
    }
}
void dfs2(string t, int p, int opt) {
    if(opt <= 0 || p >= lenth - 1) return void(ans2 = max(ans2, t));
    if(t[p] == maxi[p]) dfs2(t, p + 1, opt);
    else {
        for(int i = p + 1; i < lenth; i ++) {
            if(t[i] == maxi[p]) {
                swap(t[p], t[i]);
                dfs2(t, p + 1, opt - 1);
                swap(t[p], t[i]);
            }
        }
    }
}
int main() {
	int cas = read();
	while(cas--) {
		cin >> s;
		int n = lenth = s.length();
        k = read();
        ans1 = ans2 = "";
        for(int i = 0; i < n; i ++) ans2 += '0', ans1 += '9';
		assert(n <= 10);
        mini = s, maxi = s;
		sort(mini.begin(), mini.end());
		if(mini[0] == '0') {
			for(int i = 0; i < n; ++i) {
				if(mini[i] > '0') {
					swap(mini[0], mini[i]);
					break;
				}
			}
		}
		sort(maxi.begin(), maxi.end(), greater<char>());
        k = min(k, n - 1);
        dfs(s, 0, k);
        dfs2(s, 0, k);
        cout << ans1 << " " << ans2 << endl;
	}
	return 0;
}

