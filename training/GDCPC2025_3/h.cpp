#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e3 + 5;
void read(int n, int m, vector<bitset<1000>> &A) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j ++) {
            int x;
            cin >> x;
            A[i].set(j, x);
        }
    }
}
void test(int n, int m, vector<bitset<1000>> &A) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j ++) {
            cout << A[i].test(j) << " ";
        }
        cout << endl;
    }
}
void Gauss(int n, int m, int p, vector<bitset<1000>> &A, vector<bitset<1000>> &C) {
    int row = 0;
    for(int col = 0; col < m && row < n; ++col) {
        for(int i = row; i < n; ++i) {
            if (A[i].test(col)) {
                swap(A[row], A[i]);
                swap(C[row], C[i]);
                break;
            }
        }
        if(!A[row].test(col)) continue;
        for(int i = 0; i < n; ++i) {
            if (i == row) continue;
            if (A[i].test(col)) {
                A[i] ^= A[row];
                C[i] ^= C[row];
            }
        }
        ++row;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, p;
    cin >> n >> m >> p;
    vector<bitset<1000>> A(n), B(m), C(n);
    read(n, m, A);
    read(n, p, C);
    Gauss(n, m, p, A, C);
    for(int i = 0; i < n; i++) {
        if(A[i].none()) {
            if(C[i].any()) return cout << "No" << endl, 0;
            continue;
        }
        for(int j = 0; j < m; j++) {
            if(A[i].test(j)) {
                B[j] = C[i];
                break;
            }
        }
    }
    cout << "Yes" << endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < p; j ++) {
            if(B[i].test(j)) cout << "1 ";
            else cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}