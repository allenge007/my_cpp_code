#include <bits/stdc++.h>
using namespace std;

int a[32];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int cas;
    cin >> cas;
    while(cas--) {
        int n;
        cin >> n;

        int lowbit = __lg(n & -n);

        if(n == 0 || lowbit > 1) {
            cout << "NO\n";
            continue;
        }

        for(int i = 0; i < 32; ++i) a[i] = 0;

        for(int i = lowbit + 1; i < 32; ++i) {
            if(((n >> i) & 1)) {
                a[i-1] = +1;
            }
            else {
                a[i-1] = -1;
            }
            a[i] = 1;
        }

        cout << "YES\n";
        for(int i = 0; i < 32; ++i) cout << a[i] << " \n"[i % 8 == 7];
    }
}