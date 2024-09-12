#include<cstdio>
#include<cstring>
#include<algorithm>
#define file(x) freopen("data"#x".in","r",stdin);freopen("data"#x".out","w",stdout);
#define ll long long
using namespace std;
const ll P=998244353;
ll n,ans;
signed main()
{
	scanf("%lld",&n);ans=1;
	for(ll i=3;i<=n+1;i++)
		ans=ans*i%P;
	printf("%lld\n",ans);
	return 0;
}
