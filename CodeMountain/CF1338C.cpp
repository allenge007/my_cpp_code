#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    scanf("%lld",&n);
    n --;
    long long ans = 0, k = 0;
    for(long long i = 1; i * 3 <= n; i *= 4){
        k ++;
        n -= i * 3;
    }
    long long m = n / 3;
    long long cnt = 0;	
    ans = (n % 3 + 1)<<(k << 1ll);
    while(m) {
        if(m%4==1){
            if(n%3==0) ans+=(1ll<<cnt);
            if(n%3==1) ans+=(2ll<<cnt);
            if(n%3==2) ans+=(3ll<<cnt);
        }
        if(m%4==2){
            if(n%3==0) ans+=(2ll<<cnt);
            if(n%3==1) ans+=(3ll<<cnt);
            if(n%3==2) ans+=(1ll<<cnt);
        }
        if(m%4==3){
            if(n%3==0) ans+=(3ll<<cnt);
            if(n%3==1) ans+=(1ll<<cnt);
            if(n%3==2) ans+=(2ll<<cnt);
        }
        m/=4;cnt+=2;
    }
    printf("%lld\n",ans);
}

int main(){
	int T;
    scanf("%d", &T);
	while(T --) solve();
	return 0;
}
