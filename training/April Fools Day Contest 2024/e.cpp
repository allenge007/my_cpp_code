#include <bits/stdc++.h>

using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' or ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' and ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
int t[100];
int main() {
    int ans = 0;
    for(int i = 1; i <= 21; i ++) {
        string x;
        int y = 0;
        cin >> x;
        for(int i = 0; i < 21; i ++)
            y += x[i] - '0';
        t[y] ++;
    }
    int maxi = 0;
    for(int i = 1; i <= 21; i ++) {
        if(t[i] > t[maxi]) maxi = i;
    }
    cout << maxi;
    return 0;
}