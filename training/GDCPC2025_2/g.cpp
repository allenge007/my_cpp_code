#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long minVal, maxVal, lazy;
    Node *left, *right;
    Node() : minVal(0), maxVal(0), lazy(0), left(nullptr), right(nullptr) {}
};

void pushDown(Node* node) {
    if (!node || node->lazy == 0) return;
    if (!node->left) node->left = new Node();
    if (!node->right) node->right = new Node();
    node->left->minVal += node->lazy;
    node->left->maxVal += node->lazy;
    node->left->lazy   += node->lazy;
    node->right->minVal += node->lazy;
    node->right->maxVal += node->lazy;
    node->right->lazy   += node->lazy;
    node->lazy = 0;
}

void update(Node* &node, long long ql, long long qr, long long l, long long r, long long k) {
    if (ql <= l && r <= qr) {
        if (!node) node = new Node();
        node->minVal += k;
        node->maxVal += k;
        node->lazy   += k;
        return;
    }
    if (!node) node = new Node();
    pushDown(node);
    auto mid = (l + r) / 2;
    if (ql <= mid)
        update(node->left, ql, qr, l, mid, k);
    if (qr > mid)
        update(node->right, ql, qr, mid+1, r, k);
    long long leftMin  = node->left ? node->left->minVal : 0;
    long long rightMin = node->right ? node->right->minVal : 0;
    long long leftMax  = node->left ? node->left->maxVal : 0;
    long long rightMax = node->right ? node->right->maxVal : 0;
    node->minVal = min(leftMin, rightMin);
    node->maxVal = max(leftMax, rightMax);
}

pair<long long,long long> query(Node* node, long long ql, long long qr, long long l, long long r) {
    if (ql <= l && r <= qr) {
        if (node)
            return {node->minVal, node->maxVal};
        else
            return {0, 0};
    }
    if (!node) return {0, 0};
    pushDown(node);
    auto mid = (l + r) / 2;
    auto resMin = LLONG_MAX, resMax = LLONG_MIN;
    if (ql <= mid) {
        auto leftRes = query(node ? node->left : nullptr, ql, qr, l, mid);
        resMin = min(resMin, leftRes.first);
        resMax = max(resMax, leftRes.second);
    }
    if (qr > mid) {
        auto rightRes = query(node ? node->right : nullptr, ql, qr, mid+1, r);
        resMin = min(resMin, rightRes.first);
        resMax = max(resMax, rightRes.second);
    }
    return {resMin, resMax};
}

bool isEqualRange(Node* root, long long ql, long long qr, long long l, long long r) {
    auto res = query(root, ql, qr, l, r);
    return res.first == res.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    long long l = 1, r = 2e18;
    Node* root = nullptr;
    for(int i = 1; i <= N; i++) {
        string opt;
        long long L, P;
        cin >> opt >> L >> P;
        if(opt[0] == '-') {
            if(isEqualRange(root, P, P + L - 1, l, r)) {
                cout << "S";
                update(root, P, P + L - 1, l, r, 1);
            } else {
                cout << "U";
            }
        } else {
            update(root, P, P, l, r, L);
            cout << "S";
        }
    }
    return 0;
}