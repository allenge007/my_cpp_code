#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1e4 + 5;
string str, S[maxn];
int cnt[maxn];
void solve() {
    cin >> str;
    int n = str.size(), tot = 0, num = 0;
    for(int i = 0; i < n; i ++) {
        if(isdigit(str[i])) {
            num = num * 10 + str[i] - '0';
        } else if(isalpha(str[i])) {
            S[tot] += str[i];
        } else if(str[i] == '[') {
            cnt[++ tot] = num, num = 0;
        } else if(str[i] == ']') {
            for(int j = 1; j <= cnt[tot]; j ++) S[tot - 1] += S[tot];
            S[tot].clear();
            cnt[tot --] = 0;
        }
    }
    cout << S[0] << endl;
    S[0].clear();
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}