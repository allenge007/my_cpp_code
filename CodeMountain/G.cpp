#include<bits/stdc++.h>
#include <windows.h>
using namespace std;
int n,m,l;
int stu[100005];
struct AB{
	bool pd;
	string nam;
}ha[1000005];
int Hash(string s){
	int len=s.length();
	long long re=0; 
	for(int i=0;i<len;i++){
		re=re*10+(int)(s[i]);
		re%=999983;
	}
	re%=999983;
	int r=re;
	return r;
}
string s,ans[100005];
int val,cnt;
int main(){
	auto ss = GetTickCount();
	freopen("G.in","r",stdin);
	scanf("%d%d%d",&n,&m,&l);
	for(int i=1;i<=n;i++){
		cin>>s;
		val=Hash(s);
		stu[++stu[0]]=val;
		ha[val].nam=s;
		ha[val].pd=true;
	}
//	cout<<"!"<<endl;
	for(int i=1;i<=m;i++){
		cin>>s;
		val=Hash(s);
		if(ha[val].nam==""){
			stu[++stu[0]]=val;
			ha[val].nam=s;
			ha[val].pd=false;
		}
		else{
			ha[val].pd=false;
		}
	}
//	cout<<"@"<<endl;
	for(int i=1;i<=l;i++){
		cin>>s;
		val=Hash(s);
		if(ha[val].nam==""){
			stu[++stu[0]]=val;
			ha[val].nam=s;
			ha[val].pd=true;
		}
		else{
			ha[val].pd=true;
		}
	}
//	cout<<"#"<<endl;
	for(int i=1;i<=stu[0];i++){
		if(ha[stu[i]].pd){
			ans[++cnt]=ha[stu[i]].nam;
		}
	}
	sort(ans+1,ans+cnt+1);
	for(int i=1;i<=cnt;i++){
		cout<<ans[i]<<endl;
	} 
	auto tt = GetTickCount();
	cout<<tt<<endl;
	return 0;
}
