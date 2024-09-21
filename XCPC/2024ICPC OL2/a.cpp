#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int c[maxn], n, k, C, id, w[maxn], in[maxn], cnt, str[maxn], rak[maxn];
map<string, int> S;
string name[maxn];
struct node{
    int w, id;
    node(int w = 0, int id = 0) : w(w), id(id) {};
}las[maxn];
vector<node> sch[maxn];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    int C = 1e9;
    for(int i = 1; i <= k; i ++) {
        cin >> c[i];
        C = min(C, c[i]);
    }
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x >> name[i];
        str[i] = x;
        if(!S[name[i]]) S[name[i]] = ++ id;
        sch[S[name[i]]].push_back(node(x, i));
    }
    for(int i = 1; i <= id; i ++) {
        sort(sch[i].begin(), sch[i].end(), [](node x, node y){
            return x.w > y.w;
        });
        int lim = min((int)sch[i].size(), C);
        for(int j = 0; j < lim; j ++) {
            rak[++ cnt] = sch[i][j].w;
        }
        in[i] = lim;
        las[i] = sch[i][lim - 1].w;
    }
    sort(rak + 1, rak + cnt + 1, [](node x, node y) {
        return x.w > y.w;
    });
    for(int i = 1; i <= n; i ++) {
        int rk = lower_bound(rak + 1, rak + cnt + 1, str[i], [](int x, int y) {
            return x > y;
        }) - rak;
        if(rak[rk] != str[i] && rak[rk] != las[S[name[i]]].w) {
            printf("%d\n", rk - 1);
        }
        else printf("%d\n", rk);
    }
    return 0;   
}