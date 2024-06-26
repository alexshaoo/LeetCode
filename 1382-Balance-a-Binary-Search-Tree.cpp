/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> nodes;
    void traverse(TreeNode* root) {
        if (!root) return;
        traverse(root->left);
        nodes.push_back(root);
        traverse(root->right);
    }
    TreeNode* build(int l, int r) {
        if (l > r) return nullptr;
        int m = (l+r)/2;
        TreeNode* root = nodes[m];
        root->left = build(l, m-1);
        root->right = build(m+1, r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        traverse(root);
        return build(0, nodes.size()-1);
    }
};