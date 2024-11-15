#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 4, maxm = 4e5 + 4;
int tf[maxm], prime[maxn], num, a[maxn];
void solve() {
    int n, p = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++) {
        if(tf[a[i]] == 0) {
            if(p == 0) p = a[i];
            else if(p != a[i]) return cout << "-1" << endl, void();
        }
    }
    if(p == 0) return cout << "2" << endl, void();
    for(int i = 1; i <= n; i ++) {
        if(tf[a[i]]) {
            if(tf[a[i]] == 2) {
                if(a[i] < 2 * p) {
                    return cout << "-1" << endl, void();
                }
            } else {
                if(a[i] < 2 * p + tf[a[i]]) {
                    return cout << "-1" << endl, void();
                }
            }
        }
    }
    cout << p << endl;
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    for(int i = 2; i < maxm;i ++) {
		if(tf[i] == 0) prime[++num]=i;
		for(int j=1;j<=num&&i*prime[j]<maxm;j++) {
			tf[i*prime[j]] = prime[j];
			if(i%prime[j] == 0) break;
		}
	}
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}