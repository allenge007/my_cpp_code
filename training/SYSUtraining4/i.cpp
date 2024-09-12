#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

template<typename T = int>
inline T read() {
	T x = 0; bool f = 1; char c = getchar();
	while(isdigit(c)^1) f &= (c != 45), c = getchar();
	while(isdigit(c)) x = (x<<1) + (x<<3) + (c^48), c = getchar();
	return f ? x : -x;
}

const int maxn = 200005;
vector<int> spx[maxn], spy[maxn];

int main() {
	int n = read(), m = read(), k = read();
	for(int i = 1; i <= k; ++i) {
		int x = read(), y = read();
		spx[x].push_back(y), spy[y].push_back(x);
		if(x == 1 || y == 1) puts("Chaneka"), exit(0);
	}
	int x = n, y = m;
	while(x > 1 && y > 1) {
		// cerr << "at: " << x << " " << y << endl;
		int xx = x-1, yy = y-1, flag1 = 1, flag2 = 1;
        if(xx > 1) {
            for(int i : spx[xx]) {
                if(i >= y) {
                    --xx, flag1 = 1;
                    break;
                }
            }
        }
        if(yy > 1) {
            for(int i : spy[yy]) {
                if(i >= x) {
                    --yy, flag2 = 1;
                    break;
                }
            }
        }
		if(flag1) x = xx;
        if(flag2) y = yy;
	}
	puts(x == y && x == 1 ? "Bhinneka" : "Chaneka");
	return 0;
}

