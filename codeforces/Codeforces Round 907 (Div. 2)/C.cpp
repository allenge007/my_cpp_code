#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn = 2e5 + 5;
int a[maxn];
void solve() {
    int n;
    scanf("%lld", &n);
    for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    int head = 1, tail = n, x = 0, cnt = 0;
    while(head < tail) {
        if(x + a[head] < a[tail]) {
            x += a[head];
            cnt += a[head];
            a[head] = 0; head ++;
        }
        else {
            a[head] -= a[tail] - x;
            cnt += a[tail] - x + 1;
            a[tail] = 0, x = 0;
            tail --;
            if(!a[head]) head ++;
        }
    }
    // cout<<a[tail]<<" "<<x<<" "<<cnt<<endl; 
    if(a[tail]) {
        if((a[tail] - x) % 2 == 0) {
            if(a[tail] == 0) cnt ++;
            else cnt += (a[tail] - x)/2 + 1;
        }
        else {
            if(a[tail] == 1) {
                cnt ++;
            }
            else cnt += (a[tail] - x)/2 + 2;
        }
    }
    
    printf("%lld\n", cnt);
}
signed main() {
    int T;
    scanf("%lld", &T);
    while(T --) solve();
    return 0;
}