#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define file(x) freopen("A"#x".in","r",stdin);freopen("A"#x".out","w",stdout);
using namespace std;
ll T,sum,ans,a[3][3];
int uni(int x,int y){
    int z=0;
    if(x==0||y==0)z++;
    else return z;
    if(x==1||y==1)z++;
    return z;
}
bool check(ll x,ll y){
    for(ll i=0;i<3;i++)
        for(ll j=0;j<3;j++){
            int c=uni(i,x),z=uni(j,y);
            if(((a[x][y]^a[i][j])==(sum^a[c][z]^(a[c][z]+1)))&&(i!=x)&&(j!=y))
                return 0;
        }
    return 1;
}
int main()
{
//	file(1);
    scanf("%lld",&T);
    while(T--){
        sum=ans=0;
        for(ll i=0;i<3;i++)
            for(ll j=0;j<3;j++)
                scanf("%lld",&a[i][j]),a[i][j]--,sum=sum^a[i][j];
        for(ll i=0;i<3;i++)
            for(ll j=0;j<3;j++)
                ans+=check(i,j);
        printf("%lld\n",ans);
    }
    return 0;
}
