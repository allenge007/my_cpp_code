#include <bits/stdc++.h>

using namespace std;

int main() {
    long long x;
    cin >> x;
    while(x % 2 == 0) x /= 2;
    while(x % 3 == 0) x /= 3;
    if(x > 1) cout << "No";
    else cout << "Yes";
    return 0;
}