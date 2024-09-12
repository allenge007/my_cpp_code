#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 5;
const long long mod = 998244353;
char str[maxn];
int ans[maxn], cnt;
int main() {
    scanf("%s", str + 1);
    int tot = 0, n = strlen(str + 1);
    for(int i = 1; i <= n; i ++) {
        if(str[i] == '(') tot ++;
        else {
            if(str[i - 1] == '(') ans[++ cnt] = 0;
            else ans[++ cnt] = 1;
            tot --;
        }
    }
    long long num = 1;
    for(int i = cnt; i >= 1; i --) {
        if(ans[i]) num *= (cnt - i + 1), num %= mod;
    }
    printf("%lld\n", num);
    return 0;
}