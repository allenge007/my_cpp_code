#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], to[maxn];
bool vis[maxn];
void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
        if(a[i]) to[i] = (a[i] + i) % n;
        vis[i] = 0;
    }
    long long l = 0, r = 0, lr = 0;
    for(int i = 0; i < n; i ++) {
        if(!vis[i] && a[i]) {
            int x = i, fe = 1, fo = 1;
            long long cnt = 0, pos = i;
            while(!vis[x]) {
                vis[x] = 1, cnt += a[x];
                if(pos % 2 == 0) fo = 0;
                else fe = 0;
                pos += a[x];
                x = to[x];
            }
            if(pos % 2 == 0) fo = 0;
            else fe = 0;
            cnt /= n;
            if(n % 2 == 0) {
                if(!fo && !fe) lr += cnt;
                else {
                    if(!fo) l += cnt;   
                    else r += cnt;
                } 
            }
            else {
                if(!fo && !fe) lr += cnt;
                else {
                    l += cnt / 2, r += cnt / 2;
                    if(!fo) l += cnt % 2;   
                    else r += cnt % 2;  
                } 
            }


        }
    }
    printf("%lld %lld %lld\n", l, r, lr);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}