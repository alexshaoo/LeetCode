/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void f(vector<int>& v, Node* root) {
        if (!root) return;
        for (const auto& c : root->children) f(v, c);
        v.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        f(ans, root);
        return ans;
    }
};