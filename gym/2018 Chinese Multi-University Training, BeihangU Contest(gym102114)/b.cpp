#include<cstdio>
#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn = 100+10;
const int INF = 0x3f3f3f3f;
int bit[12];
ll pos,k,Max,Min;
ll MIN[12],MAX[12];
ll get_num(int a[]){
    ll ans = 0;
    for(int i = 1;i <= pos;i++){
        ans  = ans * 10 + a[i];
    }
    return ans;
}
void dfs_max(int a[],int rt,int tim){
    if(tim == k){
        Max = max(Max,get_num(a));
        return;
    }
    if(rt == pos){
        Max = max(Max,get_num(a));
        return;
    }
    if(a[rt] == MAX[rt]){
        Max = max(Max,get_num(a));
        dfs_max(a,rt + 1,tim);
    }
    else{
        for(int i = rt + 1;i <= pos;i++){
            if(a[i] != MAX[rt]) continue;
            swap(a[rt],a[i]);
            Max = max(Max,get_num(a));
            dfs_max(a,rt + 1,tim + 1);
            swap(a[rt],a[i]);
        }
    }

}
void dfs_min(int a[],int rt,int tim){
    if(tim == k){
        Min = min(Min,get_num(a));
        return;
    }
    if(rt == pos){
        Min = min(Min,get_num(a));
        return;
    }
    if(a[rt] == MIN[rt]){
        Min = min(Min,get_num(a));
        dfs_min(a,rt + 1,tim);
    }
    else{
        for(int i = rt + 1;i <= pos;i++){
            if(a[i] != MIN[rt]) continue;
            swap(a[rt],a[i]);
            Min = min(Min,get_num(a));
            dfs_min(a,rt + 1,tim + 1);
            swap(a[rt],a[i]);
        }
    }

}
int main(){
    int T;
    char n[12];
    scanf("%d",&T);
    while(T--){
        scanf("%s%d",n,&k);
        pos = strlen(n);
        for(int i = 0;i < pos;i++){
            bit[i + 1] = n[i] - '0';
        }
        for(int i = 1;i <= pos;i++){
            MIN[i] = bit[i];
        }
        sort(MIN + 1,MIN + pos + 1);
        for(int i = 1;i <= pos;i++){
            MAX[i] = MIN[pos - i + 1];
        }
        if(MIN[1] == 0){
            int p = 2;
            while(MIN[p] == 0){
                p++;
            }
            swap(MIN[1],MIN[p]);
        }
        Max = 0,Min = INF;
        k = min(k,pos - 1);
        dfs_max(bit,1,0);
        dfs_min(bit,1,0);
        printf("%lld %lld\n",Min,Max);
    }
    return 0;
}