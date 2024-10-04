#include <bits/stdc++.h>

using namespace std;
string str;
const int maxn = 2e5 + 5;
void solve() {
    int n, siz = 0;
    string ptr;
    cin >> n >> str;
    int las = -1, lth = str.size(), ans = 0, mini = n;
    for(int i = 0; i < lth; i ++) {
        if(str[i] == '1' && las == -1) {
            las = i, ptr += '1';
        }
        else if(str[i] == '0' && las != -1) {
            ptr += '0', ans += i - las, mini = min(mini, i - las), las = -1;
        }
        else if(str[i] == '0') ptr += '0';
    }
    if(las != -1) mini = min(mini, lth - las), ans += lth - las;
    lth = ptr.size();
    if(ptr[0] == '1' && ptr[lth - 1] == '1') {
        bool flag = 1;
        for(int i = 1; i < lth; i ++) {
            if(ptr[i] == '0' && ptr[i - 1] == '0')  {
                flag = 0;
                break;
            }
        }
        if(flag) return printf("%d\n", ans + mini), void();
    }
    return printf("%d\n", ans), void();
}
int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}
