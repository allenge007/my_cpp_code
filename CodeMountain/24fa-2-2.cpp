#include <bits/stdc++.h>

using namespace std;
const int maxn = 5005;
int n;
struct node{
    int x, y, z, val;
    node(int x = 0, int y = 0, int z = 0, int val = 0) : x(x), y(y), z(z), val(val) {};
    bool operator < (const node &a) const {
        return x == a.x ? y < a.y : x < a.x;
    }
};
vector<node> g;
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        char ch;
        int x, y, z;
        cin >> ch >> x >> y >> z;
        if(z == 'W') g.push_back(node(x + y, x - y, z, 1));
        else g.push_back(node(x + y, x - y, z, -1));
    }
    sort(g.begin(), g.end());

    return 0;
}