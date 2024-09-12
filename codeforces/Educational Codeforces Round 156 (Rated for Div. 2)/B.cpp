#include <bits/stdc++.h>

using namespace std;
const double eps = 1e-8;
int Px, Py, Ax, Ay, Bx, By;
int D(int x) {
    return x * x;
}
bool check(double w){
    bool inA = 0, inB = 0, outA = 0, outB = 0, br = 0;
    if(w * w > (double)(Ax * Ax + Ay * Ay)) inA = 1;
    if(w * w > (double)(Bx * Bx + By * By)) inB = 1;
    if(w * w > (double)(D(Ax - Px) + D(Ay - Py))) outA = 1;
    if(w * w > (double)(D(Bx - Px) + D(By - Py))) outB = 1;
    if(w * w * 4 > (double)(D(Ax - Bx) + D(Ay - By))) br = 1;
    if(br) {
        bool f1 = 0, f2 = 0;
        if(inA or inB) f1 = 1;
        if(outA or outB) f2 = 1;
        if(f1 and f2) return 1;
        return 0;
    }
    if(inA and outA) return 1;
    if(inB and outB) return 1;
    return 0;
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        
        scanf("%d%d%d%d%d%d", &Px, &Py, &Ax, &Ay, &Bx, &By);
        double l = 0, r = 4e3, chk = 0;
        while(r - l > eps) {
            double mid = (l + r) / 2;
            if(check(mid)) r = mid;
            else {
                l = mid;
            }
        }
        printf("%.8lf\n", r);
    }
    return 0;
}