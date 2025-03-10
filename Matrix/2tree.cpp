#include <cstdio>

int main() {
    printf("%d\n", f(1, 2, 3, 4));
    return 0;
}

int f(int n, int m) {
    printf("%d %d\n", n, m);
    return 114514;
}