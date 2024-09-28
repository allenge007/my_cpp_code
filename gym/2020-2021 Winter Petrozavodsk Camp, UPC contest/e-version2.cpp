#include <bits/stdc++.h>

using namespace std;
#pragma GCC optimize(3)

inline int read() {
    int w = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w * f;
}
const int maxn = 5e4 + 5, maxm = 2e5 + 5, BLOCK_SIZE = 305;
const long long mod = 1e9 + 7;
int n, q, a[maxn], root, lim, cnt;
long long ans[maxm];
struct node {
    int l, r, id;
}qury[maxm];
struct Node {
    Node* ch[2];
    int val, prio;
    int cnt;
    int siz;
    long long odd_sum, even_sum;
    Node(int _val): val(_val), cnt(1), siz(1), odd_sum(_val), even_sum(0) {
        ch[0] = ch[1] = nullptr;
        prio = rand();
    }

    Node(Node* _node) {
        val = _node->val, prio = _node->prio, cnt = _node->cnt, siz = _node->siz;
    }

    void upd_siz() {
        siz = cnt;
        if (ch[0] != nullptr) siz += ch[0]->siz;
        if (ch[1] != nullptr) siz += ch[1]->siz;
        if (ch[0] == nullptr) odd_sum = val, even_sum = 0;
        if (ch[0] != nullptr) {
            if(ch[0] -> siz & 1) {
                odd_sum = ch[0] -> odd_sum;
                even_sum = ch[0] -> even_sum + val;
            } else {
                odd_sum = ch[0] -> odd_sum + val;
                even_sum = ch[0] -> even_sum;
            }
        }
        if (ch[1] != nullptr) {
            if(ch[0] != nullptr && ch[0] -> siz & 1) {
                odd_sum += ch[1] -> odd_sum;
                even_sum += ch[1] -> even_sum;
            } else {
                odd_sum += ch[1] -> even_sum;
                even_sum += ch[1] -> odd_sum;
            }
        }
    }
};

struct none_rot_treap {
#define _3 second.second
#define _2 second.first
    Node* root;

    pair<Node*, Node*> split(Node* cur, int key) {
        if (cur == nullptr) return { nullptr, nullptr };
        if (cur->val <= key) {
            auto temp = split(cur->ch[1], key);
            cur->ch[1] = temp.first;
            cur->upd_siz();
            return { cur, temp.second };
        }
        else {
            auto temp = split(cur->ch[0], key);
            cur->ch[0] = temp.second;
            cur->upd_siz();
            return { temp.first, cur };
        }
    }

    tuple<Node*, Node*, Node*> split_by_rk(Node* cur, int rk) {
        if (cur == nullptr) return { nullptr, nullptr, nullptr };
        int ls_siz = cur->ch[0] == nullptr ? 0 : cur->ch[0]->siz;
        if (rk <= ls_siz) {
            Node* l, * mid, * r;
            tie(l, mid, r) = split_by_rk(cur->ch[0], rk);
            cur->ch[0] = r;
            cur->upd_siz();
            return { l, mid, cur };
        }
        else if (rk <= ls_siz + cur->cnt) {
            Node* lt = cur->ch[0];
            Node* rt = cur->ch[1];
            cur->ch[0] = cur->ch[1] = nullptr;
            return { lt, cur, rt };
        }
        else {
            Node* l, * mid, * r;
            tie(l, mid, r) = split_by_rk(cur->ch[1], rk - ls_siz - cur->cnt);
            cur->ch[1] = l;
            cur->upd_siz();
            return { cur, mid, r };
        }
    }

    Node* merge(Node* u, Node* v) {
        if (u == nullptr && v == nullptr) return nullptr;
        if (u != nullptr && v == nullptr) return u;
        if (v != nullptr && u == nullptr) return v;
        if (u->prio < v->prio) {
            u->ch[1] = merge(u->ch[1], v);
            u->upd_siz();
            return u;
        }
        else {
            v->ch[0] = merge(u, v->ch[0]);
            v->upd_siz();
            return v;
        }
    }

    void insert(int val) {
        auto temp = split(root, val);
        auto l_tr = split(temp.first, val - 1);
        Node* new_node;
        if (l_tr.second == nullptr) {
            new_node = new Node(val);
        }
        else {
            l_tr.second->cnt++;
            l_tr.second->upd_siz();
        }
        Node* l_tr_combined =
            merge(l_tr.first, l_tr.second == nullptr ? new_node : l_tr.second);
        root = merge(l_tr_combined, temp.second);
    }

    void del(int val) {
        auto temp = split(root, val);
        auto l_tr = split(temp.first, val - 1);
        if (l_tr.second->cnt > 1) {
            l_tr.second->cnt--;
            l_tr.second->upd_siz();
            l_tr.first = merge(l_tr.first, l_tr.second);
        }
        else {
            if (temp.first == l_tr.second) {
                temp.first = nullptr;
            }
            delete l_tr.second;
            l_tr.second = nullptr;
        }
        root = merge(l_tr.first, temp.second);
    }

    inline long long OddSum() {
        return root == nullptr ? 0 : root->odd_sum;
    }

    inline long long EvenSum() {
        return root == nullptr ? 0 : root->even_sum;
    }
};

none_rot_treap tr;
inline void move(int p, int op) {
    if (op == 1) {
        tr.insert(a[p]);
    }
    else {
        tr.del(a[p]);
    }
}
int main() {
    n = read(), q = read(); 
    for (int i = 0; i < n; i++) a[i] = read(), lim = max(lim, a[i]);
    for (int i = 1; i <= q; i++) {
        int l = read(), r = read();
        qury[i] = { l, r, i };
    }
    sort(qury + 1, qury + q + 1, [](node x, node y) {
        return x.l / BLOCK_SIZE ^ y.l / BLOCK_SIZE ? x.l / BLOCK_SIZE < y.l / BLOCK_SIZE : x.l / BLOCK_SIZE & 1 ? x.r < y.r : x.r > y.r;
        });
    int l = 0, r = -1;
    for (int i = 1; i <= q; i++) {
        const node& qu = qury[i];
        while (l > qu.l) move(--l, 1);
        while (r < qu.r) move(++r, 1);
        while (l < qu.l) move(l++, -1);
        while (r > qu.r) move(r--, -1);
        ans[qury[i].id] = tr.OddSum();
    }
    for (int i = 1; i <= q; i++) printf("%lld\n", ans[i] % mod);
    return 0;
}