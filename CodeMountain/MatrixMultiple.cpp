#include <bits/stdc++.h>

using namespace std;
const int maxn = 998244353;
inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while(ch < '0' or ch > '9') {if(ch == '-') f = -f; ch = getchar();}
    while(ch >= '0' and ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
class Matrix {
    public:
        long long a[2][2];
        void clear() {
            for(int i = 0; i < 2; i ++)
                for(int j = 0; j < 2; j ++)
                    a[i][j] = 0;
        }
        void init() {
            for(int i = 0; i < 2; i ++)
                for(int j = 0; j < 2; j ++)
                    a[i][j] = (i == j);
        }
        void scan() {
            for(int i = 0; i < 2; i ++)
                for(int j = 0; j < 2; j ++)
                    scanf("%lld", &a[i][j]);
        }
        void print() {
            for(int i = 0; i < 2; i ++)
                for(int j = 0; j < 2; j ++)
                    printf("%d ", a[i][j]);
            printf("\n");
        }
        Matrix operator *(const Matrix &y) const{
            Matrix c;
            c.clear();
            for(int k = 0; k < 2; k ++)
                for(int i = 0; i < 2; i ++)
                    for(int j = 0; j < 2; j ++)
                        (c.a[i][j] += a[i][k] * y.[k][j] % mod) %= mod;
            return c;
        }
};
int main() {

    return 0;
}