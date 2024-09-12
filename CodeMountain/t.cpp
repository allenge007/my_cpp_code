#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int main(){
    int a[maxn], n, tot = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        if(x < 10) a[++ tot] = x;
        else a[++ tot] = x / 10, a[++ tot] = x % 10;
    }

    return 0;
}