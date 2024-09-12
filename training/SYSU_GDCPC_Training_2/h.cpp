#include <bits/stdc++.h>

using namespace std;
const double eps = 1e-6;
bool check(double x, int n, int k, int d) {
    double l = sqrt((double)d/x), r = sqrt(2.0*d/x);
    // cout << l << " " << r << endl;
    return l * 2 + 2.0 * (k - 1) * r > (double)n;
}
void solve() {
    int n, k, d;
    scanf("%d%d%d", &n, &k, &d);
    double l = 0, r = 1e10;
    while(r - l > eps) {
        double mid = (l + r)/2.0;
        if(check(mid, n, k, d)) l = mid;
        else r = mid;
    }
    // cout << check(11, n, k, d) << endl;
    printf("%.6lf\n", l);
    return ;
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}