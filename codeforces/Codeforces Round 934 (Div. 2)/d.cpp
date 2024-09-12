#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
char str[maxn], ptr[maxn << 1];
int cnt = 0, p[maxn << 1];
void manacher(int N) {
    ptr[0] = '$', cnt = 0;
	for(int i=1; i<=N; i++) ptr[++cnt] = '#', ptr[++cnt] = str[i];
	ptr[++cnt] = '#', ptr[++cnt] = '\0';
	int mx = 0, id; p[0] = 1;
	for(int i = 1; i <= cnt; i++){
		if(i < mx) p[i] = min(p[id*2 - i], mx - i);
		else p[i] = 1;
		while(ptr[i - p[i]] == ptr[i + p[i]]) p[i] ++;
		if(mx < i + p[i]){
			id = i; mx = i + p[i];
		}
	}
}
bool check(int l, int r) {
    return p[l + r] - 1 >= r - l + 1;
}
void solve() {
    vector<int> pos, pos2;
    int n, q;
    scanf("%d%d%s", &n, &q, str + 1);
    manacher(n);
    for(int i = 1; i <= n; i ++) {
        if(i + 2 <= n and str[i] != str[i + 2]) pos.push_back(i);
        if(i + 1 <= n and str[i] != str[i + 1]) pos2.push_back(i);
    }
    pos.push_back(n), pos2.push_back(n);
    while(q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        auto it = lower_bound(pos.begin(), pos.end(), l);
        if(*it < r - 1) {
            long long lenth = r - l + 1ll;
            if(check(l, r)) printf("%lld\n", (1 + lenth) * lenth / 2ll - 1ll - r + l - 1ll);
            else printf("%lld\n", (1 + lenth) * lenth / 2ll - 1ll);
        }
        else {
            auto it2 = lower_bound(pos2.begin(), pos2.end(), l);
            if(*it2 >= r) printf("0\n");
            else {
                long long lenth = r - l + 1ll;
                if(lenth & 1) lenth --;
                if(lenth == 0) printf("0\n");
                else printf("%lld\n", (2ll + lenth) * ((lenth - 2ll) / 2ll + 1ll) / 2ll);
            }
        }
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        solve();
    }
    return 0;
}