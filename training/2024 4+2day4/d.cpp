#include <bits/stdc++.h>

using namespace std;
const int maxn = 5005;
int n, a[maxn];
long long L, R, sum;
bool ok(int p) {

}
int main() {
    scanf("%d%lld%lld", &n, &L, &R);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), sum += a[i];
    sort(a + 1, a + n + 1);
    cout << sum/2    << endl;
    printf("Bob\n");
    return 0;
}