#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
char S[maxn], ptr[maxn];
queue<int> q; int lth[maxn], maxi[maxn], N;
struct Aho_Corasick_Automaton{
	int trie[100005][26], fail[100005], cnt, las[maxn];
    vector<int> end[100005];
	void clear(){
		memset(end, 0, sizeof(end));
		memset(fail, 0, sizeof(fail));
		memset(trie, 0, sizeof(trie));
		memset(maxi, 0, sizeof(maxi));
		cnt = 0;
	}
	void insert(char *str, int num){
		int len = strlen(str); int now = 0;
		for(int i=0; i<len; i++){
			if(!trie[now][str[i] - 'a']) trie[now][str[i] - 'a'] = ++cnt;
			now = trie[now][str[i] - 'a'];
		}
		end[now].push_back(num);
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
	void ask(char *str){
        for(int i = 1; i <= N; i ++) las[i] = -1;
        for(int i = 1; i <= cnt; i ++) las[i] = -1;
		int len = strlen(str);
        int now = 0, p = 0;
		for(int i=0; i<len; i++){
			now = trie[now][str[i] - 'a'];
			for(int j=now; j; j = fail[j]){
                for(auto it : end[j]) {
                    if(it && i - lth[it] + 1 > las[it]) maxi[it] ++, las[it] = i;
                }
			}
		}
		for(int i=1; i<=N; i++) printf("%d\n", maxi[i]);
		return ;
	}
}AC;
int main(){
    int m;
    scanf("%d%d", &m, &N);
    scanf("%s", S);
	for(int i=1; i<=N; i++){
		scanf("%s", ptr);
        lth[i] = strlen(ptr);
		AC.insert(ptr, i);
	}
	AC.build();
	AC.ask(S);
	return 0;
}