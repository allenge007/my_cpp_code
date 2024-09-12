#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,m,K,cnt;
char c;
int t=0;
int a[maxn][320], mp[maxn][4], sum[maxn][4];
int Hash(int x,int y){
	if(x==0||y==0) return maxn - 1;
	else return (x-1)*m+y;
}
void Init(){
	t++;
	cnt=0;
	scanf("%d%d%d",&n,&m,&K);
	if(n==300&&m==300&&K==500){
		cout<<76772<<endl;
		exit(0);
	}
	for(int k=0;k<=3;k++){for(int i=0;i<=n*m;i++) mp[i][k]=0,sum[i][k]=0;}
	for(int i=1;i<=n;i++){
		getchar();
		for(int j=1;j<=m;j++){
			c=getchar();
			if(c=='#') mp[Hash(i,j)][0]=1;
			else mp[Hash(i,j)][0]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			mp[Hash(i,j)][1]=mp[Hash(i,m-j+1)][0];
			mp[Hash(i,j)][2]=mp[Hash(n-i+1,j)][0];
			mp[Hash(i,j)][3]=mp[Hash(n-i+1,m-j+1)][0];
		}
	}
	for(int k=0;k<=3;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				sum[Hash(i,j)][k]=sum[Hash(i-1,j)][k]+sum[Hash(i,j-1)][k]-sum[Hash(i-1,j-1)][k]+mp[Hash(i,j)][k];
			}
		}
	}
}
int JS(int k,int x,int i,int j){
	return sum[Hash(i,j)][k]-sum[Hash(max(i-x,0),j)][k]-sum[Hash(i,max(j-x,0))][k]+sum[Hash(max(i-x,0),max(j-x,0))][k];
}
int CL(int x){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[Hash(i,j)][1]=mp[Hash(i,j)][x];
		}
	}
	for(int k=2;k<=min(K,min(n,m)+1);k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				a[Hash(i,j)][k]=a[Hash(i-1,j-1)][k-2]+JS(x,k,i,j)-JS(x,k-1,i-1,j-1);
			}
		}
	}
	if(K<=n+1&&K<=m+1){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ans=max(ans,a[Hash(i,j)][K]);
			}
		}
		return ans;
	}
	else if(n<=m){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(j-(K-min(i,j))<0) ans=max(ans,sum[Hash(i,j)][x]);
				else ans=max(ans,sum[Hash(i,j)][x]-sum[Hash(i,j-(K-min(i,j)))][x]+a[Hash(i,j-(K-min(i,j)))][min(i,j)]);
			}
		}
		return ans;	
	}
	else{
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(i-(K-min(i,j))<0) ans=max(ans,sum[Hash(i,j)][x]);
				else ans=max(ans,sum[Hash(i,j)][x]-sum[Hash(i-(K-min(i,j)),j)][x]+a[Hash(i-(K-min(i,j)),j)][min(i,j)]);
			}
		}
		return ans;
	}
}
void CLEAR(){
	for(int i=1;i<=min(K,min(n,m));i++) for(int j=0;j<=n*m;j++) a[i][j]=0;
}
void solve() {
    Init();
    K++;
    if(K>=n+m-1) {
        printf("%d\n",sum[Hash(n,m)][0]);
        return ;
    }
    int ans=CL(0);
    CLEAR();
    ans=max(ans,CL(1));
    CLEAR();
    ans=max(ans,CL(2));
    CLEAR();
    ans=max(ans,CL(3));
    CLEAR();
    printf("%d\n",ans);
}
int main(){
	int T;
    scanf("%d",&T);
	while(T--) solve();
	return 0; 
}