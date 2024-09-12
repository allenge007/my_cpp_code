#include <bits/stdc++.h>

using namespace std;
int main() {
  freopen("test.in", "w", stdout);
  int n = 1000, m = 1000;
  cout<<n<<" "<<m<<endl;
  cout<<1<<" "<<1<<" "<<n<<" "<<m<<endl;
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= m; j ++)
      cout<<".";
    cout<<endl;
  }
  return 0;
}