#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    if(n == 0) return 0;
    int l = -(int)(sqrt(n)) - 1, r = -l, nowx = 0, nowy = 0;
    while(l <= r) {
        int len = (r - l + 1)/3, mid1 = l + len, mid2 = r - len;
        int check1
    }
    return 0;
}