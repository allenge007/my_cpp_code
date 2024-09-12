#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int n,a[N],b[N],c[N],fa[N];
int find(int x)
{return (fa[x]==x)?x:(fa[x]=find(fa[x]));}
bool check(int x){
	for(int i=1;i<=n+1;i++)fa[i]=i;
	for(int i=1;i<=x;i++){
		int l=a[i],r=c[n-x+i];
		int w=upper_bound(b+1,b+2+n,l)-b;
		w=find(w);if(w>n||b[w]>=r)return 0;fa[w]=w+1;
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);sort(b+1,b+1+n);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);sort(c+1,c+1+n);
	int l=1,r=n;b[n+1]=1e9+7;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",r);
}
