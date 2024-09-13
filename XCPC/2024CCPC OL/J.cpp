#include <bits/stdc++.h>
using namespace std;

const int N = 1000006;
int a[N], b[N], c[32];

inline void insert(int *base, int x) {
    for(int i = 30; ~i; --i) {
        if((x >> i) & 1) {
            if(base[i]) x ^= base[i];
            else return void(base[i] = x);
        }
    }
}

int main() {
    int cas;
    scanf("%d", &cas);
    while(cas--) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for(int i = 1; i <= n; ++i) scanf("%d", &b[i]);
        memset(c, 0, sizeof(c));

        int X = 0, Y = 0;
        for(int i = 1; i <= n; ++i) X ^= a[i], Y ^= b[i], insert(c, a[i] ^ b[i]);
        int p = 0;
        for(int i = 30; ~i; --i) {
            if(!c[i]) continue;
            int x = (X >> i) & 1, y = (Y >> i) & 1;
            if(x && y) X ^= c[i], Y ^= c[i];
            else if(x || y) {
                p = i;
                break;
            }
        }
        int foo = max(X, Y), bar = max(X ^ c[p], Y ^ c[p]);
        for(int i = p-1; ~i; --i) {
            if(!c[i]) continue;
            if((foo ^ c[i]) < foo) foo ^= c[i];
            if((bar ^ c[i]) < bar) bar ^= c[i];
        }
        printf("%d\n", min(foo, bar));
    }
    return 0;
}