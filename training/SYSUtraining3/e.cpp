#include <bits/stdc++.h>

using namespace std;
const double eps = 1e-6;
void solve() {
    double R, a1 = 0, ans = 0;
    int m;
    scanf("%d%lf", &m, &R);
    for(int i = 1; i <= m;  i ++) {
        double x, y, r;
        scanf("%lf%lf%lf", &x, &y, &r);
        double d2 = x * x + y * y;
        if(fabs(sqrt(d2) + r - R) < eps) {
            ans += 2.0 * acos(-1) * r;
            continue;
        }
        if(sqrt(d2) + r < R || sqrt(d2) - r > R) continue;
        double d = sqrt(d2);
        
        a1 += 2.0 * acos((R * R + d2 - r * r) / d / R / 2.0);
        double a0 = 2.0 * acos((r * r + d2 - R * R)/r/d / 2.0);
        // cout << i << endl;
        // cout << r << " " << d << " " << R << " " << (R * R + d2 - r * r) / d / R << " " << a1/acos(-1) << " " << a0/acos(-1) << endl;
        ans += a0 * r;
    }
    ans += 2 * acos(-1) * R - a1 * R;
    printf("%.18lf\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}