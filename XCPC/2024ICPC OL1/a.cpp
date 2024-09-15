#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int cas;
    cin >> cas;
    vector<int> a(32);
    while(cas--) {
        for(int i = 0; i < 32; ++i) cin >> a[i];
        int x = a[0], p = 0;
        sort(a.begin(), a.end(), greater<int>());
        for(int i = 0; i < 32; ++i) {
            if(a[i] == x) {
                p = i;
                break;
            }
        }
        if(p < 1) cout << "1\n";
        else if(p < 5) cout << "2\n";
        else if(p < 19) cout << "4\n";
        else if(p < 26) cout << "8\n";
        else if(p < 30) cout << "16\n";
        else cout << "32\n";
    }
    return 0;
}