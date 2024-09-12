#include <bits/stdc++.h>

using namespace std;
const long long n2 = (1ll << 35ll) - 1ll;
int main() {
    cout << "? 0" << endl;
    long long x1, x2;
    cout.flush();
    cin >> x1;
    cout << "? " << n2 << endl;
    cout.flush();
    cin >> x2;
    cout << "! " << (long long)(x1 + x2 - 2ll * n2) << endl;
    cout.flush();   
    return 0;
}