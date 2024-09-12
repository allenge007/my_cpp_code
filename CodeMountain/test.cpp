#include<bits/stdc++.h>
#define LL long long
using namespace std;
int _;
LL n;
LL work(LL l,LL r,LL L,LL R,LL x){
    if(l==r) return L;
    LL len=(r-l+1)/4;
    LL mid=(l+r)/2,mid1=l+len-1,mid2=r-len+1,_mid=(L+R)/2,_mid1=L+len-1,_mid2=R-len+1;
    printf("%lld %lld %lld %lld %lld\n",l,mid1,mid,mid2,r);
    if(x<=mid1) work(l,mid1,L,_mid1,x);
    else if(x<=mid) work(mid1+1,mid,_mid+1,_mid2-1,x);
    else if(x<=mid2-1) work(mid+1,mid2-1,_mid2,R,x);
    else  work(mid2,r,_mid1+1,_mid,x);
}
int main(){
    scanf("%d",&_);
    while(_--){
        scanf("%lld",&n);
        LL p=(n-1)/3+1,r=n%3,k=0,sum=0;
        for(k=0;k<=60;k+=2){
            if(sum+(1ll<<k)>=p) break;
            else sum+=(1ll<<k);
        }
        p=p-sum;
        LL a=(1ll<<k)+p-1,b=work(1,(1ll<<k),(1ll<<k+1),(1ll<<k+1)+(1ll<<k)-1,p);
        if(r==0) printf("%lld\n",a^b);
        if(r==1) printf("%lld\n",a);
        if(r==2) printf("%lld\n",b);
    }
    return 0;
}
