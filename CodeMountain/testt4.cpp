#include <bits/stdc++.h>
using namespace std;

int a[200005];
int md[1000005];
long long dp[200005][2];
long long s[200005];
int main(){
//	freopen("color.in","r",stdin);
//	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(s,0,sizeof(s));
		memset(md,0,sizeof(md));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			if (a[i]==a[i-1]) s[i]=s[i-1]+a[i];
			else s[i]=s[i-1];
		}
		for(int i=1;i<=n;i++){
			int r=md[a[i]];
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
			if (md[a[i]]>0) dp[i][1]=max(dp[r+1][0],dp[r+1][1])+a[i]+s[i-1]-s[r];
			// dp[i][1]=max(dp[i][1],dp[i][0]);
			md[a[i]]=i;
		}
		cout<<max(dp[n][0],dp[n][1])<<endl;
	}
	return 0;
}