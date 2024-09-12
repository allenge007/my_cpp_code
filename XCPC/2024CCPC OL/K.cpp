#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n, k;
        scanf("%d%d", &n, &k);
        if(n & 1) {
            printf("Alice\n");
            continue;
        }
        if(k >= n) {
            printf("Alice\n");
            continue;
        }
        while(n % 2 == 0 && k >= 2) {
            n /= 2, k /= 2;
        }
        if(k == 1) printf(n & 1 ? "Alice\n" : "Bob\n");
        else printf("Alice\n");
    }
    return 0;
}