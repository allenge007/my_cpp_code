#include <bits/stdc++.h>

using namespace std;
const int maxn = 105;
char str[maxn];
int ans[maxn * 3], num;
void solve() {
    num ++;
    int n, cnt = 0;
    scanf("%d%s", &n, str + 1);
    deque<char> que;
    for(int i = 1; i <= n; i ++) que.push_back(str[i]);
    int p = n, q = 0;
    while(que.size() > 1) {
        if(que.back() != que.front()) {
            p --, q ++;
            que.pop_back(), que.pop_front();
        }
        else {
            if(que.front() == '1') {
                que.push_front('1'), que.pop_back();
                ans[++ cnt] = q;
                q ++, p ++;
            }
            else {
                que.pop_front(), que.push_back('0');
                q ++;
                ans[++ cnt] = p ++;
            }
            
        }
        if(cnt > 300) return printf("-1\n"), void();
    }
    if(que.size() == 1) return printf("-1\n"), void();
    printf("%d\n", cnt);
    for(int i = 1; i <= cnt; i ++)
        printf("%d ", ans[i]);
    printf("\n");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}