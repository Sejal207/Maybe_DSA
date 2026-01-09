#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }

private:

    pair<int, TreeNode*> dfs(TreeNode* node) {
        if (!node) return {0, nullptr};

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        if (left.first == right.first) {
            return {left.first + 1, node};
        }
        if (left.first > right.first) {
            return {left.first + 1, left.second};
        }
        return {right.first + 1, right.second};
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* result = sol.subtreeWithAllDeepest(root);
    cout << "Root of the smallest subtree with all deepest nodes: "
         << result->val << endl;

    return 0;
}
