#include <bits/stdc++.h>

using namespace std;
void SA() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> suffix_array(n), rank(n), temp(n), cnt(max(256, n));

    // Initial ranking based on the first character
    for (int i = 0; i < n; ++i) {
        suffix_array[i] = i;
        rank[i] = s[i];
    }

    for (int k = 1; k < n; k *= 2) {
        // Counting sort based on the second half
        fill(cnt.begin(), cnt.end(), 0);
        for (int i = 0; i < n; ++i) {
            cnt[(i + k < n) ? rank[i + k] + 1 : 0]++;
        }
        for (int i = 1; i < cnt.size(); ++i) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = n - 1; i >= 0; --i) {
            temp[--cnt[(suffix_array[i] + k < n) ? rank[suffix_array[i] + k] + 1 : 0]] = suffix_array[i];
        }
        suffix_array = temp;

        // Counting sort based on the first half
        fill(cnt.begin(), cnt.end(), 0);
        for (int i = 0; i < n; ++i) {
            cnt[rank[suffix_array[i]]]++;
        }
        for (int i = 1; i < cnt.size(); ++i) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = n - 1; i >= 0; --i) {
            temp[--cnt[rank[suffix_array[i]]]] = suffix_array[i];
        }
        suffix_array = temp;

        // Update ranks
        temp[suffix_array[0]] = 0;
        for (int i = 1; i < n; ++i) {
            temp[suffix_array[i]] = temp[suffix_array[i - 1]] + 
                (rank[suffix_array[i]] != rank[suffix_array[i - 1]] || 
                rank[suffix_array[i] + k] != rank[suffix_array[i - 1] + k]);
        }
        rank = temp;
    }

    for (int i = 0; i < n; ++i) {
        cout << suffix_array[i] << " ";
    }
    cout << endl;
}
const int maxn = 1e5 + 5;
char str[maxn];
void solve() {
    int k;
    scanf("%d", &k);
    scanf("%s", str);
    SA();
    for(int i = 1; i <= n; n ++)
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}