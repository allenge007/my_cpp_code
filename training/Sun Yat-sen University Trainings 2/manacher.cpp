#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
char s[maxn];
int len[maxn], n, num[maxn], fail[maxn], cur, pos, trie[maxn][26], tot = 1;
char ptr[maxn];
int getfail(int x,int i) {
	while(i - len[x] - 1 < 0 || s[i-len[x]-1] != s[i])
        x = fail[x];
	return x;
}
signed main() {
	int Q;
    scanf("%lld%s", &Q, ptr);
    int n = 0;
    fail[0] = 1, len[1] = -1;
    int i = 0, ans = 0, las = 0, lans = 0, lt = 0, ll = 0, ln = 0, lpos = 0;
    bool flag = 0;
    for(int t = 0; t < Q; t ++) {
        if(ptr[t] >= 'a' and ptr[t] <= 'z') {
            s[n ++] = ptr[t];
            lpos = pos;
            pos = getfail(cur, i);
            if(!trie[pos][s[i] - 'a']){
                flag = 1;
                fail[++ tot] = trie[getfail(fail[pos],  i)][s[i] - 'a'];
                lt = trie[pos][s[i] - 'a'];
                trie[pos][s[i] - 'a'] = tot;
                ll = len[tot];
                len[tot] = len[pos] + 2;
                ln = num[tot];
                num[tot] = num[fail[tot]] + 1;
            }
            las = cur;
            cur = trie[pos][s[i]-'a'];
            lans = ans;
            i ++;
            printf("%lld ",ans += num[cur]);
        }
        else {
            printf("%lld ", lans);
            cur = las, ans = lans;
            i --, n --;
            if(flag) {
                fail[tot] = 0;
                trie[pos][s[i] - 'a'] = lt, len[tot] = ll, num[tot] = ln;
                tot --;
            }
            pos = lpos;
            flag = 0;
        }
    }
    
	return 0;
}