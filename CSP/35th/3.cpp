#include <bits/stdc++.h>

using namespace std;
const int maxn = 2005;
string oldfile[maxn];
string pat[10005];
int cnt = 0, n = 0;
struct patch{
	string old[maxn], New[maxn];
	int old_cnt, New_cnt;
	int NN, MM, nn, mm, lin = 0;
	patch(int NN = 0, int MM = 0, int nn = 0, int mm = 0, int lin = 0) : NN(NN), MM(MM), nn(nn), mm(mm) {
		old_cnt = New_cnt = 0;
	};
	int read(int &p, string str, int lth, int& opt) {
		int w = 0;
		while(p < lth && str[p] < '0' || str[p] > '9') {
			if(str[p] == '-') opt = -1;
			else if(str[p] == '+') opt = 1;
			else if(str[p] == ',') opt = 0;
			p ++;
		}
		while(p < lth && str[p] >= '0' && str[p] <= '9') w = w * 10 + str[p] - '0', p ++;
		return w;
	}
	bool upd(string str) {
		int lth = str.size(), p = 0, op = 2;
		NN = read(p, str, lth, op);
		if(op != -1) return 0;
		MM = read(p, str, lth, op);
		if(op != 0) return 0;
		nn = read(p, str, lth, op);
		if(op != 1) return 0;
		mm = read(p, str, lth, op);
		if(op != 0) return 0;
//		cout << NN << " " << MM << " " << nn << " " << mm << endl;
		return 1;
	}
	bool insert_old(string str) {
		int lth = str.size();
		old_cnt ++;
		for(int i = 1; i < lth; i ++) {
			old[old_cnt].push_back(str[i]);
		}
		return 1;
	}
	bool insert_new(string str) {
		int lth = str.size();
		New_cnt ++;
		for(int i = 1; i < lth; i ++) {
			New[New_cnt].push_back(str[i]);
		}
		return 1;
	}
	bool insert(string str) {
		if(str[0] != ' ' && str[0] != '-' && str[0] != '+') return 0;
		if(str[0] == ' ') {
			insert_old(str), insert_new(str);
		}
		else if(str[0] == '-') insert_old(str);
		else insert_new(str);
//		cout << old_cnt << " " << New_cnt << endl;
		return 1;
	}
	bool check_siz() {
		if(old_cnt != MM || New_cnt != mm) return 0;
		return 1;
	}
	bool operator<(const patch& y) const {
		return NN < y.NN;
	}
	bool cmp(int &l) {
		int tot = 0;
		for(int i = l; i <= n; i ++) {
			bool flag = 1;
//			cout << i << endl;
			for(int j = 1; j <= old_cnt; j ++) {
				if(old[j] != oldfile[i + j - 1]) {
					flag = 0;
					break;
				}
			}
			if(flag) return l = i + MM, 1;
		}
		return 0;
	}
}block[maxn];
pair<int, int> rep[maxn];
#define fir first
#define sec second
int main() {
// 	freopen("test.in", "r", stdin);
	cin >> n;
	string Nul;
	getline(cin, Nul);
	for(int i = 1; i <= n; i ++)
		getline(cin, oldfile[i]);
	int tot = 0;
	while(getline(cin, pat[tot])) tot ++;
//	for(int i = 0; i < tot; i ++) cout << pat[i] << endl;
	for(int i = 0; i < tot; i ++) {
		if(pat[i][0] == '#' || pat[i][0] == '\n' || pat[i].size() == 0) continue;
		if(pat[i][0] != '@' && cnt == 0) continue;
		if(pat[i][0] == '@') {
			if(!block[++ cnt].upd(pat[i])) return cout << "Patch is damaged.\n", 0;
		} else {
			if(!block[cnt].insert(pat[i])) return cout << "Patch is damaged.\n", 0;
		}
	}
	if(!cnt) return printf("Patch is damaged.\n"), 0;
	for(int i = 1; i <= cnt; i ++) if(!block[i].check_siz()) return cout << ("Patch is damaged.\n"), 0;
	int sig = 1;
	sort(block + 1, block + cnt + 1);
	for(int i = 1; i <= cnt; i ++) {
		if(!block[i].cmp(sig)) return cout << ("Patch is damaged.\n"), 0;
		rep[i] = make_pair(sig - block[i].MM, sig);
	}
	int tai = 1;
	 for(int i = 1; i <= n;) {
//		 cout << i << "fuck\n";
//		cout << tai << " " << block[tai].New_cnt << endl;
		 if(tai <= cnt && i == rep[tai].fir) {
//		 	cout << tai << " " << block[tai].New_cnt << endl;
		 	for(int j = 1; j <= block[tai].New_cnt; j ++) {
		 		cout << block[tai].New[j] << endl;
		 	}
		 	i = rep[tai ++].sec;
		 }
		 else {
		 	cout << oldfile[i ++] << endl;
		 }
	 }
	return 0;
}