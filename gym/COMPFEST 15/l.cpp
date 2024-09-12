#include <bits/stdc++.h>

using namespace std;
const int maxn = 2005;
long long n, M;
bool vis[maxn];
long long check(int k) {
    long long cnt = 0;
    int j = 1;
    for(int i = 0; i < k; i ++) vis[i] = 0;
    long long fir = (k - 1) % n + 1;
    while(!vis[fir] && j <= n) {
        // cout << fir << " ";
        long long l = 0, r = n + 2ll * k;
        vis[fir] = 1;
        while(l <= r) {
            long long mid = (l + r) >> 1;
            if(fir + mid * k > j + mid) r = mid - 1;
            else l = mid + 1;
        }
        long long cntf = l;
        l = 0, r = n + 2ll * k;
        while(l <= r) {
            long long mid = (l + r) >> 1;
            if(fir + mid * k > n) r = mid - 1;
            else l = mid + 1;
        }
        long long cnte = min(r, (long long)n - j);
        if(cntf > cnte) {
            j += cnte + 1;
            fir = fir + (cnte + 1) * k - 1;
            fir = fir % n + 1;
            continue;
        }
        cnt += (fir + cntf * k + fir + cnte * k) * (cnte - cntf + 1) / 2ll;
        j += cnte + 1;
        fir = fir + (cnte + 1) * k - 1ll;
        fir = fir % n + 1;
    }

    return cnt;
}
int main() {
    scanf("%lld%lld", &n, &M);
    long long maxi = 0;
    int p = 1;
    for(int i = 2; i <= M; i ++) {
        long long cnt = check(i);
        if(cnt > maxi) {
            p = i, maxi = cnt;
            // cout << maxi << endl;
        }
        // cout << i << " " << cnt << endl;
    }
    printf("%d\n", p);
    return 0;
}