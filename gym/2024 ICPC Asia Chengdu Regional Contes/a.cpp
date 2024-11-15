#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
void solve() {
    string str;
    cin >> str;
    int n = str.size();
    int p = 0, cnt = 0;
    for(int i = 0; i < n; i ++) {
        if(str[i] == '-') {
            cnt ++;
            if(!p) p = i;
            else if(str[i - 1] != '-') {
                return void(cout << "No\n");
            }
        }
    }   
    if(!p) return void(cout << "No\n");
    if(p + cnt + 2 > n) return void(cout << "No\n");
    if(n < 5) return void(cout << "No\n");
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}