#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const long long mod = 1e9 + 7;
char ptr[maxn];
queue<int> q;
struct Aho_Corasick_Automaton{
	int trie[maxn][26], end[maxn], fail[maxn], lenth[maxn], cnt;
	void insert(char *str){
		int len = strlen(str); int now = 0;
		for(int i=0; i<len; i++){
			if(!trie[now][str[i] - 'a']) trie[now][str[i] - 'a'] = ++cnt, lenth[cnt] = lenth[now] + 1;
			now = trie[now][str[i] - 'a'];
		}
		end[now] ++;
	}
	void build(){
		for(int i=0; i<26; i++) if(trie[0][i]) fail[trie[0][i]] = 0, q.push(trie[0][i]);
		while(!q.empty()){
			int x = q.front(); q.pop();
			for(int i=0; i<26; i++){
				if(trie[x][i]) fail[trie[x][i]] = trie[fail[x]][i], q.push(trie[x][i]);
				else trie[x][i] = trie[fail[x]][i];
			}
		}
	}
	int ask(char *str){
		int len = strlen(str); int now = 0;
        long long ans = 0;
		for(int i=0; i<len; i++){
			now = trie[now][str[i] - 'a'];
            int p = 0;
			for(int j=now; j; j = fail[j]) {
                if(end[j]) {
                    ans += (long long) end[j] * (i - lenth[j] + 2ll) % mod * (len - i) % mod;
                    ans %= mod;
                }
            }
		}
		return ans;
	}
}AC;
int main(){
	int N, M;
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++){
		scanf("%s", ptr);
		AC.insert(ptr);
	}
	AC.build();
	for(int i = 1; i <= M; i ++) {
        scanf("%s", ptr);
        printf("%d\n", AC.ask(ptr));
    }
	return 0;
}