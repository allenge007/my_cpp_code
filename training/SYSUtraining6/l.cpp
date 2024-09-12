#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000000+5,M=1000000+5,INF=2147483647;
int n,m;	//如题意 
int nn,s,t,S,T;		//nn:原图中的点数,s:原图的源点,S虚拟图的源点,t,T同理 
int q[N],d[N],cur[N],ve[N];			//q:队列,d:高度,cur:当前弧优化,ve(Virtual Edge):虚拟边 
int h[N],e[N],f[N],ne[N],idx=0;			//h,e,ne,idx:邻接表,f:流量 
inline void add(int x,int y,int c){
	e[idx]=y,f[idx]=c,ne[idx]=h[x],h[x]=idx++;
	e[idx]=x,f[idx]=0,ne[idx]=h[y],h[y]=idx++;			//使用成对储存的技巧 
	return ;
}
inline int min(int a,int b){
	return a<b? a:b;
}
bool bfs(){				//寻找有无增广路并建立分层图 
	int hh=0,tt=0;
	memset(d,-1,sizeof d);
	q[hh]=S,d[S]=0,cur[S]=h[S];			//S初始高度为0,当前弧初始为第一条出边 
	while(hh<=tt){
		int p=q[hh++];
		for(int i=h[p];i!=-1;i=ne[i]){
			int ver=e[i];
			if(d[ver]==-1&&f[i]){			//一定要判断容量大于0 
				d[ver]=d[p]+1;				//层数  
				cur[ver]=h[ver];			//当前弧初始为第一条出边 
				if(ver==T) return true;
				q[++tt]=ver;
			}
		}
	}
	return false;
}
int find(int u,int limit){			//找到增广路,find(u,limit)表示从点u开始,
									//从S到u的最大容量为limit 
	if(u==T) return limit;
	int nowflow=0;					//nowflow表示从u向T流的最大流量 
	for(int i=cur[u];i!=-1&&nowflow<limit;i=ne[i]){		//从未满的路径开始搜
														//nowflow<limit是很重要的优化! 
		cur[u]=i;			//当前弧优化,搜到i就意味着i前的边已用完,将当前弧更新 
		int ver=e[i];
		if(d[ver]==d[u]+1&&f[i]){				//保证当前点在上一点的下一层,同样要注意f>0 
			int tflow=find(ver,min(f[i],limit-nowflow));
			if(!tflow) d[ver]=-1;				//若t到终点无增广路径,就删去点ver(把ver高度定为-1) 
			f[i]-=tflow,f[i^1]+=tflow,nowflow+=tflow;
		}
	}
	return nowflow;
}
int Dinic(){
	int maxflow=0,inflow;
    // cout << 1 << endl;
	while(bfs())				//若存在增广路 
		while(inflow=find(S,INF))  maxflow+=inflow;			//找出当前图上所有增广路 
	return maxflow;
}
bool vis[26][5005];
int L[26], R[26], pos[5005];
string str[505], ptr[505];
signed main(){
    memset(h, -1, sizeof h);
    int G, l;
    cin >> G >> l;
    for(int i = 0; i < 26; i ++) R[i] = INF;
    for(int i = 1; i < G; i ++) {
        string x, y;
        cin >> x >> y;
        str[i] = x, ptr[i] = y;
        for(int j = 0; j < l; j ++) if(y[j] == 'G') pos[j + 1] = x[j] - 'a' + 1;
    }
    for(int i = 1; i < G; i ++) {
        int cnt[26] = {}, flag[26] = {};
        for(int j = 0; j < l; j ++) {
            if(ptr[i][j] == 'G') {
                cnt[str[i][j] - 'a'] ++;
            }
            else if(ptr[i][j] == 'Y') {
                vis[str[i][j] - 'a'][j + 1] = 1;
                cnt[str[i][j] - 'a'] ++;
            }
            else if(ptr[i][j] == 'B'){
                vis[str[i][j] - 'a'][j + 1] = 1;
                flag[str[i][j] - 'a'] = 1;
            }
        }
        for(int j = 0; j < 26; j ++) {
            L[j] = max(L[j], cnt[j]);
            if(flag[j]) R[j] = cnt[j];
        }
    }
    for(int i = 1; i <= l; i ++) if(pos[i]) L[pos[i] - 1] --, R[pos[i] - 1] --;
    //构建原图 
    s = l + 27, t = l + 28;		//原图中s=1为源点,t=n+m+2为汇点 
    nn = l + 28;			//nn:原图的点数 
    for(int i = 26; i >= 1; i --) {
        if(!R[i - 1]) continue;
        for(int j = 1; j <= l; j ++) {
            if(!vis[i - 1][j] && pos[j] == 0) {
                add(i, j + 26, 1);
                // cout << (char)(i - 1 + 'a') << " " << j << endl;
            }
        }
    }
    for(int i = 1;i <= 26; ++ i){	//将少女编号为2~m+1,并和源点连通 
        if(R[i - 1] == 0) continue;
        add(s, i, R[i - 1] - L[i - 1]);
        ve[i] += L[i - 1];
        ve[s] -= L[i - 1];
        // cout << (char)(i + 'a' - 1) << " " << L[i - 1] << " " << R[i - 1] << endl;
    }
    for(int i = 1; i <= l; i ++) {
        if(!pos[i]) {
            add(i + 26, t, 1);
        }
    }/*
    for(int i=m+2;i<=m+n+1;++i){	//将天数编号为m+2~m+n+1,并和汇点连通 
        int C,D;
        scanf("%d%d",&C,&D);
        add(i,t,D);
        for(int j=1;j<=C;++j){		//将天与少女连通 
            int TT,L,R;		//TT即为题中的T
            scanf("%d%d%d",&TT,&L,&R);
            TT+=2;		//注意输入中的少女是从0编号的
            add(TT,i,R-L);	
            ve[TT]-=L;			//一定要减L,别减R！ 
            ve[i]+=L; 
        }
    }*/
    //构建虚拟图 
    S = l + 29, T = l + 30;		//S=0为虚拟图源点,T=n+m+3为虚拟图汇点 
    int outflow=0;		//记录从虚拟源点出流量,用于判断是否是满流 
    for(int i = 1; i <= l + 28; ++i){		//创建虚拟边保证虚拟图中流量守恒 
        if(ve[i]>0){
            add(S, i, ve[i]);
            // cout << i << endl;
            outflow += ve[i]; 
        } 
        else if(ve[i] < 0) add(i, T, -ve[i]);
    }
    // cout << outflow << endl;
    add(t, s, INF);		//增加一条从t到s的边,保证流量守恒 
    if(Dinic() < outflow) printf("-1\n\n");		//务必两个\n 
    else{
        int res=f[idx-1];		//最后加的边的反向边的流量
                                //即是当前(虚拟图的)满流中s->t的流量
        f[idx-1]=f[idx-2]=0;	//删除该边	
        S=s,T=t;		//因为现在求的是s->t的最大流量,
                        //所以重新初始化源点和汇点 
        res += Dinic(); 		//ans即为虚拟图中s->t的流量+
                               //新增加的可行流量
        for(int i = 1; i <= 26; i ++) {
            for(auto it = h[i]; it != -1; it = ne[it]) {
                if(f[it] == 0 && e[it] >= l + 1 && e[it] <= l + 26) {
                    pos[e[it] - 26] = i;
                    // cout << e[it] - 26 << " " << i << endl;
                }
            }
        }
        for(int i = 1; i <= l; i ++) cout << (char)(pos[i] + 'a' - 1);
        cout << endl;
    }
	return 0;
}
