#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
int head[maxn], Next[maxn << 1], edge[maxn << 1], ver[maxn << 1], tot;
void add(int x, int y, int z) {
    ver[++ tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

int main() {
    return 0;
}