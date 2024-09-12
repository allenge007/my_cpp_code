#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;
char s[maxn];
int len[maxn], n, num[maxn], fail[maxn], cur, pos, trie[maxn][26], tot = 1;
int las[maxn], lans[maxn], lt[maxn], ll[maxn], ln[maxn], lpos[maxn], flag[maxn];
char ptr[maxn];
int getfail(int x,int i) {
	while(i - len[x] - 1 < 0 || s[i - len[x] - 1] != s[i])
        x = fail[x];
	return x;
}
signed main() {
	int Q;
    scanf("%lld%s", &Q, ptr);
    int n = 0;
    fail[0] = 1, len[1] = -1;
    int i = 0, ans = 0, cnt = 0;
    for(int t = 0; t < Q; t ++) {
        if(ptr[t] >= 'a' and ptr[t] <= 'z') {
            s[n ++] = ptr[t];
            lpos[++ cnt] = pos;
            pos = getfail(cur, i);
            if(!trie[pos][s[i] - 'a']){
                flag[cnt] = 1;
                fail[++ tot] = trie[getfail(fail[pos],  i)][s[i] - 'a'];
                lt[cnt] = trie[pos][s[i] - 'a'];
                trie[pos][s[i] - 'a'] = tot;
                ll[cnt] = len[tot];
                len[tot] = len[pos] + 2;
                ln[cnt] = num[tot];
                num[tot] = num[fail[tot]] + 1;
            }
            las[cnt] = cur;
            cur = trie[pos][s[i]-'a'];
            lans[cnt] = ans;
            i ++;
            printf("%lld ",ans += num[cur]);
        }
        else {
            printf("%lld ", lans[cnt]);
            cur = las[cnt], ans = lans[cnt];
            i --, n --;
            if(flag[cnt]) {
                fail[tot] = 0;
                trie[pos][s[i] - 'a'] = lt[cnt], len[tot] = ll[cnt], num[tot] = ln[cnt];
                tot --;
            }
            pos = lpos[cnt];
            flag[cnt] = 0;
            cnt --;
        }
    }
    
	return 0;
}