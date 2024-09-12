#include <bits/stdc++.h>

using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' or ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' and ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n - 1; i ++) {
        if(s[i] == 'i' and s[i + 1] == 't') return printf("YES\n"), void();
    }
    return printf("NO\n"), void();
}
int main() {
    string s;
    cin >> s;
    cout << "I am not who keeps delaying things that must be done";
    return 0;
}