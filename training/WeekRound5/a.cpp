#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
char str[maxn];
int n;
int main() {
    scanf("%d%s", &n, str + 1);
    for(int i = 1; i <= n; i ++) {
        // cout << i << " ";
        if(str[i] != 'A' and str[i] != 'B') {
            printf("%c", str[i]);
        }
        else {
            int cnt = 0, cntb = 0;
            for(int j = i; j <= n + 1; j ++) {
                if(str[j] != 'A' and str[j] != 'B' or j == n + 1) {
                    i = j - 1;
                    break;
                }
                if(str[j] == 'A') cnt ++;
                else cntb ++;
            }
            for(int j = 1; j <= cnt + cntb/2; j ++) putchar('A');
            if(cntb%2) putchar('B');
        }
    }
    return 0;
}