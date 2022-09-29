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
    
    int maxHeight(TreeNode* root) {
        if (root->left && root->right) {
            return 1+max(maxHeight(root->left), maxHeight(root->right));
        } else if (root->left || root->right) {
            return 1+(root->left ? maxHeight(root->left) : maxHeight(root->right));
        }
        return 0;
    }
    
    int deepestLeaves(TreeNode* root, int depth, int maxDepth) {
        
        if (depth == maxDepth) {
            return root->val;
        } else {
            
            if (root->left && root->right) {
                return deepestLeaves(root->left, depth+1, maxDepth)+deepestLeaves(root->right, depth+1, maxDepth);
            }
            
            if (root->left) {
                return deepestLeaves(root->left, depth+1, maxDepth);
            } else if (root->right) {
                return deepestLeaves(root->right, depth+1, maxDepth);
            } else {
                return 0;
            }
        }    
    }
    
    int deepestLeavesSum(TreeNode* root) {
        return deepestLeaves(root, 0, maxHeight(root));
    }
};