#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char str[100005];
int tx, ty, a[100005], pre[100005][15], dp[100005][15], now[15], x1[100005][15], x2[100005][15];
int main(void)
{
	int T, n, i, j, p, q, ans, cnt, ax, ay, Ans, c1, c2;
	scanf("%d", &T);
	while(T--)
	{
		tx = ty = 1;
		scanf("%d%s", &n, str+1);
		for(i=1;i<=n;i++)
			a[i] = str[i]-'0';
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=9;j++)
				pre[i][j] = pre[i-1][j];
			pre[i][a[i]] = i;
		}
		Ans = ans = 0;
		for(p=0;p<=9;p++)
		{
			for(q=p;q<=9;q++)
			{
				cnt = 0;
				for(i=0;i<=p;i++)  now[++cnt] = i;
				for(i=q;i>=p;i--)  now[++cnt] = i;
				for(i=q;i<=9;i++)  now[++cnt] = i;
				for(i=1;i<=n;i++)
				{
					for(j=1;j<=cnt;j++)
					{
						if(a[i]==now[j])
						{
							dp[i][j] = dp[i-1][j-1]+1;
							x1[i][j] = i-1, x2[i][j] = j-1;
							if(dp[i-1][j]+1>dp[i][j])
							{
								dp[i][j] = dp[i-1][j]+1;
								x2[i][j] = j;
							}
						}
						else
						{
							dp[i][j] = dp[i-1][j];
							x1[i][j] = i-1, x2[i][j] = j;
							if(dp[i][j-1]>dp[i][j])
							{
								dp[i][j] = dp[i][j-1];
								x1[i][j] = i, x2[i][j] = j-1;
							}
						}
						if(dp[i][j]>=ans)
						{
							ans = dp[i][j];
							ax = i, ay = j;
						}
					}
				}
				if(ans>Ans)
				{
					Ans = ans;
					while(ax!=0)
					{
						if(ay==p+2 && x2[ax][ay]!=ay)
							tx = ax;
						if(ay==q+3 && x2[ax][ay]!=ay)
							ty = x1[ax][ay];
						c1 = x1[ax][ay];
						c2 = x2[ax][ay];
						ax = c1, ay = c2;
					}
				}
			}
		}
		if(ty==0)
			tx = ty = 1;
		printf("%d %d %d\n", ans, tx, ty);
	}
	return 0;
}
/*
1
2
10
*/