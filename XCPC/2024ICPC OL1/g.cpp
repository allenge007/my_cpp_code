#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2010;

int a[N], b[N][N], n;

int sum[N][N], cnt[N][N];

bool check(int x) {
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= n + 1; j++) sum[i][j] = cnt[i][j] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 1; j--)
            sum[i][j] = sum[i][j + 1] + (b[j][i] <= x);
    }
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            cnt[i][j] = cnt[i][j - 1] + sum[j][i];
            int num = (j - i + 1) * (j - i + 2) / 2ll;
            if (cnt[i][j] >= (num + 1) / 2ll) tot++;
        }
    }
    int num = n * (n + 1) / 2ll;
    return tot >= (num + 1) / 2ll;
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    
    for (int i = 1; i <= n; i++) {
        priority_queue<int, vector<int>, greater<int>> q2;
        priority_queue<int> q1;
        // vector<int> num; 
        for (int j = i; j <= n; j++) {
            // num.push_back(a[j]);
            // sort(num.begin(), num.end());
            if (q1.size() && a[j] < q1.top()) {
                q1.push(a[j]);
                int k = (j - i + 2) / 2 - 1;
                while (q1.size() > k) {
                    q2.push(q1.top());
                    q1.pop();
                }
            } else {
                q2.push(a[j]);
                int k = (j - i + 2) / 2 - 1;
                while (q2.size() && q1.size() < k) {
                    q1.push(q2.top());
                    q2.pop();
                }
            }
            b[i][j] = q2.top();
            // if (b[i][j] != num[(num.size() + 1) / 2 - 1]) {
            //     cout << i << ' ' << j << ' ' << b[i][j] << ' ' << num[(num.size() + 1) / 2 - 1] << endl;
            // }
            // cout << b[i][j] << ' ';
        }
        // cout << endl;
    }

    sort(a + 1, a + 1 + n);
    int tot = unique(a + 1, a + 1 + n) - a - 1;

    int l = 1, r = tot, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(a[mid])) ans = mid, r = mid - 1;
        else l = mid + 1;
    }

    cout << a[ans] << endl;

    return 0;
}