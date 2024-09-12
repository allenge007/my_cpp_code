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
const int maxn = 1e7;
bool vis[maxn];
int main() {
    for(int i = 0; i <= 1000; i ++) {
        for(int j = 0; j <= 1000; j ++) {
            if(i * 45 + j * 23 > 1e7) break;
            vis[i * 45 + j * 23] = 1;
        }
    }
    for(int i = 100; i < 2e4; i ++) if(!vis[i]) cout <<i << endl;
    return 0;
}