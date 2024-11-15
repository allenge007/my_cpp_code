#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 5;
string str[maxn], ptr[maxn];
int nxt[maxn], pre1[maxn], pre2[maxn];
map<string, int> S;
bool eq(int x, int y, int i, int j) {
    if(x == 0) return 0;
    if(str[x].size() != ptr[i].size()) return 0;
    for(int k = 0; k < str[x].size(); k ++) {
        if(str[x][k] != ptr[i][k]) return 0;
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n = 0;
    cin >> str[++ n];
    while(str[n] != "$") cin >> str[++ n];
    int m = 0;
    cin >> ptr[++ m];
    while(ptr[m] != "$") cin >> ptr[++ m];
    n --, m --;
    for(int i = 1; i <= n; i ++) {
        pre1[i] = S[str[i]];
        S[str[i]] = i;
    }
    for(int i = 1; i <= m; i ++) {
        pre2[i] = S[ptr[i]];
        S[ptr[i]] = i;
    }
    for(int i = 2, j = 0; i <= m; i ++) {
        while(j && pre2[i] != pre2[j + 1]) j = nxt[j];
        if(pre2[i] == pre2[j + 1]) j ++;
        nxt[i] = j;
    }
    for(int i = 1, j = 0; i <= n; i ++) {
        while(j && !eq(pre1[j + 1], pre2[i], i, j)) j = nxt[j];
        if(eq(pre1[j + 1], pre2[i], i, j)) j ++;
        if(j == m) return cout << i - m + 1 << endl, 0;
    }
    return 0;
}