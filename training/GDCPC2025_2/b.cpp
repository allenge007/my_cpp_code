#include <bits/stdc++.h>
using namespace std;

const int maxn = 1501;
bitset<maxn> A[maxn];
bitset<maxn> p[maxn];
bitset<maxn> comb[maxn];
bool found = false;
bitset<maxn> res;

void insert(bitset<maxn> x, bitset<maxn> c) {
    for (int i = maxn - 1; i >= 0; --i) {
        if (!x.test(i)) continue;
        if (!p[i].any()) { 
            p[i] = x;
            comb[i] = c;
            return;
        } else {
            x ^= p[i];
            c ^= comb[i];
        }
    }
    if (x.none() && c.any()) {
        found = true;
        res = c;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        A[i] = bitset<maxn>(s + "1");
        
        bitset<maxn> cur;
        cur.reset();
        cur.set(i);
        
        insert(A[i], cur);
    }
    
    if(found) {
        int cnt = res.count() / 2;
        for(int i = 1; i <= N; ++i) {
            if (res.test(i)) {
                if(cnt) cout << "1", cnt --;
                else cout << "2";
            } else {
                cout << "0";
            }
        }
        cout << "\n";
    } else {
        cout << "*\n";
    }
    
    return 0;
}