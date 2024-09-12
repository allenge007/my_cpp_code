#include<cstdio>

int n , ans;
long long sum;

int main()
{
	scanf("%d",&n);
	for(int i = 1 , x;i <= n;i ++) scanf("%d",&x) , sum += x;
	
	for(int i = 29;i >= 0;i --)
	{
		if(sum > 1ll * n * ((1 << i) - 1))
		{
			ans |= 1 << i , sum -= n * (1ll << i);
		}
	}

	printf("%d\n",ans);
	return 0;
}
