#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2e5+10;
int n,a[N];
int check(int x){
	for(int i=1;i<=n;i++){
		if(a[n-i+1]<x&&a[n-i]<x||a[n+i-1]<x&&a[n+i]<x)return 0;
		if(a[n-i+1]>=x&&a[n-i]>=x||a[n+i-1]>=x&&a[n+i]>=x)return 1;
	}
	return a[1]>=x;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n-1;i++)
		scanf("%d",&a[i]);
	int l=1,r=1e9;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	printf("%d",r);
}
