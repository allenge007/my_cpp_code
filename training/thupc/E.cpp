#include <bits/stdc++.h>

using namespace std;
const int maxn = 351493;
int a[maxn], b[maxn], c[maxn], id[maxn], n;
long long sum, maxnum, sum2;
bool cmp(int x, int y) {
    return c[x] > c[y];
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        id[i] = i;
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &b[i]);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &c[i]);
    sort(id + 1, id + n + 1, cmp);
    for(int i = 1; i <= n; i ++) {
        if(a[i]) sum += min(a[i] + c[i], b[i]), maxnum += a[i] + c[i];
    }
    for(int i = 1; i <= n; i ++) {
        if(!a[i]) {
            if(b[i] and sum) sum += min(b[i], c[i] + 1) - 1, maxnum += c[i];
        }
    }
    int cnt2 = sum;
    for(int i = 1; i <= n; i ++) {
        if(!a[id[i]] and !b[id[i]]) {
            if(cnt2) cnt2 --, maxnum += c[id[i]];
        }
    }
    for(int i = 1; i <= n; i ++) {
        if(a[i] > 0) printf("%lld ", a[i] + c[i] - min(a[i] + c[i], b[i]) + sum);
        else {
            if(sum and b[i]) printf("%lld ", a[i] + c[i] - min(b[i], c[i] + 1) + 1 + sum);
            else {
                if(sum) printf("%lld ", sum + c[i]);
                else printf("0 ");
            }
        }
    }
    printf("\n");
    printf("%lld", maxnum);
    return 0;
}