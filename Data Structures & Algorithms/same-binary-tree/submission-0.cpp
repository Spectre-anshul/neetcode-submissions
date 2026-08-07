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
    void check(TreeNode *root, vector<int>&curr){
        if(!root){
            curr.push_back(-1);
            return;
        } 
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL) {
                curr.push_back(INT_MIN);   // null marker
                continue;
    }

    curr.push_back(node->val);
    q.push(node->left);
    q.push(node->right);
}
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>pp, qq;
        check(p, pp);
        check(q,qq);
        return pp == qq;
    }
};
