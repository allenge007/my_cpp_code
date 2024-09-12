#include <bits/stdc++.h>
using namespace std;

const int N = 505;
char c[N][N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%s", c[i]+1);
    }
    int num = 0;
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < m; ++j) {
            if(c[i][j] == 'c' && c[i][j+1] == 'c' && c[i+1][j] == 'p' && c[i+1][j+1] == 'c') ++num;
        }
    }
    printf("%d\n", num);
}
