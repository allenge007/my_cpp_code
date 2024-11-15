#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> nodes;

TreeNode* convertToBinaryTree(const vector<vector<int>>& children, int root) {
    if (children[root].empty()) {
        return nodes[root];
    }
    nodes[root]->left = nodes[children[root][0]];
    TreeNode* current = nodes[root]->left;
    for (size_t i = 1; i < children[root].size(); ++i) {
        current->right = nodes[children[root][i]];
        current = current->right;
    }
    for (int child : children[root]) {
        convertToBinaryTree(children, child);
    }
    return nodes[root];
}

void levelOrderTraversal(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    nodes.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        nodes[i] = new TreeNode(i);
    }
    vector<vector<int>> children(n + 1);
    for (int i = 2; i <= n; ++i) {
        int parent;
        cin >> parent;
        children[parent].push_back(i);
    }

    TreeNode* root = convertToBinaryTree(children, 1);
    levelOrderTraversal(root);

    return 0;
}