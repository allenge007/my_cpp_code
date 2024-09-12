#include <bits/stdc++.h>

using namespace std;
int qpow(long long x, long long y) {
    long long cnt = 1, basic = x;
    while(y) {
        if(y & 1) cnt = cnt * basic % 10ll;
        basic = basic * basic % 10ll, y >>= 1ll;
    }
    return cnt;
}
int main() {
    int T;
    cin >> T;
    while(T --) {
        long long x, y;
        cin >> x >> y;
        x %= 10ll;
        cout << qpow(x, y) << endl;
    }
    return 0;
}