#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
char str[maxn];
void print(int x, int k) {
    for(int i = k - 1; i >= 0; i --)
        putchar(((x >> i) & 1) + '0');
    putchar('\n');
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n, k, cnt = 0;
        scanf("%d%d", &n, &k);  
        scanf("%s", str + 1);
        for(int i = 1; i <= n; i ++) {
            if(str[i] == '1') cnt ++;
        }   
        bool flag = 0;
        for(int i = cnt; i < min(cnt + k + 1, (1 << k)); i ++) {
            int num = 0;
            for(int j = 0; j < k; j ++) if(i & (1 << j)) num ++;
            if(cnt + num % (1 << k) == i) {
                print(i, k);
                flag = 1;
                break;
            }
        }
        if(!flag) printf("None\n");
    }
    return 0;
}