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

// class Solution {
// public:
//     int maxheight(TreeNode *root){
//         if(!root) return 0;
//         return 1+max(maxheight(root->right), maxheight(root->left));
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(!root) return 0;
//         int left = maxheight(root->left);
//         int right = maxheight(root->right);
//         int diameter = left + right;
//         int sub = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
//         return max(sub, diameter);
//     }
// };

class Solution{
    public:
    int res = 0;
    int maxHeight(TreeNode *root){
        if(!root) return 0;
        int left = maxHeight(root->left);
        int right = maxHeight(root->right);
        res = max(res, left + right);
        return 1+ max(left, right);
    }
    int diameterOfBinaryTree(TreeNode *root){
        if(!root) return 0;
        maxHeight(root);
        return res;
    }
};