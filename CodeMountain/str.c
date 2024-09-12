#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char t[1005];
int min(int x, int y) {
    return x < y ?  x : y;
}
int cmp(char *x, char *y) {
    int n = strlen(x), m = strlen(y);
    return n < m;
}
void swap(char *x, char *y) {
    int n = strlen(x), m = strlen(y);
    for(int i = 0; i < n; i ++)
        t[i] = x[i];
    for(int i = 0; i < m; i ++)
        x[i] = y[i];
    x[m] = '\0';
    for(int i = 0; i < n; i ++)
        y[i] = t[i];
    y[n] = '\0';
}
char str[1005][1005];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%s", str[i]);
    for(int i = n - 1; i > 0; i --)
        for(int j = i; j; j --)
            if(cmp(&str[j], &str[j - 1])) {
                int n = strlen(x), m = strlen(y);
            for(int i = 0; i < n; i ++)
                t[i] = x[i];
            for(int i = 0; i < m; i ++)
                x[i] = y[i];
            x[m] = '\0';
            for(int i = 0; i < n; i ++)
                y[i] = t[i];
            y[n] = '\0';
        }
    for(int i = 0; i < n; i ++) {
        // printf("%s", str[i]);
        printf("%d\n", strlen(str[i]));
        if(i < n - 1) printf("\n");
    }
    return 0;
}