#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n/5 + (n % 5 > 0); i ++) printf("a");
    for(int i = 1; i <= n/5 + (n % 5 > 1); i ++) printf("e");
    for(int i = 1; i <= n/5 + (n % 5 > 2); i ++) printf("i");
    for(int i = 1; i <= n/5 + (n % 5 > 3); i ++) printf("o");
    for(int i = 1; i <= n/5; i ++) printf("u");
    printf("\n");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}