#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
char str[maxn];
int main() {
    scanf("%s", &str);
    int n = strlen(str);
    for(int i = 0; i < n; i ++) {
        if(str[i] == '5') putchar('2');
        else if(str[i] == '2') putchar('0');
        else putchar('5');
    }
    return 0;
}