#include <stdio.h>

int gcd(int x, int y) {
    if(!y) return x;
    return gcd(y, x%y);
}

int main() {
    int x, y;
    while(scanf("%d%d", &x, &y) != EOF) {
        printf("%d", gcd(x, y));
    }
    return 0;
}