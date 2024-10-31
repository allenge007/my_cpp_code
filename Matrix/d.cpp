#include <cstdio>
#include <queue>
using namespace std;
void solve() {
    queue<int> q;
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) q.push(i);
    while(!q.empty()) {
        printf("%d ", q.front());
        q.pop();
        if(q.empty()) break;
        q.push(q.front());
        q.pop();
    }
    printf("\n");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}