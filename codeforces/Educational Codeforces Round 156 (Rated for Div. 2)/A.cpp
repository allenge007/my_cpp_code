#include <bits/stdc++.h>

using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n, x, y, z;
        scanf("%d", &n);
        if(n % 3 == 0) {
            x = 1, y = 4, z = 7;
            if(n < x + y + z) printf("NO\n");
            else printf("YES\n%d %d %d\n", x, y, n - x - y);
        }
        else if(n % 3 == 1) {
            x = 1, y = 2, z = 4;
            if(n < x + y + z) printf("NO\n");
            else printf("YES\n%d %d %d\n", x, y, n - x - y);
        }
        else if(n % 3 == 2) {
            x = 1, y = 2, z = 5;
            if(n < x + y + z) printf("NO\n");
            else printf("YES\n%d %d %d\n", x, y, n - x - y);
        }
    }
    
    return 0;
}