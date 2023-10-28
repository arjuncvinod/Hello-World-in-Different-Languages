// question link = https://leetcode.com/problems/construct-string-from-binary-tree

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
    vector<string> res;
    
    
    string updateString(string str, string s1, string s2) {
        size_t index = 0;
        while (true) {
         /* Locate the substring to replace. */
         index = str.find(s1, index);
         if (index == std::string::npos) break;

         /* Make the replacement. */
         str.replace(index, s1.length(), s2);

         /* Advance index forward so the next iteration doesn't pick it up as well. */
         index += 1;
        }
        return str;
    }
    
    void preOrder(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        res.push_back(to_string(root->val));
        res.push_back("(");
        preOrder(root->left);
        res.push_back(")");
        res.push_back("(");
        preOrder(root->right);
        res.push_back(")");
    }
    
    
    string tree2str(TreeNode* root) {
        preOrder(root);
        string str;
        string str3 = "";
        string str2 = "()()";
        for(int i=0; i<res.size(); i++) {
            str += res[i];
            // cout<<res[i];
        }
        str = updateString(str, "()()", "");
        str = updateString(str, "())", ")");
        str = updateString(str, ")()", ")");
        // cout<<str<<endl;
        return str;
    }
    
    
};