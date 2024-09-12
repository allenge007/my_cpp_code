#include<bits/stdc++.h>
using namespace std;
const int maxn=90000001, maxm = 5000000;
int prime[maxm], num;
bitset<maxn> tf;
int n,m;
long long sum[maxm];
int main()
{
    for(int i=2;i<=90000000;i++){
		if(tf[i]==0) {
            prime[++num]=i, sum[num] = sum[num - 1] + prime[num];
            if(sum[num] > 200000000000000ll) {
                // cout << prime[num] << " " << num << endl;
                break;
            }
        }
		for(int j=1; j<=num && (long long)i*prime[j]<=90000000ll;j++){
			tf[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
    int T;
    scanf("%d", &T);
    while(T --) {
        long long y;
        scanf("%lld", &y);
        int l = 1, r = num;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(sum[mid] < y) l = mid + 1;
            else r = mid - 1;
        }
        if(y == 0) printf("1\n");
        else if(sum[l] != y) printf("0\n");
        else printf("%d\n", prime[l + 1] - prime[l]);
    }
	return 0;
}