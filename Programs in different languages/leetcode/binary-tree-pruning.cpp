// question link - https://leetcode.com/problems/binary-tree-pruning/submissions/

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
        
    bool traverse(TreeNode* root) {
        if (root == NULL) {
            return false;
        }
        
        traverse(root->left);
        if(root->left !=NULL && root->left->val == 0 && root->left->right == NULL && root->left->left == NULL) {
            root->left = NULL;
        }
        traverse(root->right);
        if(root->right !=NULL && root->right->val == 0 && root->right->right == NULL && root->right->left == NULL) {
            root->right = NULL;
        }
         
        return true;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        bool flag = false;
        traverse(root);
        if(root->left == NULL && root->right == NULL && root->val == 0){
            return NULL;
        }
        return root;
    }
};