#include <bits/stdc++.h>

using namespace std;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' or ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' and ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
int main() {
    cout << "safety";
    return 0;
}