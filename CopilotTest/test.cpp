#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    vector<int> data;
    int n;

    void buildTree(int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;
            buildTree(leftChild, start, mid);
            buildTree(rightChild, mid + 1, end);
            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

    void updateTree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            data[idx] = val;
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;
            if (idx >= start && idx <= mid) {
                updateTree(leftChild, start, mid, idx, val);
            } else {
                updateTree(rightChild, mid + 1, end, idx, val);
            }
            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

    int queryTree(int node, int start, int end, int L, int R) {
        if (R < start || L > end) {
            return 0;
        }
        if (L <= start && end <= R) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;
        int leftSum = queryTree(leftChild, start, mid, L, R);
        int rightSum = queryTree(rightChild, mid + 1, end, L, R);
        return leftSum + rightSum;
    }

public:
    SegmentTree(const vector<int>& input) {
        data = input;
        n = data.size();
        tree.resize(4 * n);
        buildTree(0, 0, n - 1);
    }

    void update(int idx, int val) {
        updateTree(0, 0, n - 1, idx, val);
    }

    int query(int L, int R) {
        return queryTree(0, 0, n - 1, L, R);
    }
};

int main() {
    vector<int> data = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(data);

    cout << "Sum of values in given range = " << segTree.query(1, 3) << endl;

    segTree.update(1, 10);

    cout << "Updated sum of values in given range = " << segTree.query(1, 3) << endl;

    return 0;
}