#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5;
void solve() {
    string str;
    cin >> str;
    int n = str.size();
    vector<string> head;
    string x;
    int cnt = 0;
    for(int i = 0; i < n; i ++) {
        if(str[i] != ':') x += str[i];
        else {
            cnt = i, head.push_back(x), x = "";
            break;
        }
    }
    for(int i = cnt + 3; i < n; i ++) {
        if(str[i] != '/') x += str[i];
        else {
            cnt = i, head.push_back(x), x = "";
            break;
        }
    }
    if(x != "") head.push_back(x), x = "", cnt = n - 1;
    bool flag = 0;
    for(int i = cnt + 1; i < n; i ++) {
        if(str[i] != '/') {
            x += str[i];
            if(str[i] == '=') flag = 1;
        }
        else {
            if(flag) head.push_back(x), flag = 0;
            x = "";
        }
    }
    for(auto it : head) cout << it << endl;
}
int main() {
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}