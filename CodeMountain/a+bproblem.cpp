#include <bits/stdc++.h>

using namespace std;
const int maxn = 105;
int a[maxn], b[maxn], n;
int main() {
  cin >> n;
  for(int i = 1; i <= n; i ++) cin >> a[i];
  for(int i = 1; i <= n; i ++) cin >> b[i];
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1, [](int x, int y) {
    return x > y;
  });
  int cnt = 0;
  for(int i = 1; i <= n; i ++) if(a[i] > b[i]) cnt ++;
  return printf(cnt * 2 == n ? "YES\n" : "NO\n"), 0;
}