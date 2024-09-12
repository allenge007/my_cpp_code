#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e6 + 5;
char str[6][maxn], ptr[] = {'h', 'a', 'r', 'b', 'i', 'n'};
bool t[6][26], flag, vis[6];
void dfs(int x) {
    if(x == 6) {
        flag = 1;
        return ;
    }
    for(int i = 0; i < 6; i ++) {
        if(!vis[i]) {
            if(t[i][ptr[x] - 'a']) {
                vis[i] = 1;
                dfs(x + 1);
                vis[i] = 0;
                if(flag) return ;
            }
        }
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        for(int i = 0; i < 6; i ++) scanf("%s", str[i] + 1);
        for(int i = 0; i < 6; i ++) {
            int n = strlen(str[i] + 1);
            for(int j = 1; j <= n; j ++)
                t[i][str[i][j] - 'a'] = 1;
        }
        dfs(0);
        if(flag) printf("Yes\n");
        else printf("No\n");
        flag = 0;
        for(int i = 0; i < 6; i ++)
            for(int j = 0; j < 26; j ++)
                t[i][j] = 0;
    }
    return 0;
}