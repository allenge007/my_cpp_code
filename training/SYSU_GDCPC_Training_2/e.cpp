#include <cstdio>

using namespace std;
#define int long long
struct node{
    int x, y, z;
    void read() {
        scanf("%lld%lld%lld", &x, &y, &z);
    }
};
struct Matrix {
    double a[3][3], adj[3][3], Det;
    inline double det(double a, double b, double c, double d) {
        return a * d - b * c;
    }
    bool inverse() {
        adj[0][0] = det(a[1][1], a[1][2], a[2][1], a[2][2]);
        adj[0][1] = -det(a[1][0], a[1][2], a[2][0], a[2][2]);
        adj[0][2] = det(a[1][0], a[1][1], a[2][0], a[2][1]);
        adj[1][0] = -det(a[0][1], a[0][2], a[2][1], a[2][2]);
        adj[1][1] = det(a[0][0], a[0][2], a[2][0], a[2][2]);
        adj[1][2] = -det(a[0][0], a[0][1], a[2][0], a[2][1]);
        adj[2][0] = det(a[0][1], a[0][2], a[1][1], a[1][2]);
        adj[2][1] = -det(a[0][0], a[0][2], a[1][0], a[1][2]);
        adj[2][2] = det(a[0][0], a[0][1], a[1][0], a[1][1]);
        Det = adj[0][0] * a[0][0] + adj[0][1] * a[0][1] + adj[0][2] * a[0][2];
        if(Det == 0) return 0;
        for(int i = 0; i < 3; i ++)
            for(int j = 0; j < 3; j ++)
                a[i][j] = adj[j][i]/Det;
        return 1;
    }
}M;
inline bool zero(node a, node b, node c) {
    M.a[0][0] = a.x, M.a[1][0] = a.y, M.a[2][0] = a.z;
    M.a[0][1] = b.x, M.a[1][1] = b.y, M.a[2][1] = b.z;
    M.a[0][2] = c.x, M.a[1][2] = c.y, M.a[2][2] = c.z;
    return !M.inverse();
}
inline bool iszero(node x) {
    return x.x == 0 && x.y == 0 && x.z == 0;
}
const int maxn = 1e3 + 5, maxm = 1e4 + 5;
int n, m;
node tri[maxn][3], vec[maxn];
int dot(node x, node y) {
    return x.x * y.x + x.y * y.y + x.z * y.z;
}
bool cross(node x, node a, node b) {
    if(dot(x, a) * dot(x, b) > 0) return 0;
    return 1;
}
signed main() {
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < 3; j ++)
            tri[i][j].read();
    }
    for(int i = 1; i <= m; i ++)
        vec[i].read();
    for(int i = 1; i <= m; i ++) {
        int cnt = 0;
        double ans = 1e20;
        for(int j = 1; j <= n; j ++) {
            M.a[0][0] = vec[i].x, M.a[1][0] = vec[i].y, M.a[2][0] = vec[i].z;
            M.a[0][1] = tri[j][0].x - tri[j][1].x, M.a[1][1] = tri[j][0].y - tri[j][1].y, M.a[2][1] = tri[j][0].z - tri[j][1].z;
            M.a[0][2] = tri[j][0].x - tri[j][2].x, M.a[1][2] = tri[j][0].y - tri[j][2].y, M.a[2][2] = tri[j][0].z - tri[j][2].z;
            
            if(!M.inverse()) {
            }
            else {
                double t = tri[j][0].x * M.a[0][0] + tri[j][0].y * M.a[0][1] + tri[j][0].z * M.a[0][2];
                double u = tri[j][0].x * M.a[1][0] + tri[j][0].y * M.a[1][1] + tri[j][0].z * M.a[1][2];
                double v = tri[j][0].x * M.a[2][0] + tri[j][0].y * M.a[2][1] + tri[j][0].z * M.a[2][2];
                if(t >= 0) {
                    if(u >= 0 and v >= 0 and u + v <= 1) {
                        if(t < ans) {
                            ans = t, cnt = j;
                        }
                    }
                }
            }
        }
        printf("%lld\n", cnt);
    }
    return 0;
}