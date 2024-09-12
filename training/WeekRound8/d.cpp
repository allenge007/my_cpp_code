#include<bits/stdc++.h>
using namespace std;

const int maxn = 5005;
int a[maxn], b[maxn], sa[maxn], sb[maxn];
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]), sa[a[i]] ++;
	for(int i = 1; i <= n; i ++)
        scanf("%d", &b[i]), sb[b[i]] ++;
	for(int i = 1; i <= n; i ++)
		if(sa[a[i]] ^ sb[a[i]])
			return printf("No\n"), 0;
	for(int i=1;i<=n;i++)
		if(sa[a[i]] > 1)
            return printf("Yes\n"), 0;
	int ans = 0;
	for(int i = 1; i < n; i ++) {
		for(int j = i + 1; j <= n; j ++) {
			if(a[i] < a[j]) ans ^= 1;
			if(b[i] < b[j]) ans ^= 1;
		}
	}
	printf(ans == 0 ? "Yes\n" : "No\n");
	return 0;
} 
