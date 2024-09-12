#include <bits/stdc++.h>

using namespace std;
long long exgcd(long long a, long long b, long long c, long long &x, long long &y){
	if(b == 0){
		x = c/a, y = 0ll;
		return a;
	}
	long long t;
	long long d = exgcd(b, a%b, c, t, x);
	y = t - a/b*x;
	return d;
}
long long n;
int main() {
    scanf("%lld", &n);
    if(n <= 9e5) {
        while(n >= 9) printf("9"), n -= 9;
        printf("%lld\n", n);
        return 0;
    }
    for(int j = 1; j <= 3000; j ++) {
        for(int k = 1; k <= 3000; k ++) {
            long long i = n / k / j / 789ll;
            long long left = n - (long long)i * j * k * 789ll;
            long long a, b;
            exgcd(45, 23, left, a, b);
            a = (a % 23 + 23) % 23;
            b = (left - 45ll * a) / 23ll;
            if(a > 0 && b > 0 && a + b + i + j + k + 3 <= 1e5) {
                for(int l = 1; l <= i; l ++) printf("7");
                for(int l = 1; l <= j; l ++) printf("8");
                for(int l = 1; l <= k; l ++) printf("9");
                printf("04");
                for(int l = 1; l <= a; l ++) printf("5");
                printf("2");
                for(int l = 1; l <= b; l ++) printf("3");
                return 0;
            }
        }
    }
    return 0;
}