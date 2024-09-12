#include<bits/stdc++.h>
using namespace std;
const int maxn=10000005;
int prime[maxn],num;
long long sum[maxn];
bool tf[maxn]={1, 1};
void solve() {
    int n;
    scanf("%d", &n);
    printf("%lld\n", sum[n]);
}
int main()
{
	for(int i=2;i<=10000000;i++)
	{
		if(tf[i]==false) prime[++num]=i, sum[i] = 1;
		for(int j=1;j<=num&&i*prime[j]<=10000000;j++)
		{
			tf[i*prime[j]]=true;
            sum[i * prime[j]] = prime[j];
			if(i%prime[j]==0) break;
		}
	}
    for(int i = 2; i <= 10000000; i ++)
        sum[i] += sum[i - 1];
	int t;
    scanf("%d", &t);
    while(t --) solve();
	return 0;
}