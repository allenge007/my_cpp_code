#include <bits/stdc++.h>

using namespace std;
const int maxn = 55;
char str[maxn][12];
int r, n, rl, rr;
int lab(int x) {
    if(x < 0) return -x;
    return x;
}
int dis(int x) {
    return min(lab(x - 1), min(lab(x - r/2 - 2), lab(x - r - 3)));
}
int empty(int x) {
    int num = 0;
    for(int i = 1; i <= 11; i ++) {
        if(i == 4 || i == 8) continue;
        if(str[x][i] == '-') num ++;
    }
    return num;
}
void choose(int x) {
    int mind = 0, d = r + 3, p = 0;
    if(empty(2) || empty(r/2 + 3)) {
        if(empty(2) >= empty(r/2 + 3)) p = 2;
        else p = r/2 + 3;
    }
    else {
        for(int i = 2; i < r + 3; i ++) {
            if(i == r/2 + 2) continue;
            if(empty(i) > mind || (empty(i) == mind && dis(i) < d)) {
                p = i, mind = empty(i), d = dis(i);
            }
        }
    }
    if(str[p][5] == '-' || str[p][7] == '-') {
        if(str[p][5] != '-') str[p][7] = x - 1 + 'a', rr --;
        else if(str[p][7] != '-') str[p][5] = x - 1 + 'a', rl --;
        else if(rl >= rr) str[p][5] = x - 1 + 'a', rl --;
        else str[p][7] = x - 1 + 'a', rr --;
    }
    else if(str[p][3] == '-' || str[p][9] == '-') {
        if(str[p][3] != '-') str[p][9] = x - 1 + 'a', rr --;
        else if(str[p][9] != '-') str[p][3] = x - 1 + 'a', rl --;
        else if(rl >= rr) str[p][3] = x - 1 + 'a', rl --;
        else str[p][9] = x - 1 + 'a', rr --;
    }
    else if(str[p][1] == '-' || str[p][11] == '-') {
        if(str[p][1] != '-') str[p][11] = x - 1 + 'a', rr --;
        else if(str[p][11] != '-') str[p][1] = x - 1 + 'a', rl --;
        else if(rl >= rr) str[p][1] = x - 1 + 'a', rl --;
        else str[p][11] = x - 1 + 'a', rr --;
    }
    else if(str[p][6] == '-') {
        str[p][6] = x - 1 + 'a';
    }
    else if(str[p][2] == '-' || str[p][10] == '-') {
        if(str[p][2] != '-') str[p][10] = x - 1 + 'a', rr --;
        else if(str[p][10] != '-') str[p][2] = x - 1 + 'a', rl --;
        else if(rl >= rr) str[p][2] = x - 1 + 'a', rl --;
        else str[p][10] = x - 1 + 'a', rr --;
    }
}
int main() {
    scanf("%d%d", &r, &n);
    for(int i = 1; i <= r + 3; i ++) {
        scanf("%s", str[i] + 1);
        if(i != 1 && i != r/2 + 2 && i != r + 3) {
            for(int j = 1; j <= 11; j ++) {
                if(j < 6 && str[i][j] == '-') rl ++;
                else if(j > 6 && str[i][j] == '-') rr ++;
            }
        }
    }
    for(int i = 1; i <= n; i ++) choose(i);
    for(int i = 1; i <= r + 3; i ++) {
        printf("%s\n", str[i] + 1);
    }
    return 0;
}