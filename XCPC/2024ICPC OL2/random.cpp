#include <bits/stdc++.h>

using namespace std;
const int maxn = 100055;
long long a[maxn], b[maxn];
int main() {
    freopen("test.in", "w", stdout);
    srand(time(0));
    int T;
    cin >> T;
    while(T --) {
        int n = 1004;
        printf("%d\n", n);
        for(int i = 1; i <= n; i ++) {
            cout << rand() % 2 << " " << (rand() ^ rand() % 10) << " " << (rand() % 10) << endl;
        }
        system("D:/OI/Contest/bin/checker.exe");
        system("D:/OI/Contest/bin/c.exe");
        freopen("test.out", "r", stdin);
        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
        }
        freopen("myans.out", "r", stdin);
        for(int i = 1; i <= n; i ++) {
            cin >> b[i];
        }
        for(int i = 1; i <= n; i ++) if(a[i] != b[i]) return cerr << i<< " " <<  "fuck\n", 0;
        // cerr << "pass\n";
        
    }
    
    return 0;
}