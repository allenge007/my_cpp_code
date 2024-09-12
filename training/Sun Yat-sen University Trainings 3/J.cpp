#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n;
        scanf("%d", &n);
        if(n & 1) {
            if(n - 3 <= 2) printf("-1\n");
            else printf("3 %d\n", n - 3);
        }
        else {
            if(n <= 4) printf("-1\n");
            else printf("2 %d\n", n - 2);
        }
    }
    return 0;
}