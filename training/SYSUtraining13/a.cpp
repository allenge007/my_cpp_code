#include <bits/stdc++.h>

using namespace std;
const int maxn = 65;
long long A[maxn], B[maxn];
void insrtA(long long x) {
    for(int i = 62; i >= 0; i --) {
        if((x >> i) & 1) {
            if(!A[i]) {
                A[i] = x;
                break;
            }
            else x ^= A[i];
        }
    }
}
void insrtB(long long x) {
    for(int i = 62; i >= 0; i --) {
        if((x >> i) & 1) {
            if(!B[i]) {
                B[i] = x;
                break;
            }
            else x ^= B[i];
        }
    }
}
void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    memset(A, 0, sizeof A);
    memset(B, 0, sizeof B);
    long long X = 0;
    for(int i = 1; i <= n; i ++) {
        long long x, y;
        scanf("%lld%lld", &x, &y);
        insrtA(x ^ y), X ^= x;
    }
    for(int i = 1; i <= m; i ++) {
        long long x, y;
        scanf("%lld%lld", &x, &y);
        insrtB(x ^ y), X ^= x;
    }
    for(int i = 62; i >= 0; i --) {
        if(!A[i] && !B[i]) continue;
        if(!A[i] && (X ^ B[i]) < X) X ^= B[i];
        if(!B[i] && (X ^ A[i]) > X) X ^= A[i];
        if(A[i] && B[i]) insrtA(A[i] ^ B[i]);
        if(A[i] && B[i] && (X ^ B[i]) < X) X ^= A[i]; 
    } 
    printf("%lld\n", X);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}

/*
1
1 1
1 100
0 100
*/