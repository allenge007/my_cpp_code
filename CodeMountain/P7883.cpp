#include<iostream>
#include<cmath> 
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	scanf("%lld",&n);
	ll ans=n;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			ans=ans/i*(i-1);
			while(n%i==0)
			{
				n/=i;
			}
		}
	}
	if(n>1) ans=ans/n*(n-1);//说明还有一个质因数没算，不然的花n应该为1
	printf("%lld",ans);
	return 0;
}
