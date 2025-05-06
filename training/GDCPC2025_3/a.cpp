#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 5;
int T;
void solve() {
    int n;
    string str;
    cin >> n >> str;
    if(str[0] == '0') {
        int minlen = maxn, las = n;
        for(int i = n - 1; ~i; --i) {
            if(str[i] == '1') {
                minlen = min(minlen, las - i);
                las = i;
            }
        }
        if(las == n) cout << str << endl;
        else if(minlen == 1) cout << "empty" << endl;
        else {
            for(int i = 1; i < min(minlen, las + 1); i ++) cout << '0';
            cout << endl;
        }
    } else {
        int minlen = maxn, las = n;
        for(int i = n - 1; ~i; --i) {
            if(str[i] == '0') {
                minlen = min(minlen, las - i);
                las = i;
            }
        }
        if(las == n) cout << str << endl;
        else if(minlen == 1) cout << "empty" << endl;
        else {
            for(int i = 1; i < min(minlen, las + 1); i ++) cout << '1';
            cout << endl;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T --) solve();
    return 0;
}