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



// Traverse the tree
// During travering store the node at level in a map
// iterate map and calculate average at each level and store it in new vector (result)
class Solution {
public:
    int level = 1;
    map <long int, vector<long int>> umap;
    void bfs(TreeNode* root) {

        if(root == NULL) {
            return;
        } 
        umap[level].push_back(root->val);
        level++;
        
        bfs(root->left);
        bfs(root->right);
        level--;
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        bfs(root);
        
        for(auto it: umap) {
            // cout<<it.first<<" : ";
            double avg;
            long int sum = 0;
            long int counter =0;
            for(int i=0; i<it.second.size(); i++) {
                // cout<<it.second[i]<<" ";
                sum += it.second[i];
                counter++;
            }
            // cout<<endl;
            avg = sum/(double)counter;
            res.push_back(avg);
        }
        return res;
    }
};