 #include<bits/stdc++.h>
using namespace std;
const int maxr = 45, maxc = 30, INF = 1e6 + 7;
int R, C, Map[maxr][maxc], Kingx, Kingy;
int X[8] = {-1, 1, 2, 2, 1, -1, -2, -2}, Y[8] = {2, 2, 1, -1, -2, -2, -1, 1};
struct node{
	int x, y;
	bool king;//记录是否带国王
};
queue< node > q;
int Abs(int x){//求绝对值
	if(x < 0) return -x;
	if(x == 0) return 0;
	if(x > 0) return x;
}
int spfa(int x,int y){
	int dis[maxr][maxc][2] = {}; bool vis[maxr][maxc][2] = {};//初始化dis，vis数组(spfa常规操作) 
	for(int i=1; i<=R; i++)//初始化dis数组，同样是常规操作 
		for(int j=1; j<=C; j++)
		    dis[i][j][0] = dis[i][j][1] = INF;
	node t;
	if(x == Kingx and y == Kingy) dis[x][y][1] = 0, t.king = true;//如果集合点的位置是国王的位置(不用考虑国王的移动)，初始状态就是dis[x][y][1] 
	else dis[x][y][0] = 0, t.king = false;//如果集合点的位置不是国王的位置，需要考虑国王的移动，初始状态是dis[x][y][0]
	t.x = x, t.y = y;
	q.push(t);//入队，常规操作 
	vis[x][y][t.king] = true;//标记,常规操作 
	while(!q.empty()){//一下均为spfa常规操作
		int dx = q.front().x, dy = q.front().y;
		bool flag = q.front().king;
		q.pop();
		for(int i=0; i<8; i++){//不进行带国王的操作 
			int ex = dx + X[i], ey = dy + Y[i];
			if(ex < 1 or ey < 1 or ex > R or ey > C) continue;
			if(dis[ex][ey][flag] > dis[dx][dy][flag] + 1){
				dis[ex][ey][flag] = dis[dx][dy][flag] + 1;
				if(!vis[ex][ey][flag]){
					vis[ex][ey][flag] = true;
					node e; e.x = ex, e.y = ey, e.king = flag;
					q.push(e);
				}
			}
		}
		if(!flag){//在(dx, dy)这个点带上国王(让国王自己走到这个点) 
			int val = dis[dx][dy][flag] + max(Abs(dx-Kingx), Abs(dy-Kingy));
			//算出国王走到这个点的步数,国王可以走八个方向，不是曼哈顿距离，而是max(Abs(dx-Kingx), Abs(dy-Kingy),自行画图理解 
			if(dis[dx][dy][!flag] > val){
				dis[dx][dy][!flag] = val;
				if(!vis[dx][dy][!flag]){
					vis[dx][dy][!flag] = true;
					node e; e.x = dx, e.y = dy, e.king = !flag;
					q.push(e);
				}
			}
		}
		vis[dx][dy][flag] = false;
	}
	int minu = abs(Kingx) + abs(Kingy) , cnt = 0;//最短路跑完后，算出最短的总距离
	//容易证明，骑士所在的点的状态dis[x][y][1]>=dis[x][y][0]，要使总距离最小，只需要找最小的(dis[x][y][1]-dis[x][y][0])，最后加上所有骑士的距离dis[x][y][0]即可 
	for(int i=1; i<=R; i++)
	    for(int j=1; j<=C; j++)
	    	if(Map[i][j] == 1) minu = min(minu, dis[i][j][1] - dis[i][j][0]), cnt += dis[i][j][0];
	return cnt+minu;
}
int main(){
    freopen("test.in", "r", stdin);
	cin>>C>>R;//写到最后发现R,C打反了，不想改了，将就着看吧 
	char kingx;
	cin>>kingx>>Kingy;//读入 
	Kingx = kingx-'A'+1;//Kingx储存国王的横坐标，Kingy储存国王的纵坐标 
	char knightx; int knighty;
	while(cin>>knightx>>knighty){//读入 
		Map[knightx-'A'+1][knighty] = 1;//邻接矩阵标记国王的位置 
	}
	int ans = INF;//初始化 
	for(int i=1; i<=R; i++) 
		for(int j=1; j<=C; j++)
			ans = min(ans, spfa(i, j));//枚举集合点，spfa求最短距离 
	if(ans == INF) printf("0");
	else printf("%d", ans);
	return 0;
}