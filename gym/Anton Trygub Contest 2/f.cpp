#include <bits/stdc++.h>

using namespace std;
int ans[100000005], tot, cnt;
void dfs(int x, int p) {
    if(x == 0) {
        if(!tot) return ;
        int s1 = 0, s2 = 0;
        // for(int i = 1; i <= tot; i ++) cout << ans[i] << " ";
        // cout << endl;
        bool flag = 1;
        for(int i = 1; i < (1 << tot) - 1; i ++) {
            s1 = s2 = 0;
            for(int j = 0; j < tot; j ++) {
                if((i >> j) & 1) s1 += 1 << ans[j + 1];
                else s2 += 1 << ans[j + 1];
            }
            for(int i = 10; i >= 0; i --) {
                if((s1 >> i) & 1) {
                    if((s2 >> i) & 1) {
                        flag = 0;
                        break;
                    }
                    break;
                }
                if((s2 >> i) & 1) break;
            }
            if(!flag) break;
            // cout << s1 << " " << s2 << endl;
        }
        if(flag) cnt ++;
        return ;
    }
    if(x < (1 << p)) return ;
    for(int i = p; (1 << i) <= x; i ++) {
        ans[++ tot] = i;
        dfs(x - (1 << i), i);
        tot --;
    }
}
int main() {
    for(int i = 1; ; i ++) {
        dfs(i, 0);
        cout << cnt << " ";
        cout.flush();
        cnt = 0;
    }
    return 0;
}