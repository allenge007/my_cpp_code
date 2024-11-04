#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
int n, p[maxn];
void solve() {
    int las = 0;
    cin >> n;
    p[1] = 0, p[2] = 1;
    for(int i = 2; i < n; i ++) {
        cout << "? " << 1 << " " << i << endl;
        cout.flush();
        int r;
        cin >> r;
        if(!r) {
            las = i;
            break;
        }
    }
    for(int i = 1; i < las; i ++) p[i] = 0;
    p[las] = 1;
    int head = 1;
    for(int i = las + 1; i < n; i ++) {
        cout << "? " << i - 1 << " " << i << endl;
        cout.flush();
        int r;
        cin >> r;
        if(r == 1) {
            while(1) {
                cout << "? " << ++ head << " " << i << endl;
                cout.flush();
                int r;
                cin >> r;
                if(!r) {
                    p[i] = head;
                    break;
                }
            }
        } else p[i] = i - 1;
    }
    cout <<"! ";
    for(int i = 1; i < n; i ++) cout << p[i] << " ";
    cout << endl;
    cout.flush();
}
int main() {
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}