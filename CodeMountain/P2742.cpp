#include <bits/stdc++.h>
#define float double
using namespace std;
const int maxn = 1e5 + 5;
struct Point{
    float x, y;
    Point(float x = 0, float y = 0): x(x), y(y) {}
    float operator * (const Point &b) const {
        return x * b.y - y * b.x;
    }
    Point operator - (const Point &b) const {
        return Point(x - b.x, y - b.y);
    }
    bool operator < (const Point &b) const {
        return x == b.x ? y < b.y : x < b.x;
    }
}p[maxn];
int st[maxn], top;
bool used[maxn];
float dis(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        float x, y;
        cin >> x >> y;
        p[i] = Point(x, y);
    } 
    sort(p + 1, p + n + 1);
    st[++ top] = 1;
    for(int i = 2; i <= n; i ++) {
        while(top >= 2 && (p[st[top]] - p[st[top - 1]]) * (p[i] - p[st[top]]) <= 0) used[st[top --]] = 0;
        st[++ top] = i;
        used[i] = 1;
    }
    int tmp = top;
    for(int i = n - 1; i >= 1; i --) {
        if(used[i]) continue;
        while(top > tmp && (p[st[top]] - p[st[top - 1]]) * (p[i] - p[st[top]]) <= 0) used[st[top --]] = 0;
        st[++ top] = i;
        used[i] = 1;
    }
    float ans = 0;
    for(int i = 2; i <= top; i ++) {
        ans += dis(p[st[i - 1]], p[st[i]]);
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}