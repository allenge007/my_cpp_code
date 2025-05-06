#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int T[maxn], C, N;
bool check(int x) {
    int wear = C;
    for(int i = 1; i <= N; i ++) {
        if(T[i] < x) {
            if(wear == 0) return false;
            wear --;
        } else {
            wear = C;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> C >> N;
    for(int i = 1; i <= N; i++) {
        cin >> T[i];
    }
    int l = -50, r = 50;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    cout << r << endl;
    return 0;
}