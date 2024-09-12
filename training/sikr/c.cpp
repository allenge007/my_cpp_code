#include <bits/stdc++.h>

using namespace std;
const int maxn = 105;
int a[maxn], tot;
int main() {
    int n, m;
    cin >> n >> m;
    while(m) {
        a[tot ++] = m % (n + 1);
        m /= (n + 1);
    }
    int las = 0;
    for(int i = 0; i < tot; i ++)
        if(a[i]) {
            las = i;
            break;
        }
    for(int i = tot - 1; i >= 0; i --) {
        if(a[i]) {
            if(a[i] > 1 || (a[i] == 1 && i == 0)) cout<<a[i];
            if(i > 1) cout<<"x^"<<i;
            else if(i == 1) cout<<"x";
            if(i > las) cout<<"+";
        }
    }
    return 0;
}